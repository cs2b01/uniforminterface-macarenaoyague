%{

    #include <stdio.h>
    int nLines = 0;

%}

endline .*\n 

%%

{endline} {printf("%d %s", ++nLines, yytext);}



%% 
  
int yywrap(){return 1;}  

int main() 
{ 

    extern FILE *yyin;
    yyin = fopen("test.c","r");
    yylex();
    return 0; 

}
