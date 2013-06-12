//
//  Tape.h
//  TuringMachine
//
//  Created by Jan Brejcha on 10.06.13.
//  Copyright (c) 2013 brejchajan. All rights reserved.
//

#ifndef __TuringMachine__Tape__
#define __TuringMachine__Tape__
#define DEFAULT_SIZE 5

#include <iostream>
namespace brejchajan{
class Tape{
public:
    Tape(char blankSymbol);
    ~Tape();
    char readSymbol();
    void writeSymbol(char symbol);
    void moveLeft();
    void moveRight();
    void printTape();
    void setInputWord(const char *word, int wordLength);
    
private:
    char blankSymbol;
    char *tape;
    long position;
    long currentSize;
    void reallocate();
};
}
#endif /* defined(__TuringMachine__Tape__) */
