%{
#include <stdio.h>
%}

DIGIT           [0-9]
ID              [_a-zA-Z][a-zA-Z0-9]*
KEYWORD         "if"|"else"|"while"|"int"
OP              ">"|"<"|"="|">="|"<="|"+"|"-"|"*"|"/"
SPECIALCHARACTER    "'"|":"|";"|"("|")"

%%
{KEYWORD}+              { printf("%s is a keyword\n", yytext); }
{DIGIT}+                { printf("%s is an integer\n", yytext); }
{ID}+                   { printf("%s is an identifier\n", yytext); }
{OP}+                   { printf("%s is an operator\n", yytext); }
{SPECIALCHARACTER}+     { printf("%s is a special character\n", yytext); }
%%

void main()
{
    printf("Enter the string:\n");
    yylex();
}

int yywrap()
{
    return 1;
}
