%{
    #include<stdio.h>
    int flag=0;
%}
%%
[a-zA_Z0-9]+@[a-z]+".com" {flag=1;}
%%
int main(){
    printf("Enter the email and preess Ctrl+D when done:\n");
    yylex();
    if(flag)
        printf("Valid email\n");
    else
        printf("Invalid email\n");
}
int yywrap(){
    return 1;
}