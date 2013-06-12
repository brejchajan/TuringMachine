//
//  Tape.cpp
//  TuringMachine
//
//  Created by Jan Brejcha on 10.06.13.
//  Copyright (c) 2013 brejchajan. All rights reserved.
//
#include <iostream>
#include "Tape.h"
#include <memory.h>
#include <exception>

using namespace brejchajan;

Tape::Tape(char blankSymbol){
    this->blankSymbol = blankSymbol;
    tape = new char[DEFAULT_SIZE];
    //set blanks to the new tape
    memset(tape, blankSymbol, DEFAULT_SIZE);
    position = DEFAULT_SIZE/2;
    currentSize = DEFAULT_SIZE;
}

void Tape::moveLeft(){
    if (position == 0){
        //need to reallocate the tape because there is no more space on the left side
        this->reallocate();
    }
    position--;
}

void Tape::moveRight(){
    if (position == currentSize - 1){
        this->reallocate();
    }
    position++;
}

char Tape::readSymbol(){
    char res = tape[position];
    return res;
}

void Tape::writeSymbol(char symbol){
    tape[position] = symbol;
}

void Tape::reallocate(){
    long newSize = 3*currentSize;
    if (newSize < currentSize || newSize != 3*currentSize){
        //the count of symbols is too big
        throw new std::out_of_range("the count of symbols on the tape is too big");
    }
    char *newTape = new char[newSize];
    //set blanks to the new tape
    memset(newTape, blankSymbol, newSize);
    //memcpy old to new
    std::copy(tape, tape + currentSize, newTape + currentSize);
    //update position on the tape
    position += currentSize;
    //delete old tape
    delete [] tape;
    //use new tape
    tape = newTape;
    //update current size of the tape
    currentSize = newSize;
}

void Tape::printTape(){
    for (int i = 0; i < currentSize; i++){
        std::cout << tape[i];
        if (i == position){
            std::cout << "*";
        }
        std::cout << ", ";
    }
    std::cout << "\n\n";
}

void Tape::setInputWord(const char *word, int wordLength){
    while (currentSize < 2*wordLength){
        this->reallocate();
    }
    printTape();
    for (int i = 0; i < wordLength; i++){
        tape[position + i] = word[i];
        printTape();
    }
}

Tape::~Tape(){
    delete tape;
}