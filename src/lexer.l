%{
#include "parser.tab.h"
#include <string.h>
void yyerror(const char *s);
%}

%option noyywrap

LETRA   [a-zA-Z]
DIGITO  [0-9]
ID      {LETRA}({LETRA}|{DIGITO}|_)*
INTEIRO {DIGITO}+
TEXTO   \"([^\\\"]|\\.)*\"

%%

"var"           { return VAR; }
"inteiro"       { return INTEIRO; }
"booleano"      { return BOOLEANO; }
"texto"         { return TEXTO_TYPE; }
"config"        { return CONFIG; }
"fim"           { return FIM; }
"repita"        { return REPITA; }
"como"          { return COMO; }
"saida"         { return SAIDA; }
"entrada"       { return ENTRADA; }
"configurar"    { return CONFIGURAR; }
"ligar"         { return LIGAR; }
"desligar"      { return DESLIGAR; }
"lerDigital"    { return LER_DIGITAL; }
"lerAnalogico"  { return LER_ANALOGICO; }
"configurarPWM" { return CONFIG_PWM; }
"ajustarPWM"    { return AJUSTAR_PWM; }
"com"           { return COM; }
"frequencia"    { return FREQUENCIA; }
"resolucao"     { return RESOLUCAO; }
"conectarWifi"  { return CONECTAR_WIFI; }
"enviarHttp"    { return ENVIAR_HTTP; }
"configurarSerial" { return CONFIG_SERIAL; }
"escreverSerial"  { return ESCREVER_SERIAL; }
"lerSerial"     { return LER_SERIAL; }
"esperar"       { return ESPERAR; }
"se"            { return SE; }
"senao"         { return SENAO; }
"entao"         { return ENTAO; }
"enquanto"      { return ENQUANTO; }
"=="            { return IGUAL; }
"!="            { return DIFERENTE; }
"<"             { return MENOR; }
">"             { return MAIOR; }
"<="            { return MENOR_IGUAL; }
">="            { return MAIOR_IGUAL; }
"+"             { return MAIS; }
"-"             { return MENOS; }
"*"             { return MULT; }
"/"             { return DIV; }

{INTEIRO}       { yylval.ival = atoi(yytext); return INTEIRO_LIT; }
"verdadeiro"    { yylval.ival = 1; return BOOL_LIT; }
"falso"         { yylval.ival = 0; return BOOL_LIT; }
{TEXTO}         { yylval.sval = strdup(yytext); return TEXTO_LIT; }
{ID}            { yylval.sval = strdup(yytext); return IDENT; }

[ \t\n]         ; // Ignora espaços, tabs e novas linhas
"//".*          ; // Ignora comentários
.               { yyerror("Caractere inválido"); }

%%