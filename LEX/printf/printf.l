%{
#include <stdio.h>
int printf_count = 0;
int scanf_count = 0;
%}

%%
"printf"    { printf("writef"); printf_count++; }
"scanf"     { printf("readf"); scanf_count++; }
.|\n        { ECHO; }
%%

int main() {
    FILE *fp = fopen("input.c", "r");
    if (!fp) {
        perror("Error opening input.c");
        return 1;
    }

    yyin = fp;      // Set the Lex input source file
    yylex();        // Start scanning
    fclose(fp);     // Close file

    printf("\n\nTotal printf: %d\n", printf_count);
    printf("Total scanf: %d\n", scanf_count);
    return 0;
}

int yywrap() {
    return 1;
}
