%option noyywrap
%{
#include <stdio.h>
#define YY_DECL int yylex()
#include "y.tab.h"
int ntoken = 0;
%}
number [0-9]+.?|[0-9]*.[0-9]+
%%
[ ] {}
{number} {++ntoken;printf("%d: nodo hoja %d \n", number, ntoken); return NUMBER;}
\n|. {return yytext[0];}
%%