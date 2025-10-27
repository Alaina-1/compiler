%{
#include <stdio.h>
void yyerror(const char *s);
int yylex(void);
%}

%token IDENTIFIER

%%
input:
    IDENTIFIER    { printf("Valid identifier\n"); }
  | /* empty */   { printf("Invalid identifier\n"); }
  ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter a variable name: ");
    yyparse();
    return 0;
}
