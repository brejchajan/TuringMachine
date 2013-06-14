//
//  TuringMachine.h
//  TuringMachine
//
//  Created by Jan Brejcha on 10.06.13.
//  Copyright (c) 2013 Jan Brejcha.
//

//  This file is part of TuringMachine.

//  TuringMachine is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.

//  TuringMachine is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with TuringMachine.  If not, see <http://www.gnu.org/licenses/>.


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
    void setPrintTapeEachStep(bool state);
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
    bool printTapeEachStep;
    void init(set<State> *states, set<char> *inputSymbols, set<char> *tapeSymbols, char blankSymbol, TransitionFunction *deltaFunction, State *initialState, set<State> *endStates);
    bool makeStep();
};
    
}

#endif /* defined(__TuringMachine__TuringMachine__) */
