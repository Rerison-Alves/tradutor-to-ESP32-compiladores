@echo off
cd .\regras\
flex tradutor.l
bison -d tradutor.y
cd ..
gcc -o tradutor .\regras\tradutor.tab.c .\regras\lex.yy.c

IF %ERRORLEVEL% NEQ 0 (
    echo Erro durante a compilacao.
    pause
    exit /b 1
)

echo Compilacao completa. Execute com:
echo .\tradutor.exe '.\arquivo_programa.txt'
echo.

pause

cmd /k
