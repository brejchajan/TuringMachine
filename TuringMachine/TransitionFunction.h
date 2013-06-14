//
//  TransitionFunction.h
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


#ifndef __TuringMachine__TransitionFunction__
#define __TuringMachine__TransitionFunction__

#include <iostream>
#include "State.h"
#include <map>

using namespace std;

namespace brejchajan{
    
typedef struct triplet{
    State *state;
    char symbol;
    //'L' or 'R'
    char moveToSide;
    bool operator< (const triplet &other)const{
        return false;
    }
} Triplet;

typedef struct tuple{
public:
    State *state;
    char symbol;
    bool operator==(const tuple &t)const{
        if (this->state == t.state && this->symbol == t.symbol){
            return true;
        }
        return false;
    }
    bool operator!=(const tuple &t)const{
        return !(*this == t);
    }
    
    bool operator< (const tuple &other)const{
        if (this->state->nameID < other.state->nameID){
            return true;
        }
        else if (this->state->nameID > other.state->nameID){
            return false;
        }
        else{
            return (this->symbol < other.symbol);
        }
    }
    
} Tuple;

class TransitionFunction{
public:
    Triplet * evaluate(State *s, char symbol);
    void addConfiguration(State *fromS, char fromSymbol, State *toState, char toSymbol, char moveToSide);
private:
    map<Tuple, Triplet> m;
};
}
#endif /* defined(__TuringMachine__TransitionFunction__) */
