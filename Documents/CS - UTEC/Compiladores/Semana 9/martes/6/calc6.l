%option noyywrap
%{
#include <stdio.h>
#define YY_DECL int yylex()
#include "y.tab.h"
%}
int [0-9]+
float [0-9]+\.[0-9]+ 
%%
[ ] {}
{int}		{yylval = atoi(yytext); return NUMBER;}
{float} 	{yylval = atof(yytext); return NUMBER;}
\n|. {return yytext[0];}
%%