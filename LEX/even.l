%{
#include <stdio.h>
%}

%%
[0-9]*[02468]     { printf("Even number: %s\n", yytext); }
[0-9]*[13579]     { printf("Odd number: %s\n", yytext); }
.|\n              ;   /* ignore anything else */
%%

int main() {
    printf("Enter a number and press Ctrl+D (Linux/Mac) or Ctrl+Z (Windows) when done:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
