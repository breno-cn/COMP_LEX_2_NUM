//
// Created by breno on 2/2/22.
//

#include "Token.h"

#include "State.h"
#include "utils.h"

Token *Token_newNumber(int number) {
    Token *token = malloc(sizeof(Token));

    if (token) {
        token->type = Number;
        token->number = number;
    }

    return token;
}

Token *Token_newFraction(int numerator, int denominator) {
    Token *token = malloc(sizeof(Token));

    if (token) {
        token->type = Fraction;
        token->fraction.numerator = numerator;
        token->fraction.denominator = denominator;
    }

    return token;
}

Token *Token_newReal(double real) {
    Token *token = malloc(sizeof(Token));

    if (token) {
        token->type = Real;
        token->real = real;
    }

    return token;
}

Token *Token_new(TokenType type) {
    Token *token = malloc(sizeof(Token));

    if (token) {
        token->type = type;
    }

    return token;
}

Token *Tokenizer_getNextToken(char *lexem) {
    int i = 0;
    char currentChar;
    int currentState = 1;

    while (1) {
        currentChar = lexem[i++];

        switch (currentState) {
            case 1:
                if (isDigit(currentChar))
                    currentState = 2;
                break;

            case 2:
                if (isDigit(currentChar))
                    currentState = 2;
                else if (currentChar == '.')
                    currentState = 4;
                else if (currentChar == 'E')
                    currentState = 7;
                else if (currentChar == '\0')
                    currentState = 3;
                break;

            case 4:
                if (isDigit(currentChar))
                    currentState = 5;

                break;

            case 5:
                if (isDigit(currentChar))
                    currentState = 5;
                else if (currentChar == '+' || currentChar == '-')
                    currentState = 8;
                else if (currentChar == 'E')
                    currentState = 7;
                else if (currentChar == '\0')
                    currentState = 6;
                break;

            case 7:
                if (currentChar == '+' || currentChar == '-')
                    currentState = 8;
                break;

            case 8:
                if (isDigit(currentChar))
                    currentState = 9;
                break;

            case 9:
                if (isDigit(currentChar))
                    currentState = 9;
                else if (currentChar == '\0')
                    currentState = 10;
                break;
        }

        if (currentState == 3 || currentState == 6 || currentState == 10)
            break;
    }

    switch (currentState) {
        case 3:
            return Token_new(Number);

        case 6:
            return Token_new(Fraction);

        case 10:
            return Token_new(Real);
    }
}

//Token *Tokenizer_getNextToken(Tokenizer *tokenizer, char *lexem) {
//    int currentIndex = 0;
//    char currentChar;
//
//    while (!State_isFinalState(tokenizer->currentState)) {
//        currentChar = lexem[currentIndex++];
//
//        switch (tokenizer->currentState) {
//            case Initial:
//                if (isDigit(currentChar)) {
//                    tokenizer->currentState = ReadDigits;
//                }
//
//                break;
//
//            case ReadDigits:
//                if (isDigit(currentChar))
//                    tokenizer->currentState = ReadDigits;
//                else if (currentChar == '.') {
//                    tokenizer->currentState = ReadDot;
//                } else if (currentChar == '\0') {
//                    tokenizer->currentState = AcceptNumber;
//                }
//
//                break;
//
//            case ReadDot:
//                if (isDigit(currentChar))
//                    tokenizer->currentState = ReadDigits;
//        }
//    }
//}

char *Token_toString(Token *token) {
    if (token->type == Number)
        return "NUMBER";

    if (token->type == Fraction)
        return "FRACTION";

    if (token->type == Real)
        return "REAL";

    return "THIS REALLY SHOULD NOT HAPPEN!";
}
