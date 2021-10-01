//
//  Individual.hpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#ifndef Individual_hpp
#define Individual_hpp

#include "../Common/Mrc.hpp"

class Individual : public Mrc {
public:
    float fitnessScore;
    
    Individual();
};

#endif /* Individual_hpp */
