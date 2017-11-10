#ifndef TOKEN_H_
#define TOKEN_H_

#include <stdlib.h>
#include <stdio.h>

typedef enum {
    INTEGER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    NONE
} TYPE;

typedef struct __token token;

struct __token {
    TYPE type;
    int value;
};

#endif
