//
//  main.cpp
//  TuringMachine
//
//  Created by Jan Brejcha on 10.06.13.
//  Copyright (c) 2013 brejchajan. All rights reserved.
//

#include <iostream>
#include "TuringMachine.h"
#include <set>
#include "State.h"
#include "TransitionFunction.h"

using namespace brejchajan;
int main(int argc, const char * argv[])
{
    
    set<State> *states = new set<State>();
    set<char> *inputSymbols = new set<char>();
    set<char> *tapeSymbols = new set<char>();
    TransitionFunction *deltaF = new TransitionFunction();
    set<State> *endStates = new set<State>();
    
    inputSymbols->insert('1');
    inputSymbols->insert('0');
    tapeSymbols->insert('1');
    tapeSymbols->insert('0');
    tapeSymbols->insert('B');
    
    
    //states
    State *q0 = new State("q0");
    State *qr = new State("qr");
    State *qc = new State("qc");
    State *qc1 = new State("qc1");
    State *qc0 = new State("qc0");
    State *qd1 = new State("qd1");
    State *qd0 = new State("qd0");
    State *ql = new State("ql");
    State *qf = new State("qf");
    
    states->insert(*q0);
    states->insert(*qr);
    states->insert(*qc);
    states->insert(*qc1);
    states->insert(*qc0);
    states->insert(*qd1);
    states->insert(*qd0);
    states->insert(*ql);
    states->insert(*qf);
    
    endStates->insert(*qf);
    
    //function
    //q0
    deltaF->addConfiguration(q0, '1', qr, '1', 'R');
    deltaF->addConfiguration(q0, '0', qr, '0', 'R');
    deltaF->addConfiguration(q0, 'B', qf, 'B', 'R');
    
    //qr
    deltaF->addConfiguration(qr, '1', qr, '1', 'R');
    deltaF->addConfiguration(qr, '0', qr, '0', 'R');
    deltaF->addConfiguration(qr, 'B', qc, 'B', 'L');
    
    //qc
    deltaF->addConfiguration(qc, '1', qc1, 'B', 'R');
    deltaF->addConfiguration(qc, '0', qc0, 'B', 'R');
    deltaF->addConfiguration(qc, 'B', qf, 'B', 'R');
    
    //qc1
    deltaF->addConfiguration(qc1, 'B', qd1, '1', 'R');
    
    //qc0
    deltaF->addConfiguration(qc0, 'B', qd0, '0', 'R');
    
    //qd1
    deltaF->addConfiguration(qd1, '1', qd1, '1', 'R');
    deltaF->addConfiguration(qd1, '0', qd1, '0', 'R');
    deltaF->addConfiguration(qd1, 'B', ql, '1', 'L');
    
    //qd0
    deltaF->addConfiguration(qd0, '1', qd0, '1', 'R');
    deltaF->addConfiguration(qd0, '0', qd0, '0', 'R');
    deltaF->addConfiguration(qd0, 'B', ql, '0', 'L');
    
    //ql
    deltaF->addConfiguration(ql, '1', ql, '1', 'L');
    deltaF->addConfiguration(ql, '0', ql, '0', 'L');
    deltaF->addConfiguration(ql, 'B', qc, 'B', 'L');
    
    
    
    TuringMachine *tm = new TuringMachine(states, inputSymbols, tapeSymbols, 'B', deltaF, q0, endStates);
    tm->setInputWord("000111", 6);
    Tape *finalTape = tm->evaluate();
    
    if (finalTape != NULL){
        cout << "This TM ended SUCCESSFULLY." << endl;
        finalTape->printTape();
    }
    else{
        cout << "This TM ended UNSUCCESSFULLY" << endl;
    }
    
    finalTape->printTape();
    
    
    delete tm;
    
    return 0;
}

