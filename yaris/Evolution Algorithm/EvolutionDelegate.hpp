//
//  EvolutionDelegate.hpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#ifndef EvolutionDelegate_hpp
#define EvolutionDelegate_hpp

// Forward References
class Individual;

class EvolutionDelegate {
public:
    virtual Individual*  createIndividual() const = 0;
    virtual void         releaseIndividual(Individual*) = 0;
    virtual float        evaluateIndividual(const Individual*) const = 0;
    virtual bool         isIndividualGoodEnough(const Individual*) const = 0;
};

#endif /* EvolutionDelegate_hpp */
