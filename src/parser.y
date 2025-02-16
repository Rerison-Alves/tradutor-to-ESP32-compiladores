%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *output_file;
int canalPWM = 0;
int currentLine = 1;

void yyerror(const char *s);
int yylex(void);

char* concatenarExpressao(const char* op, char* e1, char* e2);
char* processarHttp(const char* url, const char* dados);

// Definição da Tabela de Símbolos
typedef enum { TYPE_INT, TYPE_BOOL, TYPE_STRING } VarType;
typedef enum { UNDEFINED, INPUT, OUTPUT, PWM } PinMode;
typedef struct Symbol {
    char* name;
    VarType type;
    PinMode mode;
    struct Symbol* next;
} Symbol;

Symbol* symbolTable = NULL;

// Função para criar um símbolo
Symbol* createSymbol(const char* name, VarType type) {
    Symbol* newSymbol = (Symbol*) malloc(sizeof(Symbol));
    newSymbol->name = strdup(name);
    newSymbol->type = type;
    newSymbol->mode = UNDEFINED;
    newSymbol->next = NULL;
    return newSymbol;
}

// Função para buscar um símbolo na tabela
Symbol* findSymbol(const char* name) {
    Symbol* current = symbolTable;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

VarType getSymbolType(const char* name) {
    Symbol* symbol = findSymbol(name);
    if (symbol == NULL) {
        fprintf(stderr, "Erro semântico: Variável '%s' não foi declarada.\n", name);
        exit(1);
    }
    return symbol->type;
}

// Função para inserir um símbolo na tabela
void insertSymbol(const char* name, VarType type) {
    if (findSymbol(name) != NULL) {
        fprintf(stderr, "Erro semantico: Variavel '%s' ja declarada.\n", name);
        exit(1);
    }
    Symbol* newSymbol = createSymbol(name, type);
    newSymbol->next = symbolTable;
    symbolTable = newSymbol;
}

VarType inferType(const char* expr) {
    // Se a expressão começa com aspas, é texto.
    if (expr[0] == '\"') {
        return TYPE_STRING;
    }
    // Verifica se todos os caracteres são dígitos (considera apenas inteiros simples).
    int i = 0;
    while (expr[i] != '\0') {
        if (!isdigit(expr[i])) {
            break;
        }
        i++;
    }
    if (expr[i] == '\0') {
        return TYPE_INT;
    }
    // Caso não seja nem literal de texto nem numérico puro, podemos assumir inteiro por padrão,
    // ou implementar outras verificações conforme necessário.
    return TYPE_INT;
}

%}

%union {
    int ival;
    char *sval;
}

%token VAR INTEIRO BOOLEANO TEXTO_TYPE CONFIG FIM REPITA
%token COMO SAIDA ENTRADA CONFIGURAR LIGAR DESLIGAR
%token LER_DIGITAL LER_ANALOGICO CONFIG_PWM AJUSTAR_PWM
%token COM FREQUENCIA RESOLUCAO CONECTAR_WIFI ENVIAR_HTTP
%token CONFIG_SERIAL ESCREVER_SERIAL LER_SERIAL ESPERAR
%token SE SENAO ENTAO ENQUANTO VALOR
%token RECEBE IGUAL DIFERENTE MENOR MAIOR MENOR_IGUAL MAIOR_IGUAL
%token MAIS MENOS MULT DIV
%token <ival> INTEIRO_LIT BOOL_LIT
%token <sval> TEXTO_LIT IDENT

%type <sval> programa declaracoes declaracao_var tipo lista_ids
%type <sval> config blocos_config bloco_config repita blocos_repita
%type <sval> bloco_repita atribuicao controle_gpio config_pin config_pwm
%type <sval> ajustar_pwm conectar_wifi config_serial escrever_serial
%type <sval> enviar_http condicional cond_else enquanto_loop expressao
%type <sval> leitura comandos esperar

%left MAIS MENOS
%left MULT DIV
%nonassoc IGUAL DIFERENTE MENOR MAIOR MENOR_IGUAL MAIOR_IGUAL

%%

programa:
    declaracoes config repita
    {
        fprintf(output_file, "}\n\nvoid loop() {\n%s}\n", $3);
        free($3);
        fclose(output_file);
    }
    ;

declaracoes:
    /* empty */ { $$ = strdup(""); }
    | declaracoes declaracao_var { free($1); free($2); $$ = strdup(""); }
    ;

declaracao_var:
    VAR tipo ':' lista_ids ';'
    {
        // Determinar o tipo da variável
        VarType var_type;
        if (strcmp($2, "int") == 0) {
            var_type = TYPE_INT;
            fprintf(output_file, "int %s;\n", $4);
        } else if (strcmp($2, "bool") == 0) {
            var_type = TYPE_BOOL;
            fprintf(output_file, "bool %s = false;\n", $4);
        } else {
            var_type = TYPE_STRING;
            fprintf(output_file, "String %s;\n", $4);
        }

        // Adicionar cada variável na tabela de símbolos e verificar duplicatas
        char* token = strtok($4, ", ");
        while (token != NULL) {
            if (findSymbol(token) != NULL) {
                fprintf(stderr, "Erro semantico: Variavel '%s' ja foi declarada no mesmo escopo.\n", token);
                exit(1);
            }
            insertSymbol(token, var_type);
            token = strtok(NULL, ", ");
        }

        free($2);
        free($4);
        $$ = strdup("");
    }
    ;


tipo:
    INTEIRO     { $$ = strdup("int"); }
    | BOOLEANO   { $$ = strdup("bool"); }
    | TEXTO_TYPE { $$ = strdup("String"); }
    ;

lista_ids:
    IDENT { $$ = strdup($1);  }
    | lista_ids ',' IDENT
    {
        $$ = malloc(strlen($1) + strlen($3) + 3);
        sprintf($$, "%s, %s", $1, $3);
        free($1);
        free($3);
    }
    ;

config:
    CONFIG blocos_config FIM
    {
        fprintf(output_file, "\nvoid setup() {\n%s", $2);
        free($2);
        $$ = strdup("");
    }
    ;

blocos_config:
    /* empty */ { $$ = strdup(""); }
    | blocos_config bloco_config
    {
        $$ = malloc(strlen($1) + strlen($2) + 1);
        sprintf($$, "%s%s", $1, $2);
        free($1);
        free($2);
    }
    ;

bloco_config:
    atribuicao
    | config_pin
    | config_pwm
    | conectar_wifi
    | config_serial
    ;

repita:
    REPITA blocos_repita FIM { $$ = $2; }
    ;

blocos_repita:
    /* empty */ { $$ = strdup(""); }
    | blocos_repita bloco_repita
    {
        $$ = malloc(strlen($1) + strlen($2) + 1);
        sprintf($$, "%s%s", $1, $2);
        free($1);
        free($2);
    }
    ;

bloco_repita:
    atribuicao
    | controle_gpio
    | ajustar_pwm
    | esperar
    | condicional
    | enquanto_loop
    | enviar_http
    | escrever_serial
    ;

atribuicao:
    IDENT RECEBE expressao ';'
    {
        Symbol* sym = findSymbol($1);
        if (findSymbol($1) == NULL) {
            fprintf(stderr, "Erro semantico: Variavel '%s' nao foi declarada.\n", $1);
            exit(1);
        }
        VarType exprType = inferType($3);
                if (sym->type != exprType) {
                    fprintf(stderr, "Erro semantico: Valor atribuido a '%s' e do tipo incorreto. Esperado: %s, obtido: %s.\n",
                        $1,
                        (sym->type == TYPE_INT ? "inteiro" : (sym->type == TYPE_BOOL ? "booleano" : "texto")),
                        (exprType == TYPE_INT ? "inteiro" : (exprType == TYPE_BOOL ? "booleano" : "texto")));
                    exit(1);
                }
        $$ = malloc(strlen($1) + strlen($3) + 20);
        sprintf($$, "%s = %s;\n", $1, $3);
        free($1);
        free($3);
    }
    ;


controle_gpio:
    LIGAR IDENT ';'
    {
        Symbol* sym = findSymbol($2);
                if (sym == NULL || (sym->mode != OUTPUT && sym->mode != PWM)) {
                    fprintf(stderr, "Erro semântico: O pino '%s' precisa ser configurado como saída ou PWM para ser ligado.\n", $2);
                    exit(1);
                }
        $$ = malloc(50);
        sprintf($$, "digitalWrite(%s, HIGH);\n", $2);
        free($2);
    }
    | DESLIGAR IDENT ';'
    {
        Symbol* sym = findSymbol($2);
                if (sym == NULL || (sym->mode != OUTPUT && sym->mode != PWM)) {
                    fprintf(stderr, "Erro semântico: O pino '%s' precisa ser configurado como saída ou PWM para ser desligado.\n", $2);
                    exit(1);
                }
        $$ = malloc(50);
        sprintf($$, "digitalWrite(%s, LOW);\n", $2);
        free($2);
    }
    ;

config_pin:
    CONFIGURAR IDENT COMO SAIDA ';'
    {
        Symbol* sym = findSymbol($2);
                if (sym == NULL) {
                    fprintf(stderr, "Erro semântico: Pino '%s' não declarado.\n", $2);
                    exit(1);
                }
                sym->mode = OUTPUT;
        $$ = malloc(100);
        sprintf($$, "pinMode(%s, OUTPUT);\n", $2);
        free($2);
    }
    | CONFIGURAR IDENT COMO ENTRADA ';'
    {
        Symbol* sym = findSymbol($2);
                if (sym == NULL) {
                    fprintf(stderr, "Erro semântico: Pino '%s' não declarado.\n", $2);
                    exit(1);
                }
                sym->mode = INPUT;
        $$ = malloc(100);
        sprintf($$, "pinMode(%s, INPUT);\n", $2);
        free($2);
    }
    ;

config_pwm:
    CONFIG_PWM IDENT COM FREQUENCIA INTEIRO_LIT RESOLUCAO INTEIRO_LIT ';'
    {
        Symbol* sym = findSymbol($2);
                if (sym == NULL) {
                    fprintf(stderr, "Erro semântico: Pino '%s' não declarado para PWM.\n", $2);
                    exit(1);
                }
                sym->mode = PWM;
        $$ = malloc(200);
        sprintf($$, "ledcSetup(%d, %d, %d);\nledcAttachPin(%s, %d);\n",
               canalPWM, $5, $7, $2, canalPWM);
        canalPWM++;
        free($2);
    }
    ;

ajustar_pwm:
    AJUSTAR_PWM IDENT COM VALOR expressao ';'
    {
    Symbol* sym = findSymbol($2);
            if (sym == NULL || sym->mode != PWM) {
                fprintf(stderr, "Erro semântico: O pino '%s' precisa ser configurado como PWM para ajustar o valor.\n", $2);
                exit(1);
            }
        $$ = malloc(100);
        sprintf($$, "ledcWrite(%d, %s);\n", canalPWM-1, $5);
        free($2);
        free($5);
    }
    ;

conectar_wifi:
    CONECTAR_WIFI IDENT IDENT ';'
    {
        $$ = malloc(500);
        sprintf($$,
            "WiFi.begin(%s.c_str(), %s.c_str());\n"
            "while(WiFi.status() != WL_CONNECTED) {\n"
            "  delay(500);\n"
            "  Serial.println(\"Conectando ao WiFi...\");\n"
            "}\n"
            "Serial.println(\"Conectado ao WiFi!\");\n",
            $2, $3);
        free($2);
        free($3);
    }
    ;

config_serial:
    CONFIG_SERIAL INTEIRO_LIT ';'
    {
        $$ = malloc(50);
        sprintf($$, "Serial.begin(%d);\n", $2);
    }
    ;

escrever_serial:
    ESCREVER_SERIAL expressao ';'
    {
        $$ = malloc(strlen($2) + 30);
        sprintf($$, "Serial.println(%s);\n", $2);
        free($2);
    }
    ;

enviar_http:
    ENVIAR_HTTP TEXTO_LIT TEXTO_LIT ';'
    {
        $$ = processarHttp($2, $3);
        free($2);
        free($3);
    }
    ;

condicional:
    SE expressao ENTAO '\n' comandos cond_else FIM
    {
        $$ = malloc(strlen($2) + strlen($5) + strlen($6) + 50);
        sprintf($$, "if (%s) {\n%s%s}\n", $2, $5, $6);
        free($2); free($5); free($6);
    }
    ;

cond_else:
    /* empty */ { $$ = strdup(""); }
    | SENAO '\n' comandos
    {
        $$ = malloc(strlen($3) + 20);
        sprintf($$, "else {\n%s}\n", $3);
        free($3);
    }
    ;

enquanto_loop:
    ENQUANTO '\n' comandos FIM
    {
        $$ = malloc(strlen($3) + 50);
        sprintf($$, "while(true) {\n%s}\n", $3);
        free($3);
    }
    ;

expressao:
    expressao IGUAL expressao       { $$ = concatenarExpressao("==", $1, $3); }
    | expressao DIFERENTE expressao { $$ = concatenarExpressao("!=", $1, $3); }
    | expressao MENOR expressao     { $$ = concatenarExpressao("<", $1, $3); }
    | expressao MAIOR expressao     { $$ = concatenarExpressao(">", $1, $3); }
    | expressao MENOR_IGUAL expressao { $$ = concatenarExpressao("<=", $1, $3); }
    | expressao MAIOR_IGUAL expressao { $$ = concatenarExpressao(">=", $1, $3); }
    | expressao MAIS expressao      {
     VarType tipo1 = getSymbolType($1);
             VarType tipo2 = getSymbolType($3);
             if (tipo1 != TYPE_INT || tipo2 != TYPE_INT) {
                 fprintf(stderr, "Erro semântico: Operação '+' inválida para tipos não numéricos.\n");
                 exit(1);
             }
     $$ = concatenarExpressao("+", $1, $3);
     }
    | expressao MENOS expressao     {
     VarType tipo1 = getSymbolType($1);
             VarType tipo2 = getSymbolType($3);

             if (tipo1 != TYPE_INT || tipo2 != TYPE_INT) {
                 fprintf(stderr, "Erro semântico: Operação '-' inválida para tipos não numéricos.\n");
                 exit(1);
             }
     $$ = concatenarExpressao("-", $1, $3);
     }
    | expressao MULT expressao      {
     VarType tipo1 = getSymbolType($1);
             VarType tipo2 = getSymbolType($3);

             if (tipo1 != TYPE_INT || tipo2 != TYPE_INT) {
                 fprintf(stderr, "Erro semântico: Operação '*' inválida para tipos não numéricos.\n");
                 exit(1);
             }
     $$ = concatenarExpressao("*", $1, $3);
     }
    | expressao DIV expressao       {
     VarType tipo1 = getSymbolType($1);
             VarType tipo2 = getSymbolType($3);

             if (tipo1 != TYPE_INT || tipo2 != TYPE_INT) {
                 fprintf(stderr, "Erro semântico: Operação '/' inválida para tipos não numéricos.\n");
                 exit(1);
             }
     $$ = concatenarExpressao("/", $1, $3);
     }
    | '(' expressao ')'             { $$ = $2; }
    | INTEIRO_LIT                   { $$ = malloc(20); sprintf($$, "%d", $1); }
    | BOOL_LIT                      { $$ = malloc(10); sprintf($$, $1 ? "true" : "false"); }
    | TEXTO_LIT                     { $$ = strdup($1); free($1); }
    | IDENT                         { $$ = strdup($1); free($1); }
    | leitura                       { $$ = $1; }
    | LER_SERIAL                    { $$ = strdup("Serial.readString()"); }
    ;

leitura:
    LER_DIGITAL IDENT
    {
        Symbol* sym = findSymbol($2);
                if (sym == NULL || sym->mode != INPUT) {
                    fprintf(stderr, "Erro semântico: O pino '%s' precisa ser configurado como entrada para usar lerDigital.\n", $2);
                    exit(1);
                }
        $$ = malloc(50);
        sprintf($$, "digitalRead(%s)", $2);
        free($2);
    }
    | LER_ANALOGICO IDENT
    {
        Symbol* sym = findSymbol($2);
                if (sym == NULL || sym->mode != INPUT) {
                    fprintf(stderr, "Erro semântico: O pino '%s' precisa ser configurado como entrada para usar lerAnalogico.\n", $2);
                    exit(1);
                }
        $$ = malloc(50);
        sprintf($$, "analogRead(%s)", $2);
        free($2);
    }
    ;

comandos:
    /* empty */ { $$ = strdup(""); }
    | comandos bloco_repita
    {
        $$ = malloc(strlen($1) + strlen($2) + 1);
        sprintf($$, "%s%s", $1, $2);
        free($1);
        free($2);
    }
    ;

esperar:
    ESPERAR INTEIRO_LIT ';'
    {
        $$ = malloc(50);
        sprintf($$, "delay(%d);\n", $2);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro na linha %d: %s\n", currentLine, s);
}

char* concatenarExpressao(const char* op, char* e1, char* e2) {
    char* result = malloc(strlen(e1) + strlen(e2) + strlen(op) + 4);
    sprintf(result, "(%s %s %s)", e1, op, e2);
    free(e1);
    free(e2);
    return result;
}

char* processarHttp(const char* url, const char* dados) {
    char* result = malloc(500);
    sprintf(result,
        "HTTPClient http;\n"
        "http.begin(%s);\n"
        "http.addHeader(\"Content-Type\", \"application/x-www-form-urlencoded\");\n"
        "int httpResponseCode = http.POST(%s);\n"
        "http.end();\n",
        url, dados);
    return result;
}

int main(int argc, char *argv[]) {
    yydebug = 1;
    output_file = fopen("saida.cpp", "w");
    if(!output_file) {
        perror("Erro ao criar arquivo de saída");
        return 1;
    }

    fprintf(output_file, "#include <Arduino.h>\n");
    fprintf(output_file, "#include <WiFi.h>\n");
    fprintf(output_file, "#include <HTTPClient.h>\n\n");
    fprintf(output_file, "// Configuração do PWM\n");
    fprintf(output_file, "int canalPWM = 0;\n\n");

    yyparse();
    return 0;
}