#include "node.h"
#include "token.h"

int visit_BinNode(BinNode_t *node)
{
    switch (node->op.type) {
        case PLUS:
            return visit(node->left) + visit(node->right);
        case MINUS:
            return visit(node->left) - visit(node->right);
        case MULTIPLY:
            return visit(node->left) * visit(node->right);
        case DIVIDE:
            return visit(node->left) / visit(node->right);
        default:
            printf("node.c: Unavailable op type\n");
            exit(0);
    }
}

int visit_NumNode(NumNode_t *node)
{
    return node->operand.value;
}

int visit(void *node)
{
    if (((token_t *) node)->type == INTEGER)
        return visit_NumNode((NumNode_t *) node);
    
    return visit_BinNode((BinNode_t *) node);
}

void free_node(void *node)
{
    if (((token_t *) node)->type != INTEGER) {
        free_node(((BinNode_t *) node)->left);
        free_node(((BinNode_t *) node)->right);
    }
    free(node);
}
