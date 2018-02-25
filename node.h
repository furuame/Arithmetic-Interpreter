#ifndef NODE_H_
#define NODE_H_

#include "token.h"

typedef struct __binary_operation_node BinNode_t;
struct __binary_operation_node {
    token_t op;
    void *left;
    void *right;
};

typedef struct __number_node NumNode_t;
struct __number_node {
    token_t operand;
};

int visit(void *node);
void free_node(void *node);

#endif
