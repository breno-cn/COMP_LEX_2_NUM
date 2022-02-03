//
// Created by breno on 2/2/22.
//

#include "State.h"

int State_isFinalState(State state) {
    return state == AcceptNumber || state == AcceptFraction || state == AcceptReal;
}
