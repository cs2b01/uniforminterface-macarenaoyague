%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
extern int yylex(void);
void yyerror(const char*);
volatile bool octal = 0;
%}
%union {
	int ival;
}
%token<ival> T_NUMBER T_ZERO T_OCT
%type <ival> numbase numd numo digito
%start S
%%
S	:
  	| S T
	;
T	: '\n'
  	| num_base '\n'   	{ if (octal) 	{ printf("\tOctal: %d\n", $1); } else {  printf("\tDecimal: %d\n", $1); } }
num_base  		: T_ZERO num_octal 		{ octal = 1; $$ = $2; }
		 		| num_decimal			{ $$ = $1; }
		 		;
num_octal		: num_octal digito		{ $$ = $1*8 + $2; }
	  	 		| digito 				{ $$ = $1; }
		 		;
num_decimal		: num_decimal digito 	{ $$ = $1*10 + $2; }
	  	 		| digito	   			{ $$ = $1; }
		 		;
digito 	 		: T_NUMBER	  			{ $$ = $1; }
				| T_ZERO	  			{ $$ = $1; }
				;
%%
int main(void) {
	return yyparse();
}
void yyerror(const char* msg) {
	fprintf(stderr, "Error: %s\n", msg);
	exit(1);
}
