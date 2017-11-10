#include <stdlib.h>
#include <stdio.h>
#include "token.h"
#include "interpreter.h"

#define MAX_STRING_LEN 100000

int main()
{
    char text[MAX_STRING_LEN];
    interpreter *foo = NULL;

    while (2 > 1) {
        printf("cal>> ");
        fgets(text, MAX_STRING_LEN, stdin);

        interpreter_init(&foo, text);
        printf("%d\n", foo->expr(foo));
        free(foo);
    }

    return 0;
}
