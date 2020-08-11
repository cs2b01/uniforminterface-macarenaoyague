%{

    #include <stdio.h>

%}

letter              [A-Za-z]
number              [0-9]
underscore          [_]
endline             [.*\n]
space               [ ]
datatypes           short|register|auto|void|double|long|char|signed|int|float|unsigned|const|static|enum|struct|extern|volatile
control             while|if|do|else|for|continue|break|switch|return|case|goto
other               sizeof|default|typedef|union
classicId           ({underscore}|{letter})({underscore}|{letter}|{number})* 
nInt                ([1-9]{number}*)|0
nFloat              ({number}+[.]{number}*)|({number}*[.]{number}+)
nOctal              0[0-7]+
nHexadecimal        0x([0-9]|[a-f]|[A-F])+
arithmetic          \+\+|--|\+|-|\*|%|\/
relational          ==|!=|<|>|<=|>=
logical             &&|!|\|\|
bitwise             &|^|<<|>>|\|
assignment          {arithmetic}?=
conditional         [\?]


KEYWORD             {datatypes}|{control}|{other}
IDENTIFIER          {classicId}|{KEYWORD}({number}|{underscore}{letter})+
CONSTANT            {nInt}|{nFloat}|{nOctal}|{nHexadecimal}
SPECIAL_SYMBOL      [\{\}\(\)\[\];,#]
OPERATOR            {arithmetic}|{relational}|{logical}|{bitwise}|{assignment}|{conditional}
            
%%

{space}             {}
{endline}           {}

{KEYWORD}           {printf("(\"%s\", KEYWORD)\n", yytext);}
{IDENTIFIER}        {printf("(\"%s\", IDENTIFIER)\n", yytext);}
{CONSTANT}          {printf("(\"%s\", CONSTANT)\n", yytext);}
{SPECIAL_SYMBOL}    {printf("(\"%s\", SPECIAL_SYMBOL)\n", yytext);}
{OPERATOR}          {printf("(\"%s\", OPERATOR)\n", yytext);}


%% 
  
int yywrap(){return 1;}  

int main() 
{ 

    extern FILE *yyin;
    yyin = fopen("test.c","r");
    yylex();
    
    return 0; 

}
