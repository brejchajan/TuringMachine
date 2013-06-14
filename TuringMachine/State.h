//
//  State.h
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
