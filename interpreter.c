#include "interpreter.h"
#include <string.h>

static int isDigit(char target)
{
    if (target >= '0' && target <= '9')
        return 1;
    return 0;
}

static void advance(interpreter *thiz)
{
    thiz->pos += 1;
    if (thiz->pos >= thiz->len) {
        thiz->current_char = '\n';
    } else {
        thiz->current_char = thiz->text[thiz->pos];
    }
}

static int integer(interpreter *thiz)
{
    char number[_AVAILABLE_DIGITS];
    int i = 0;

    do {
        number[i++] = thiz->current_char;
        advance(thiz);
    } while (thiz->current_char != '\n' && isDigit(thiz->current_char));
    number[i] = '\0';
    
    return atoi(number);
}

static void skip_whitespace(interpreter *thiz)
{
    do {
        advance(thiz);
    } while (thiz->current_char == ' ');
}

static token get_next_token(interpreter *thiz)
{
    token ret = {.type = NONE, .value = '\0'};

    if (thiz->current_char != '\n') {
        if (thiz->current_char == ' ')
            skip_whitespace(thiz);

        if (thiz->current_char == '\n')
            return ret;

        if (isDigit(thiz->current_char)) {
            ret.value = integer(thiz);
            ret.type = INTEGER;
            return ret;
        }

        if (thiz->current_char == '+') {
            ret.value = '+';
            ret.type = PLUS;
            advance(thiz);
            return ret;
        }

        if (thiz->current_char == '-') {
            ret.value = '-';
            ret.type = MINUS;
            advance(thiz);
            return ret;
        }

        if (thiz->current_char == '*') {
            ret.value = '*';
            ret.type = MULTIPLY;
            advance(thiz);
            return ret;
        }

        if (thiz->current_char == '/') {
            ret.value = '/';
            ret.type = DIVIDE;
            advance(thiz);
            return ret;
        }

        printf("interpreter.c: Unavailable char exists\n");
        exit(0);
    }
    return ret;
}

static void match(interpreter *thiz, TYPE type)
{
    if (thiz->current_token.type == type) {
        thiz->current_token = get_next_token(thiz);
    } else {
        printf("interpreter.c: Failed to match rules\n");
        exit(0);
    }
}

static int term(interpreter *thiz)
{
    int ret = thiz->current_token.value;
    match(thiz, INTEGER);
    return ret;
}

static int expr(interpreter *thiz)
{
    thiz->current_token = get_next_token(thiz);
    int result = 0;

    result += term(thiz);
    do {
        switch(thiz->current_token.type) {
            case PLUS:
                match(thiz, PLUS);
                result += term(thiz);
                break;
            case MINUS:
                match(thiz, MINUS);
                result -= term(thiz);
                break;
            case MULTIPLY:
                match(thiz, MULTIPLY);
                result *= term(thiz);
                break;
            case DIVIDE:
                match(thiz, DIVIDE);
                result /= term(thiz);
                break;
            default:
                printf("Unavailable string\n");
                exit(0);
        }
    } while (thiz->current_token.type != NONE);

    return result;
}

void interpreter_init(interpreter **thiz, const char *text)
{
    (*thiz) = (interpreter *) malloc(sizeof(interpreter));
    if (!(*thiz)) {
        printf("interpreter.c: No availabe memory for use\n");
        exit(0);
    }
    (*thiz)->pos = 0;
    (*thiz)->len = strlen(text);
    (*thiz)->text = text;
    (*thiz)->current_char = text[0];
    (*thiz)->expr = expr;
}

