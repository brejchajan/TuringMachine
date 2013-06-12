//
//  State.cpp
//  TuringMachine
//
//  Created by Jan Brejcha on 10.06.13.
//  Copyright (c) 2013 brejchajan. All rights reserved.
//

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



