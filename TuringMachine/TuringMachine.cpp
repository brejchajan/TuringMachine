//
//  TuringMachine.cpp
//  TuringMachine
//
//  Created by Jan Brejcha on 10.06.13.
//  Copyright (c) 2013 brejchajan. All rights reserved.
//

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
            cout << "This Turing Machine ended UNSUCCESSFULLY";
            break;
        }
        this->tape->printTape();
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