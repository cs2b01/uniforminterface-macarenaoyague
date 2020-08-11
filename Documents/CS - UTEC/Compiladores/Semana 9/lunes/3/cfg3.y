%{
    #include <stdio.h>
    #include <ctype.h>
%}
%token a
%%
command : S {printf("%c\n", $1);}
        ;
S : C { $$ = $1; }
  ;
C : a { $$ = $1; }
  ;
%%
main()
{ return yyparse();
}
int  yylex(void)
{
    int c;
    while ((c = getchar()) == ' ');
    if (isdigit(c)){
        ungetc(c, stdin);
        scanf("%d", &yylval);
        return(NUMBER);
    }
    if (c == '\n') return 0;
    return (c);
}
void yyerror(char* s)
{ fprintf(stderr, "%s\n", s);
}
