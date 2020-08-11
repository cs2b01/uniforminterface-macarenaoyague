%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
extern int yylex(void);
void yyerror(const char* s);
volatile bool octal = 0;
int function(int num_octal) {
    int num_decimal = 0;
	int i = 0;
	int aux = num_octal;
    while (aux != 0) {
    	if (aux%10 == 8 || aux%10 == 9) {
    		printf("Error: Octal es de 0-7.\n");
    		exit(1);
    	}
    	aux /= 10;
    }
    while (num_octal != 0) {
        num_decimal += (num_octal%10)*pow(8,i);
        ++i;
        num_octal /= 10;
    }
    return num_decimal;
}
%}
%union{
	int ival;
	char carbase;
}
%token<carbase> T_OCTAL T_DECIMAL
%token<ival> T_NUMBER
%type<ival> num
%type<ival> digito
%type<ival> num_base
%start S
%%
S	: 
 	| S T
 	;
T	: '\n'
	| num_base '\n' {if (octal) { printf("\tOctal: %d\n", $1); } else { printf("\tDecimal: %d\n", $1); } }
	;
num_base: num T_DECIMAL { octal = 0; $$ = $1; }
		| num T_OCTAL 	{ octal = 1; $$ = function($1); }
	    ;
num: num digito	{ $$ = $1*10 + $2; }  
   | digito		{ $$ = $1; }
   ;
digito : T_NUMBER { $$ = $1; }
	   ;
%%
int main() {
	return yyparse();
}
void yyerror (const char* s) {
	fprintf(stderr, "Error: %s\n", s);
	exit(1);
}