#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <stdlib.h>
#include <stdio.h>
#include "token.h"
#include "lexer.h"
#include "node.h"
#include "parser.h"

typedef struct __interpreter Interpreter;

struct __interpreter {
    Parser *parser;    
};

Interpreter *interpreter_init(const char *text);
int interprete(Interpreter *interpreter);

#endif
