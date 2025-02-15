@echo off
cd .\src\
flex lexer.l
bison -d --debug parser.y
cd ..
gcc -o tradutor .\src\parser.tab.c .\src\lex.yy.c

IF %ERRORLEVEL% NEQ 0 (
    echo Erro durante a compilacao.
    pause
    exit /b 1
)

echo Compilacao completa. Execute com:
echo .\tradutor.exe '.\arquivo_input'
echo.

pause

cmd /k
