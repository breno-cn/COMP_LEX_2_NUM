#include <stdio.h>
#include <stdlib.h>

#include "Token.h"

int main() {
    printf("Hello, World!\n");

    Token *token = Tokenizer_getNextToken("123");
    printf("Token: %s\n", Token_toString(token));
    free(token);

    token = Tokenizer_getNextToken("12.3");
    printf("Token: %s\n", Token_toString(token));
    free(token);

    token = Tokenizer_getNextToken("+123");
    printf("Token: %s\n", Token_toString(token));
    free(token);

    token = Tokenizer_getNextToken("-123");
    printf("Token: %s\n", Token_toString(token));
    free(token);

    token = Tokenizer_getNextToken("12E+34");
    printf("Token: %s\n", Token_toString(token));
    free(token);

    return 0;
}
