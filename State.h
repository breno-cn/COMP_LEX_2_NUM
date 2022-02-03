//
// Created by breno on 2/2/22.
//

#ifndef COMP_LEX_2_NUM_STATE_H
#define COMP_LEX_2_NUM_STATE_H

typedef enum {
    Initial, ReadDigits, ReadDot, ReadE, AcceptNumber, AcceptFraction, AcceptReal
} State;

int State_isFinalState(State state);

#endif //COMP_LEX_2_NUM_STATE_H
