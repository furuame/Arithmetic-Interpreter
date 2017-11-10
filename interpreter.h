#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <stdlib.h>
#include <stdio.h>
#include "token.h"

#define _AVAILABLE_DIGITS 100

typedef struct __interpreter interpreter;

struct __interpreter {
    int pos;
    int len;
    const char *text;
    char current_char;
    token current_token;

    int (*expr)(interpreter *thiz);
};

void interpreter_init(interpreter **thiz, const char *text);

#endif
