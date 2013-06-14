//
//  State.cpp
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


#include "State.h"

using namespace brejchajan;
using namespace std;

State::State(string nameID){
    this->nameID = nameID;
}

string State::getName(){
    return nameID;
}

bool State::operator==(const State &other)const{
    return (other.nameID == this->nameID);
}

bool State::operator!=(const State &other)const{
    return !(*this == other);
}

bool State::operator< (const State &other)const{
    return (this->nameID < other.nameID);
}



