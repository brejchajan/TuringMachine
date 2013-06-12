//
//  TransitionFunction.cpp
//  TuringMachine
//
//  Created by Jan Brejcha on 10.06.13.
//  Copyright (c) 2013 brejchajan. All rights reserved.
//

#include "TransitionFunction.h"
using namespace brejchajan;
using namespace std;

void TransitionFunction::addConfiguration(State *fromState, char fromSymbol, State *toState, char toSymbol, char moveToSide){
    if (moveToSide != 'L' && moveToSide != 'R'){
        throw new exception;
    }
    Triplet to;
    to.state = toState;
    to.symbol = toSymbol;
    to.moveToSide = moveToSide;
    Tuple from;
    from.state = fromState;
    from.symbol = fromSymbol;
    if (m.find(from) != m.end()){
        throw new exception;//no duplicates allowed
    }
    m[from] = to;
}

Triplet * TransitionFunction::evaluate(State *s, char symbol){
    Tuple from;
    from.state = s;
    from.symbol = symbol;
    if (m.find(from) != m.end()){
        return &(m[from]);
    }
    return NULL;
}