%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *output_file;
int canalPWM = 0;
int currentLine = 1;

void yyerror(const char *s);
int yylex(void);

char* concatenarExpressao(const char* op, char* e1, char* e2);
char* processarHttp(const char* url, const char* dados);

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
%token IGUAL DIFERENTE MENOR MAIOR MENOR_IGUAL MAIOR_IGUAL
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
        if(strcmp($2, "int") == 0) {
            fprintf(output_file, "int %s;\n", $4);
        } else if(strcmp($2, "bool") == 0) {
            fprintf(output_file, "bool %s = false;\n", $4);
        } else {
            fprintf(output_file, "String %s;\n", $4);
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
    IDENT { $$ = strdup($1); free($1); }
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
    IDENT '=' expressao ';'
    {
        $$ = malloc(strlen($1) + strlen($3) + 20);
        sprintf($$, "%s = %s;\n", $1, $3);
        free($1);
        free($3);
    }
    ;

controle_gpio:
    LIGAR IDENT ';'
    {
        $$ = malloc(50);
        sprintf($$, "digitalWrite(%s, HIGH);\n", $2);
        free($2);
    }
    | DESLIGAR IDENT ';'
    {
        $$ = malloc(50);
        sprintf($$, "digitalWrite(%s, LOW);\n", $2);
        free($2);
    }
    ;

config_pin:
    CONFIGURAR IDENT COMO SAIDA ';'
    {
        $$ = malloc(100);
        sprintf($$, "pinMode(%s, OUTPUT);\n", $2);
        free($2);
    }
    | CONFIGURAR IDENT COMO ENTRADA ';'
    {
        $$ = malloc(100);
        sprintf($$, "pinMode(%s, INPUT);\n", $2);
        free($2);
    }
    ;

config_pwm:
    CONFIG_PWM IDENT COM FREQUENCIA INTEIRO_LIT RESOLUCAO INTEIRO_LIT ';'
    {
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
    | expressao MAIS expressao      { $$ = concatenarExpressao("+", $1, $3); }
    | expressao MENOS expressao     { $$ = concatenarExpressao("-", $1, $3); }
    | expressao MULT expressao      { $$ = concatenarExpressao("*", $1, $3); }
    | expressao DIV expressao       { $$ = concatenarExpressao("/", $1, $3); }
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
        $$ = malloc(50);
        sprintf($$, "digitalRead(%s)", $2);
        free($2);
    }
    | LER_ANALOGICO IDENT
    {
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