%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *msg);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%
calc:
      exp '\n'      { printf("Result = %d\n", $1); }
    ;

exp:
      NUMBER                { $$ = $1; }
    | exp '+' exp           { $$ = $1 + $3; }
    | exp '-' exp           { $$ = $1 - $3; }
    | exp '*' exp           { $$ = $1 * $3; }
    | exp '/' exp           {
                                if ($3 == 0) {
                                    yyerror("Division by zero");
                                    $$ = 0;
                                } else {
                                    $$ = $1 / $3;
                                }
                            }
    | '(' exp ')'            { $$ = $2; }
    ;
%%

int main() {
    printf("Enter an expression:\n");
    yyparse();
    return 0;
}

void yyerror(const char *msg) {
    printf("Error: %s\n", msg);
}
