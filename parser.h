#ifndef PARSER_H_
#define PARSER_H_

#include "token.h"
#include "lexer.h"
#include "node.h"

typedef struct __parser Parser;

struct __parser {
    Lexer *lexer;
};

Parser *parser_init(const char *text);

/* Return address of the root*/
void *parse(Parser *parser);

#endif
