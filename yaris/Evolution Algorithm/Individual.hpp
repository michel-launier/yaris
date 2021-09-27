//
//  Individual.hpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#ifndef Individual_hpp
#define Individual_hpp

class Individual {
public:
    float fitnessScore;
    
    Individual();
    virtual ~Individual() = 0;  // Allow delete from subclass
};

#endif /* Individual_hpp */
