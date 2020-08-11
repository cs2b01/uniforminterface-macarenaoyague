%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
	char* strval;
}

%token<ival> T_INT
%token<fval> T_FLOAT
%token<sval> T_STR
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_LEFT T_RIGHT
%token T_NEWLINE T_QUIT
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE
%left T_CASE3
%left T_CASE2
%left T_CASE1

%type<ival> expression
%type<fval> mixed_expression
%type<sval> str_expression

%start calculation

%%

calculation:
	   | calculation line
;

line: T_NEWLINE
    | mixed_expression T_NEWLINE { printf("\tResult: %f\n", $1);}
    | expression T_NEWLINE { printf("\tResult: %i\n", $1); }
	| str_expression T_NEWLINE { printf("\tResult: %s\n", $1); }
    | T_QUIT T_NEWLINE { printf("bye!\n"); exit(0); }
;

mixed_expression: T_FLOAT                 		 { $$ = $1; }
	  | mixed_expression T_PLUS mixed_expression	 { $$ = $1 + $3; }
	  | mixed_expression T_MINUS mixed_expression	 { $$ = $1 - $3; }
	  | mixed_expression T_MULTIPLY mixed_expression { $$ = $1 * $3; }
	  | mixed_expression T_DIVIDE mixed_expression	 { $$ = $1 / $3; }
	  | T_LEFT mixed_expression T_RIGHT		 { $$ = $2; }
	  | expression T_PLUS mixed_expression	 	 { $$ = $1 + $3; }
	  | expression T_MINUS mixed_expression	 	 { $$ = $1 - $3; }
	  | expression T_MULTIPLY mixed_expression 	 { $$ = $1 * $3; }
	  | expression T_DIVIDE mixed_expression	 { $$ = $1 / $3; }
	  | mixed_expression T_PLUS expression	 	 { $$ = $1 + $3; }
	  | mixed_expression T_MINUS expression	 	 { $$ = $1 - $3; }
	  | mixed_expression T_MULTIPLY expression 	 { $$ = $1 * $3; }
	  | mixed_expression T_DIVIDE expression	 { $$ = $1 / $3; }
	  | expression T_DIVIDE expression		 { $$ = $1 / (float)$3; }
;

expression: T_INT				{ $$ = $1; }
	  | expression T_PLUS expression	{ $$ = $1 + $3; }
	  | expression T_MINUS expression	{ $$ = $1 - $3; }
	  | expression T_MULTIPLY expression	{ $$ = $1 * $3; }
	  | T_LEFT expression T_RIGHT		{ $$ = $2; }
;

str_expression: T_STR { $$ = $1; }
				| T_CASE1 str_expression { 	int size = strlen($2);
											for (int i = 0; i < size; i++) {
											if ($2[i] >= 'a' && $2[i] <= 'z') {$2[i] = $2[i] - 32;}
											else if($2[i] >= 'A' && $2[i] <= 'Z') {$2[i] = $2[i] + 32;}}
											$$ = $2;   } 
				| str_expression T_CASE2 str_expression { 	int size = strlen($1);
															for (int i = 0; i < size; i++) {
															if($1[i] >= 'A' && $1[i] <= 'Z') { $1[i] = $1[i] + 32;}}
															size = strlen($3);
															for (int i = 0; i < size; i++) {
															if($3[i] >= 'A' && $3[i] <= 'Z') {$3[i] = $3[i] + 32;}}
															$$ = strcat($1, $3);		}
				| str_expression T_CASE3 str_expression { 	$$ = $2;	}

;


%%

int main() {
	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
