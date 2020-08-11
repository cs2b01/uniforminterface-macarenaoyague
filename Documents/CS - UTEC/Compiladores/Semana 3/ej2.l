%{

    #include <stdio.h>
    int nPalabras = 0;
    int nCaracteres = 0;
    int nLineas = 0;

%}

letra       [A-Za-z]
palabra     {letra}+
espacio     [ ]
endline     [.*\n]

%%

{endline}       {nLineas++;}
{palabra}       {nPalabras++;nCaracteres+=yyleng;}
{espacio}       {}
.               {nCaracteres++;}

%% 
  
int yywrap(){return 1;}  

int main() 
{ 

    extern FILE *yyin;
    yyin = fopen("test.c","r");
    yylex();
    printf("Palabras = %d \n", nPalabras);
    printf("Caracteres = %d \n", nCaracteres);
    printf("Lineas = %d \n", nLineas);
    
    return 0; 

}
