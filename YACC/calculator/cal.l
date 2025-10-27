%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+          { yylval = atoi(yytext); return NUMBER; }   /* numbers */
[ \t]+          ;                                            /* ignore spaces/tabs */
\n              { return '\n'; }                             /* newline triggers eval */
.               { return yytext[0]; }                        /* operators and others */
%%

int yywrap() { return 1; }
