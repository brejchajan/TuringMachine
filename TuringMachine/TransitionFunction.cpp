//
//  TransitionFunction.cpp
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