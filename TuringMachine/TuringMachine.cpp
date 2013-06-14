//
//  TuringMachine.cpp
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

#include "TuringMachine.h"

using namespace brejchajan;
using namespace std;

TuringMachine::TuringMachine(set<State> *states, set<char> *inputSymbols, set<char> *tapeSymbols, char blankSymbol, TransitionFunction *deltaFunction, State *initialState, set<State> *endStates){
    deallocNeeded = false;
    init(states, inputSymbols, tapeSymbols, blankSymbol, deltaFunction, initialState, endStates);
}

TuringMachine::TuringMachine(char blankSymbol){
    set<State> *states = new set<State>();
    set<char> *inputSymbols = new set<char>();
    set<char> *tapeSymbols = new set<char>();
    TransitionFunction *deltaF = new TransitionFunction();
    State *initialState = new State("q0");
    set<State> *endStates = new set<State>();
    deallocNeeded = true;
    init(states, inputSymbols, tapeSymbols, blankSymbol, deltaF, initialState, endStates);
}

void TuringMachine::init(set<brejchajan::State> *states, set<char> *inputSymbols, set<char> *tapeSymbols, char blankSymbol, brejchajan::TransitionFunction *deltaFunction, brejchajan::State *initialState, set<brejchajan::State> *endStates){
    this->printTapeEachStep = false;
    this->states = states;
    this->inputSymbols = inputSymbols;
    this->tapeSymbols = tapeSymbols;
    this->blankSymbol = blankSymbol;
    this->deltaFunction = deltaFunction;
    this->initialState = initialState;
    this->endStates = endStates;
    this->tape = new Tape(blankSymbol);
    this->currentState = initialState;
}

TuringMachine::~TuringMachine(){
    if (deallocNeeded){
        delete states;
        delete inputSymbols;
        delete tapeSymbols;
        delete deltaFunction;
        delete initialState;
        delete endStates;
    }
}

void TuringMachine::setInputWord(const char *word, int wordLength){
    this->tape->setInputWord(word, wordLength);
}

Tape *TuringMachine::evaluate(){
    bool isFinal = endStates->find(*currentState) != endStates->end();
    while (!isFinal){
        bool res = this->makeStep();
        if (!res){
            return NULL;
        }
        if (this->printTapeEachStep){
            this->tape->printTape();
        }
        isFinal = endStates->find(*currentState) != endStates->end();
    }
    return tape;
}

bool TuringMachine::makeStep(){
    //obtain result of the step
    Triplet *result = deltaFunction->evaluate(currentState, tape->readSymbol());
    if (result == NULL){
        return false;
    }
    //write result to the tape
    tape->writeSymbol(result->symbol);
    //move to next position
    if (result->moveToSide == 'L'){
        tape->moveLeft();
    }
    else{
        tape->moveRight();
    }
    //update current state
    currentState = result->state;
    return true;
}

void TuringMachine::setPrintTapeEachStep(bool state){
    this->printTapeEachStep = state;
}

void TuringMachine::test(){
    for (int i = 0; i < 20; i++){
        tape->moveRight();
        tape->moveLeft();
        tape->writeSymbol('a');
        tape->printTape();
        tape->moveLeft();
    }
}

void TuringMachine::testRight(){
    for (int i = 0; i < 20; i++){
        tape->moveLeft();
        tape->moveRight();
        tape->writeSymbol('a');
        tape->printTape();
        tape->moveRight();
    }
}