%{

    #include <stdio.h>

%}

letra               [A-Za-z]
numero              [0-9]
underscore          [_]
endline             [.*\n]
espacio             [ ]

IDENTIFICADOR       ({letra}|{underscore})({letra}|{numero}|{underscore})*
NUMEROENTERO        {numero}+
NUMERODECIMAL       {numero}*[.]{numero}+
COMILLAS            ["]      
LLAVEIZQUIERDA      [{]
LLAVEDERECHA        [}]
SEMICOLON           [;]
CAMBIODELINEA       {endline} 

%%

{espacio}           {}
{IDENTIFICADOR}     {printf("IDENTIFICADOR ");}
{NUMEROENTERO}      {printf("NUMEROENTERO ");}
{NUMERODECIMAL}     {printf("NUMERODECIMAL ");}
{COMILLAS}          {printf("COMILLAS ");}
{LLAVEIZQUIERDA}    {printf("LLAVEIZQUIERDA ");}
{LLAVEDERECHA}      {printf("LLAVEDERECHA ");}
{SEMICOLON}         {printf("SEMICOLON ");}
{CAMBIODELINEA}     {printf("CAMBIODELINEA ");}

%% 
  
int yywrap(){return 1;}  

int main() 
{ 

    extern FILE *yyin;
    yyin = fopen("test.c","r");
    yylex();
    
    return 0; 

}
