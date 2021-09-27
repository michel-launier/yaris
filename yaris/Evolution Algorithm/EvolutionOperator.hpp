//
//  EvolutionOperator.hpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-23.
//

#ifndef EvolutionOperator_hpp
#define EvolutionOperator_hpp

#include <vector>

// Forward Declarations
class Individual;

class EvolutionOperator {
    float       selectionProbability;   ///< The probability that this operator is selected
    unsigned    nbOfIndividualsNeeded;  ///< Number of individual needed by the operator

public:
    EvolutionOperator(float selectionProbability, unsigned nbOfIndividualsNeeded);

    virtual Individual* createIndividual(std::vector<Individual*>) = 0;
};

#endif /* EvolutionOperator_hpp */
