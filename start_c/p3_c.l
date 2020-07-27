%{
#include <stdio.h>
#include <stdlib.h>
#include "p3.tab.h"


const char *token_err_msg = "lexical error at line %d\n";
int line_no = 1;
int while_active = 0;

%}

 /* regular definitions */

%option never-interactive
%option yylineno
%%
 /* placeholder */
\+		{return('+');}
\-		{return('-');}
\*		{return('*');}
\/		{return('/');}
\=		{return('=');}
\==		{while_active = while_active + 2;return(EQUALITY);}
\<		{while_active = while_active + 2;return('<');}
\>		{while_active = while_active + 2;return('>');}
\<=		{while_active = while_active + 2;return(LESSTHEO);}
\>=		{while_active = while_active + 2;return(GREATERTHEO);}
\<>		{while_active = while_active + 2;return(NOTEQUAL);}
\(		{return('(');}
\)		{return(')');}
\:		{return(COLON);}
\,		{return(',');}
\def	{return(DEF);}
\enddef	{return(ENDDEF);}
\if		{return(IF);}
\endif	{return(ENDDIF);}
\else	{return(ELSE);}
\while	{while_active = 1;return(WHILE);}
\endwhile	{return(ENDWHILE);}
\print		{return(PRINT);}
\input		{return(INPUT);}
"true"		{return(TRUE);}
"false"		{return(FALSE);}
"return"		{return(RETURN);}
[0-9]*[0-9]+			{yylval.fn = atoi(yytext); return(NUMBER);}
[a-zA-Z_][a-zA-Z0-9_]*	{yylval.a = (char*)malloc(strlen(yytext)+1); strcpy(yylval.a,yytext);return(IDENTIFIER);}
[\"][a-zA-Z0-9_]+[\"]	{yylval.a = (char*)malloc(strlen(yytext)+1); strcpy(yylval.a,yytext);return(STRING);}
[!].*[\n]?$       {}
[ \t]                 { }
[\n]                    {line_no++;}
.                       {return(ERROR);}

 /* keywords */
 /* operators */

 /* punctuations */

 /* other tokens */

 /* white spaces and other */

%%


