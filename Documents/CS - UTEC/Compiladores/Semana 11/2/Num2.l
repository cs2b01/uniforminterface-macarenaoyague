%{
#include "Num2.tab.h"
%}
%option noyywrap
%%
"o"			{ yylval.carbase = yytext[0]; return T_OCTAL; }
"d"			{ yylval.carbase = yytext[0]; return T_DECIMAL; }
[0-9]		{ yylval.ival = atoi(yytext); return T_NUMBER; }
[\n]		{ return yytext[0]; }
[ \t] 		;
%%
