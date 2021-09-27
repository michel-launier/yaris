//
//  EvolutionAlgorithm.h
//  genetic-programming
//
//  Created by Michel Launier on 2021-08-24.
//

#ifndef EvolutionAlgorithm_h
#define EvolutionAlgorithm_h

#include <vector>

// Forward References
struct IterationConfig;
class  EvolutionDelegate;
class  Individual;
class  EvolutionOperator;

class EvolutionAlgorithm {
    // Genetic Programming configuration
    EvolutionDelegate* myDelegate;
    
    const IterationConfig*     iterationConfig;
    
    typedef std::vector<EvolutionOperator*>  Operators;
    Operators myOperators;
    
    // Population related storage
    typedef std::vector<Individual*>    Population;
    Population*  population;

public:
    EvolutionAlgorithm(const IterationConfig*, EvolutionDelegate*);
    ~EvolutionAlgorithm();
    
    Individual* performSearch();
    
    void addOperator(EvolutionOperator*);

protected:
    void createPopulation();
    Individual* evaluatePopulation();
    void emptyPopulation();
    void evolvePopulation();
};

#endif /* EvolutionAlgorithm_h */
