#include "interpreter.h"
#include <string.h>

Interpreter *interpreter_init(const char *text)
{
    Interpreter *interpreter = (Interpreter *) malloc(sizeof(Interpreter));
    if (!interpreter) {
        printf("interpreter.c: No availabe memory for use\n");
        exit(0);
    }

    interpreter->parser = parser_init(text);

    return interpreter;
}

int interprete(Interpreter *interpreter)
{
    void *AST = parse(interpreter->parser);
    return visit(AST); 
}
