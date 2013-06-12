//
//  TuringMachine.h
//  TuringMachine
//
//  Created by Jan Brejcha on 10.06.13.
//  Copyright (c) 2013 brejchajan. All rights reserved.
//

#ifndef __TuringMachine__TuringMachine__
#define __TuringMachine__TuringMachine__

#include <iostream>
#include <set>
#include "State.h"
#include "TransitionFunction.h"
#include "Tape.h"

using namespace std;

namespace brejchajan{
class TuringMachine{
public:
    TuringMachine(set<State> *states, set<char> *inputSymbols, set<char> *tapeSymbols, char blankSymbol, TransitionFunction *deltaFunction, State *initialState, set<State> *endStates);
    TuringMachine(char blankSymbol);
    ~TuringMachine();
    Tape *evaluate();
    void setInputWord(const char *word, int wordLength);
    void test();
    void testRight();
private:
    set<State> *states;
    set<char> *inputSymbols;
    set<char> *tapeSymbols;
    char blankSymbol;
    TransitionFunction *deltaFunction;
    State *initialState;
    set<State> *endStates;
    Tape *tape;
    State *currentState;
    bool deallocNeeded;
    
    void init(set<State> *states, set<char> *inputSymbols, set<char> *tapeSymbols, char blankSymbol, TransitionFunction *deltaFunction, State *initialState, set<State> *endStates);
    bool makeStep();
};
    
}

#endif /* defined(__TuringMachine__TuringMachine__) */
