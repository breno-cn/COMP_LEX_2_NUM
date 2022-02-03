//
// Created by breno on 2/2/22.
//

#ifndef COMP_LEX_2_NUM_TOKEN_H
#define COMP_LEX_2_NUM_TOKEN_H

#include <stdlib.h>

#include "State.h"

typedef enum {
    Number, Fraction, Real
} TokenType;

typedef struct {
    TokenType type;
    union {
        int number;

        struct {
            int numerator;
            int denominator;
        } fraction;

        double real;
    };
} Token;

typedef struct {
    State currentState;
} Tokenizer;

Token *Token_newNumber(int number);
Token *Token_newFraction(int numerator, int denominator);
Token *Token_newReal(double real);
Token *Token_new(TokenType type);
//Token *Tokenizer_getNextToken(Tokenizer tokenizer, char *lexem);
Token *Tokenizer_getNextToken(char *lexem);
char *Token_toString(Token *token);

#endif //COMP_LEX_2_NUM_TOKEN_H
