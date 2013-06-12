//
//  State.h
//  TuringMachine
//
//  Created by Jan Brejcha on 10.06.13.
//  Copyright (c) 2013 brejchajan. All rights reserved.
//

#ifndef __TuringMachine__State__
#define __TuringMachine__State__

#include <iostream>
#include <string>

namespace brejchajan {
class State{
public:
    State(std::string nameID);
    std::string getName();
    bool operator==(const State &other)const;
    bool operator!=(const State &other)const;
    bool operator< (const State &other)const;
    
    std::string nameID;
};
}


#endif /* defined(__TuringMachine__State__) */
