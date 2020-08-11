%{
#include "Num1.tab.h"
%}
%option noyywrap
%%
[0]				{yylval.ival = atoi(yytext); return T_ZERO; }
[1-9]			{yylval.ival = atoi(yytext); return T_NUMBER; }
[\n]			{return yytext[0];}
[ \t]			{; }
%%
