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
struct EvolutionConfig;
class  EvolutionDelegate;
class  Individual;

class EvolutionAlgorithm {
    // Genetic Programming configuration
    const IterationConfig*     iterationConfig;
    const EvolutionConfig*     evolutionConfig;
          EvolutionDelegate* delegate;
    
    // Population related storage
    typedef std::vector<Individual*>    Population;
    Population*  population;

public:
    EvolutionAlgorithm(const IterationConfig*, const EvolutionConfig*, EvolutionDelegate*);
    ~EvolutionAlgorithm();
    
    Individual* performSearch();

protected:
    void createPopulation();
    Individual* evaluatePopulation();
    void emptyPopulation();
    void evolvePopulation();
};

#endif /* EvolutionAlgorithm_h */
