%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct symbol_table {
    char id_name[30];
    char function_name[30];
    char datatype_name[30];
    int int_value;
    int bool_value;
    char string_value[30];
} Symbol_table;


//Helper function to copy dat at every level
void compareTermandExp();
extern int yylineno;
int yyerror();
int yylex();
int yyerror_semantic();
const char* pass_msg = "Input Passed Checking\n";
const char* syn_err_msg = "syntax error at line %d\n";
void printing_symbol_table();
void printing_symbol_table_global();
void lookForID(char *word);
void addFunInglobe(char *word);
void addIDasINT(char *word);
void compAsst();
void copyIntoFactorfromString(char *word);
void copyExpressionfromExp();
void copyTermfromFactor();
void copyExpfromTerm();
void copyIntoFactorfromInt(int j);
void copyIntoFactorfromIdentifier(char *word, char *datatype);
void copyIntoFactorfromFalse();
void copyIntoFactorfromTrue();
void checkExpforReturn();
void checkIDreturn(char *word);
void checkID(char *word);
void checkIfPrintisRight();
void checkForterm();
void clearFun();
void checkIfFunexists(char *word);
void clearOutFactor();
void lookForIDorAdd(char *word);
void checkForFactor();
void checkForFactorhere();
void addInSymbolTableInput();

//Two scopes, one is global and the other is the function scope
Symbol_table* function_sts;
Symbol_table* global_sts;

int in_fun = 0;

int sem_err_check = 0;

extern int line_no;
extern int while_active;

//These are the symbol tables at all the levels
Symbol_table factor_temp;
Symbol_table term_temp;
Symbol_table expression_temp;
Symbol_table exp_temp;
Symbol_table assignment_temp;
Symbol_table callst_temp;


%}


%token ERROR
%token EQUALITY LESSTHEO GREATERTHEO NOTEQUAL COLON
%token DEF ENDDEF IF ENDDIF ELSE WHILE ENDWHILE PRINT INPUT TRUE FALSE RETURN NUMBER IDENTIFIER STRING
%token NI

//union has three different types
%union {
    char *a;
    int fn;
    double d;
}

%type <a> IDENTIFIER STRING
%type <fn> NUMBER

%%

PROGRAM             : FUNCTION_LIST END_LIST                                            {}
		            ;
FUNCTION_LIST       : FUNCTION_LIST FUNCTION 
                    | FUNCTION
                    ;
FUNCTION            : DEF IDENTIFIER '(' PARAMATERS ')' COLON STATEMENTS ENDDEF         {checkIfFunexists($2); clearFun(); }
                    | DEF IDENTIFIER '(' ')' COLON STATEMENTS ENDDEF                    {checkIfFunexists($2); clearFun(); }
                    ;
PARAMATERS          : PARAMATERS ',' IDHERE                                                     {in_fun = 1;}
                    | IDHERE                                                                    {in_fun = 1;}
                    ;
IDHERE              : IDENTIFIER                                                                {addIDasINT($1);}
                    ;
STATEMENTS          : STATEMENTS STATEMENT
                    | STATEMENT                                                                 {}
                    ;
STATEMENT           : ASSIGNMENT_STMT                                                           {}
                    | PRINT_STMT
                    | INPUT_STMT
                    | CONDITION_STMT
                    | WHILE_STMT
                    | CALL_STMT
                    | RETURN_STMT
                    ;
ASSIGNMENT_STMT     : IDENTIFIER '=' EXPRESSION                                                 {lookForIDorAdd($1);}
		            ;
RETURN_STMT         : RETURN EXP                                                                {checkExpforReturn();}
                    ;
EXPRESSION          : REL_EXP
                    | EXP                                                                       {copyExpressionfromExp();}
                    ;
REL_EXP             : EXP EQUALITY EXP                                                          {compareTermandExp();}
                    | EXP NOTEQUAL EXP                                                          {compareTermandExp();}
                    | EXP '<' EXP                                                               {compareTermandExp();}
                    | EXP LESSTHEO EXP                                                          {compareTermandExp();}
                    | EXP '>' EXP                                                               {compareTermandExp();}
                    | EXP GREATERTHEO EXP                                                       {compareTermandExp();}
                    | '('REL_EXP')'
                    ;
EXP                 : EXP '+' TERM                                                              {checkForterm();}
                    | EXP '-' TERM                                                              {checkForterm();}
                    | TERM                                                                      {copyExpfromTerm();}
                    ;
TERM                : TERM '*' FACTOR                                                           {checkForFactor();}
                    | TERM '/' FACTOR                                                           {checkForFactor();}
                    | FACTOR                                                                    {copyTermfromFactor();}
                    ;
FACTOR              : '('EXP')'                                                                 {}
                    | NUMBER                                                                    {copyIntoFactorfromInt($1); }
                    | STRING                                                                    {copyIntoFactorfromString($1);}
                    | IDENTIFIER                                                                {checkID($1);}
                    | TRUE                                                                      {copyIntoFactorfromTrue();}
                    | FALSE                                                                     {copyIntoFactorfromFalse();}
                    | '-' FACTOR
                    | CALL_STMT                                                                 {clearOutFactor();}
                    ;
PRINT_STMT          : PRINT '('EXPRESSION_LIST')'                                               {checkIfPrintisRight();}
		            ;
INPUT_STMT          : IDENTIFIER '=' INPUT '('')'                                               {addInSymbolTableInput($1);}
		            ;
CALL_STMT           : IDENTIFIER '('')'                                                         {checkIDreturn($1); strcpy(callst_temp.datatype_name, "int");}
                    | IDENTIFIER '(' EXPR_LIST ')'                                              {checkIDreturn($1); strcpy(callst_temp.datatype_name, "int");}
                    ;
CONDITION_STMT      : IF_HEAD STATEMENTS ENDDIF
                    | IF_HEAD STATEMENTS ELSE COLON STATEMENTS ENDDIF
                    ;
IF_HEAD             : IF EXPRESSION COLON
		            ;
WHILE_STMT          : WHILE EXPRESSION COLON STATEMENTS ENDWHILE
		            ;
EXPRESSION_LIST     : EXPRESSION_LIST ',' EXPRESSION
                    | EXPRESSION
                    ;
EXPR_LIST           : EXPR_LIST ',' EXP
                    | EXP
                    ;
END_LIST            : END_LIST END
                    | END
                    ;
END                 : CALL_STMT
                    | PRINT_STMT
                    | INPUT_STMT
                    ;

%%




int main(){

    //Code for debugging
    #if YYDEBUG == 1
    extern int yydebug;
    yydebug = 1;
    #endif

    global_sts = malloc(20 * sizeof * global_sts);
    function_sts = malloc(20 * sizeof * function_sts);


    for (int x = 0; x < 20; x++){
        strcpy(global_sts[x].datatype_name, "");
        strcpy(function_sts[x].datatype_name, "");
        strcpy(global_sts[x].function_name, "");
        strcpy(function_sts[x].function_name, "");
        strcpy(global_sts[x].string_value, "");
        strcpy(function_sts[x].string_value, "");
        strcpy(global_sts[x].id_name, "");
        strcpy(function_sts[x].id_name, "");
        global_sts[x].int_value = 0;
        function_sts[x].int_value = 0;
        global_sts[x].bool_value = 0;
        function_sts[x].bool_value = 0;
    }

    yyparse();

    if(sem_err_check == 0) {
        fprintf(stdout, "Input Passed Checking\n");
    }

    return 0;
}

void addInSymbolTableInput(char *word) {
    if(in_fun == 1){
        //Add in local scope
        for(int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, "") == 0) {
                //spot found
                strcpy(function_sts[i].id_name, word);
                strcpy(function_sts[i].datatype_name, "int");
                return;
            }
        }
    }
    else {
        for(int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, "") == 0) {
                //spot found
                strcpy(global_sts[i].id_name, word);
                strcpy(global_sts[i].datatype_name, "int");
                return;
            }
        }
    }
}

void compareTermandExp() {
    //check the datatype of exp and term
    if(strcmp(term_temp.datatype_name, "int") == 0 && strcmp(exp_temp.datatype_name, "int") == 0) {
        return;
    }
    else {
        fprintf(stderr, "Relational expression needs int datatype to proceed, error at line %d\n", line_no);
    }
}

void checkExpforReturn() {

    //printf("%s\n", exp_temp.datatype_name);

    if(strcmp(callst_temp.datatype_name, "int") == 0) {
        strcpy(callst_temp.datatype_name, "");
        return;
    }
    if(strcmp(exp_temp.datatype_name, "int") != 0) {
        fprintf(stderr, "Return value is not int: at line %d\n", line_no);
        sem_err_check = 1;
        return;
    }
}

void lookForIDorAdd(char *word) {
    //printf("Datatype of expression : %s\n", expression_temp.id_name);
    //First look for thed identifdier if it exists in the fun or global
    if(in_fun == 1) {
        //Looking in function
        for(int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, word) == 0) {
                //Id exists in the function, now check its datatype with the expression data type
                if(strcmp(function_sts[i].datatype_name, expression_temp.datatype_name) != 0 && strcmp(expression_temp.datatype_name, "nothing") != 0) {
                    //If the datatype name doesnt match then throw an error
                    fprintf(stderr, "cannot assign %s value to %s of datatype %s at line %d\n", expression_temp.datatype_name, word, function_sts[i].datatype_name, line_no);
                    sem_err_check = 1;
                    return;
                }
                else {
                    return;
                }
            }
        }
    }
    //checking in global
    for(int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, word) == 0) {
                //Id exists in the function, now check its datatype with the expressfion data type
                if(strcmp(global_sts[i].datatype_name, expression_temp.datatype_name) != 0 && strcmp(expression_temp.datatype_name, "nothing") != 0) {
                    //If the datatype name doesnt match then throw an error
                    fprintf(stderr, "cannot assign %s value to %s of datatype %s at line %d\n", expression_temp.datatype_name, word, global_sts[i].datatype_name, line_no);
                    sem_err_check = 1;
                    return;
                }
                else {
                    return;
                }
            }
        }

        //If they dondt exist in the symbol table then adding it into symbol table
        if(in_fun == 1) {
            //adding in function
            for(int i = 0; i < 20; i++) {
                //checking for the first empty slot in function
                if(strcmp(function_sts[i].datatype_name, "") == 0) {
                    strcpy(function_sts[i].id_name, word);
                    strcpy(function_sts[i].datatype_name, expression_temp.datatype_name);
                    return;
                }
            }
        }
        else {
            for(int i = 0; i < 20; i++) {
                //checking for the first ecmpty slot in function
                if(strcmp(global_sts[i].datatype_name, "") == 0) {
                    strcpy(global_sts[i].id_name, word);
                    strcpy(global_sts[i].datatype_name, expression_temp.datatype_name);
                    return;
                }
            }
        }
}

void clearOutFactor() {
        strcpy(factor_temp.datatype_name, "");
        strcpy(factor_temp.function_name, "");
        strcpy(factor_temp.string_value, "");
        strcpy(factor_temp.id_name, "");
        factor_temp.int_value = 0;
        factor_temp.bool_value = 0;
}

void clearFun() {
    for (int x = 0; x < 20; x++){
        strcpy(function_sts[x].datatype_name, "");
        strcpy(function_sts[x].function_name, "");
        strcpy(function_sts[x].string_value, "");
        strcpy(function_sts[x].id_name, "");
        function_sts[x].int_value = 0;
        function_sts[x].bool_value = 0;
    }
    in_fun = 0;
}

void checkIfFunexists(char *word) {
    //Only look in global variable
    for(int i = 0; i < 20; i++) {
        if(strcmp(global_sts[i].id_name, word) == 0) {
            fprintf(stderr, "function %s already declared before : error at line %d\n", word, line_no);
            sem_err_check = 1;
            return;
        }
    }
    addFunInglobe(word);
}

void checkForExphere() {
        //Checking whdether exp exists or not

    if(strcmp(exp_temp.id_name, "") != 0) {
    if(in_fun == 1) {
        for (int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, exp_temp.id_name) == 0) {
                
                //If founfd then ffcheck ffor ddatatype
                if(strcmp(function_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }
    }
    for (int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, exp_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(global_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }

    fprintf(stderr, "Variable %s is undeclared before use in this expression : line %d\n", exp_temp.id_name, line_no);
    sem_err_check = 1;
    }
    else {
        if(strcmp(exp_temp.datatype_name, "int") != 0) {
            fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
        }
    }
    
}

void checkForFactorhere() {
        //Checking whether exp exists or not
    if(strcmp(factor_temp.id_name, "") != 0) {
    if(in_fun == 1) {
        for (int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, factor_temp.id_name) == 0) {
                
                //If founfd then ffcheck ffor ddatatype
                if(strcmp(function_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }
    }
    for (int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, factor_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(global_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }

    fprintf(stderr, "Variable %s is undeclared before use in this expression : line %d\n", exp_temp.id_name, line_no);
    sem_err_check = 1;
    }
    else {
        if(strcmp(factor_temp.datatype_name, "int") != 0) {
            fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
        }
    }
    
}

void checkForterm() {

    //  printf("EXP : %s is of datatype %s\n", exp_temp.id_name, exp_temp.datatype_name);
    //  printf("TERM : %s is of datatype %s\n", term_temp.id_name, term_temp.datatype_name);
    //Checking for int dvatatype

    if(strcmp(term_temp.id_name, "") != 0) {

    if(in_fun == 1) {
        for (int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, term_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(function_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }
    }
    for (int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, term_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(global_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }
    fprintf(stderr, "Variable %s is undeclared before use in this expression : line %d\n", term_temp.id_name, line_no);
    sem_err_check = 1;
    }
    else {
        //If no id name then check the datatype
        if(strcmp(term_temp.datatype_name, "int") != 0) {
            fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
        }
    }

    checkForExphere();

}

void checkForFactor() {

    

    //  printf("EXP : %s is of datatype %s\n", exp_temp.id_name, exp_temp.datatype_name);
    //printf("TERM : f%s is of datatype %ds\n", term_temp.id_name, term_temp.datatype_name);
    //Checking for int dvatatype

    if(strcmp(term_temp.id_name, "") != 0) {

    if(in_fun == 1) {
        for (int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, term_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(function_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    checkForFactorhere();
                    return;
                }
                checkForFactorhere();
                return;
            }
        }
    }
    for (int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, term_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(global_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                    checkForFactorhere();
                }
                checkForFactorhere();
                return;
            }
        }
    fprintf(stderr, "Variable %s is undeclared before use in this expression : line %d\n", term_temp.id_name, line_no);
    sem_err_check = 1;
    checkForFactorhere();
    }
    else {
        //If no id name then check the datatype
        if(strcmp(term_temp.datatype_name, "int") != 0) {
            fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    checkForFactorhere();
                    return;
        }
    }

    

}

void checkID(char *word) {

    if(while_active == 1) {
    if(in_fun == 1) {
        //Inside the function then
        for(int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, factor_temp.id_name) == 0) {
                if(strcmp(function_sts[i].datatype_name, "bool") != 0) {
                    fprintf(stderr, "while variable doesnt have boolean datatype : at line %d\n", line_no);
                    sem_err_check = 1;
                    while_active = 0;
                    return;
                }
                
                }
            }
        }
    
        for(int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, factor_temp.id_name) == 0) {
                if(strcmp(global_sts[i].datatype_name, "bool") != 0) {
                    fprintf(stderr, "while variable doesnt have boolean datatype : at line %d\n", line_no);
                    sem_err_check = 1;
                    while_active = 0;
                    return;
                }
            }
        }

    }

    if(in_fun == 1) {
        for(int i = 0; i< 20; i++) {
            if(strcmp(function_sts[i].id_name, word) == 0) {
                copyIntoFactorfromIdentifier(word, function_sts[i].datatype_name);
                return;
            }
        }
    }
    //checking in global
        for(int i = 0; i< 20; i++) {
            if(strcmp(global_sts[i].id_name, word) == 0) {
                copyIntoFactorfromIdentifier(word, global_sts[i].datatype_name);
                return;
            }
        }

        //If not found then throwin an error
        fprintf(stderr, "Identifier %s undeclared before use\n", word);
        strcpy(factor_temp.datatype_name,"nothing");
        strcpy(factor_temp.id_name,word);
        sem_err_check = 1;

    

    if(while_active == 3) {
    if(in_fun == 1) {
        //Inside the function then
        for(int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, factor_temp.id_name) == 0) {
                if(strcmp(function_sts[i].datatype_name, "int") != 0) {
                    fprintf(stderr, "while variable doesnt have int datatype : at line %d\n", line_no);
                    sem_err_check = 1;
                    while_active = 0;
                    return;
                }
                
                }
            }
        }
    
        for(int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, factor_temp.id_name) == 0) {
                if(strcmp(global_sts[i].datatype_name, "int") != 0) {
                    fprintf(stderr, "while variable doesnt have int datatype : at line %d\n", line_no);
                    sem_err_check = 1;
                    while_active = 0;
                    return;
                }
            }
        }

    }

}

void checkIDreturn(char *word) {
    //Searching for the function in global
    for(int i = 0; i < 20; i++) {
        if(strcmp(global_sts[i].id_name, word) == 0) {
            return;
        }
    }
    fprintf(stderr, "This identifier/function doesn't exist: at line %d\n", line_no);
    sem_err_check = 1;
    return;
}

void addIDasINT(char *word) {
    for(int i = 0; i < 20; i++) {
        if(strcmp(function_sts[i].datatype_name, "") == 0) {
            strcpy(function_sts[i].datatype_name, "int");
            strcpy(function_sts[i].id_name, word);
            // printf("%s\n", function_sts[i].datatype_name);
            // printf("%s\n", function_sts[i].id_name);
            return;
        }
    }
    return;
}

void checkIfPrintisRight() {
    if(strcmp(expression_temp.datatype_name, "string") == 0) {
        return;
    }
    if(in_fun == 1) {
        //Inside the function then
        for(int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, expression_temp.id_name) == 0) {
                return;
                }
            }
        }
        for(int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, expression_temp.id_name) == 0) {
                return;
            }
        }

        fprintf(stderr, "print statement is printing out the variable that doesnt exist : at line %d\n", line_no);
        sem_err_check = 1;
}

void addFunInglobe(char *word) {
    for(int i = 0; i < 20; i++) {
        if(strcmp(global_sts[i].datatype_name, "") == 0) {
            strcpy(global_sts[i].datatype_name, "function");
            strcpy(global_sts[i].id_name, word);
            // printf("%s\n", function_sts[i].datatype_name);
            // printf("%s\n", fundction_sts[i].id_name);
            return;
        }
    }
    return;
}

void printing_symbol_table_global() {
printf("Symbol table starts here : ...................GLOBAL......................\n");
int k = 1;
    for(int i = 0; i < 20; i++) {
        if(strcmp(global_sts[i].datatype_name, "") != 0) {
            printf("Record : %d\n", k);
            printf("Datatype: %s\n", global_sts[i].datatype_name);
            printf("ID: %s\n", global_sts[i].id_name);
            printf("int_value: %d\n", global_sts[i].int_value);
            k++;
        }
    }
}

void copyIntoFactorfromString(char *word) {
    strcpy(factor_temp.string_value, word);
    strcpy(factor_temp.datatype_name, "string");
    return;
}

void copyIntoFactorfromTrue() {
    strcpy(factor_temp.datatype_name, "bool");
    factor_temp.bool_value = 1;
}

void copyIntoFactorfromFalse() {
    strcpy(factor_temp.datatype_name, "bool");
    factor_temp.bool_value = 0;
}

void copyIntoFactorfromInt(int j) {
    strcpy(factor_temp.datatype_name, "int");
    factor_temp.int_value = j;
    return;
}

void copyIntoFactorfromIdentifier(char *word, char *datatype) {
    strcpy(factor_temp.id_name, word);
    strcpy(factor_temp.datatype_name, datatype);
    return;
}

void copyTermfromFactor() {

    //printf("Copying term from factor : %s\n", factor_temp.datatype_name);

    strcpy(term_temp.string_value, factor_temp.string_value);
    strcpy(term_temp.datatype_name, factor_temp.datatype_name);
    strcpy(term_temp.id_name, factor_temp.id_name);
    term_temp.int_value = factor_temp.int_value;
    term_temp.bool_value = factor_temp.bool_value;
    
    //clearing factor
    strcpy(factor_temp.datatype_name, "");
    strcpy(factor_temp.function_name, "");
    strcpy(factor_temp.string_value, "");
    strcpy(factor_temp.id_name, "");
    factor_temp.int_value = 0;
    factor_temp.bool_value = 0;

}

void addIDinExpression(char *word) {
    strcpy(assignment_temp.datatype_name, expression_temp.datatype_name);
    strcpy(assignment_temp.string_value, expression_temp.string_value);
    assignment_temp.int_value = expression_temp.int_value;
    assignment_temp.bool_value = expression_temp.bool_value;
    strcpy(assignment_temp.id_name, word);
}

void copyExpfromTerm() {
    strcpy(exp_temp.string_value, term_temp.string_value);
    strcpy(exp_temp.datatype_name, term_temp.datatype_name);
    strcpy(exp_temp.id_name, term_temp.id_name);
    exp_temp.int_value = term_temp.int_value;
    exp_temp.bool_value = term_temp.bool_value;

    //clearing term
    // strcpy(term_temp.datatype_name, "");
    // strcpy(term_temp.function_name, "");
    // strcpy(term_temp.string_value, "");
    // strcpy(term_temp.id_name, "");
    // term_temp.int_value = 0;
    // term_temp.bool_value = 0;
}

void copyExpressionfromExp() {
    strcpy(expression_temp.string_value, exp_temp.string_value);
    strcpy(expression_temp.datatype_name, exp_temp.datatype_name);
    strcpy(expression_temp.id_name, exp_temp.id_name);
    expression_temp.int_value = exp_temp.int_value;
    expression_temp.bool_value = exp_temp.bool_value;

    //clearing exp
    strcpy(exp_temp.datatype_name, "");
    strcpy(exp_temp.function_name, "");
    strcpy(exp_temp.string_value, "");
    strcpy(exp_temp.id_name, "");
    exp_temp.int_value = 0;
    exp_temp.bool_value = 0;
}

void compAsst() {
    for(int i = 0; i < 20; i++) {
        //Checking in the function first
        if(strcmp(function_sts[i].id_name, assignment_temp.id_name) == 0) {
            //If it is present in the global, look for its datatype
            if(strcmp(function_sts[i].datatype_name, assignment_temp.datatype_name) == 0) {
                //if it matched then update the value
                strcpy(function_sts[i].string_value, assignment_temp.string_value);
                function_sts[i].int_value = assignment_temp.int_value;
                function_sts[i].bool_value = assignment_temp.bool_value;
                return;
            }
            else {
                fprintf(stderr, "Variable assigned with different value at line %d\n", line_no);
                sem_err_check = 1;
                return;
            }
        }
    }
    for(int i = 0; i < 20; i++) {
        //Checking in the global first
        if(strcmp(global_sts[i].id_name, assignment_temp.id_name) == 0) {
            //If it is present in the global, look for its datatype
            if(strcmp(global_sts[i].datatype_name, assignment_temp.datatype_name) == 0) {
                //if it matched then update the value
                strcpy(global_sts[i].string_value, assignment_temp.string_value);
                global_sts[i].int_value = assignment_temp.int_value;
                global_sts[i].bool_value = assignment_temp.bool_value;
                return;
            }
            else {
                fprintf(stderr, "Variable assigned with different value at line %d\n", line_no);
                sem_err_check = 1;
                return;
            }
        }
    }
    //Now adding the variable to the symbol_table
    if(in_fun == 1) {
        //Adding in function
        for(int j = 0; j < 20; j++) {
            if(strcmp(function_sts[j].datatype_name,"") == 0) {
                //Adding in function
                strcpy(function_sts[j].id_name, assignment_temp.id_name);
                strcpy(function_sts[j].datatype_name, assignment_temp.datatype_name);
                strcpy(function_sts[j].string_value, assignment_temp.string_value);
                function_sts[j].int_value = assignment_temp.int_value;
                function_sts[j].bool_value = assignment_temp.bool_value;
                return;
            }
        }
    }
    else {
        for(int j = 0; j < 20; j++) {
            if(strcmp(global_sts[j].datatype_name,"") == 0) {
                //Adding in function
                strcpy(global_sts[j].id_name, assignment_temp.id_name);
                strcpy(global_sts[j].datatype_name, assignment_temp.datatype_name);
                strcpy(global_sts[j].string_value, assignment_temp.string_value);
                global_sts[j].int_value = assignment_temp.int_value;
                global_sts[j].bool_value = assignment_temp.bool_value;
                return;
            }
        }
    }
}



void printing_symbol_table() {
    printf("Symbol table starts here : .................FUNCTION........................\n");
    int k = 1;
    for(int i = 0; i < 20; i++) {
        if(strcmp(function_sts[i].datatype_name, "") != 0) {
            printf("Record : %d\n", k);
            printf("Datatype: %s\n", function_sts[i].datatype_name);
            printf("ID: %s\n", function_sts[i].id_name);
            printf("int_value: %d\n", function_sts[i].int_value);
            k++;
        }
    }
}

int yyerror(){
   fprintf(stderr, syn_err_msg, line_no);
   exit(-1);
}
