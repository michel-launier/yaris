//
//  EvolutionAlgorithm.cpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#include "EvolutionAlgorithm.hpp"
#include "AlgorithmConfig.hpp"
#include "Individual.hpp"
#include "EvolutionDelegate.hpp"
#include "EvolutionOperator.hpp"

// ------------------------------------------------------------------------
EvolutionAlgorithm::EvolutionAlgorithm(const AlgorithmConfig* iterationConfig,
                                       EvolutionDelegate* delegate)
{
    this->iterationConfig = iterationConfig;
    this->myDelegate      = delegate;
    
    // Initialise properties
    currentGeneration = &generationA;
    nextGeneration    = &generationB;
}

// ------------------------------------------------------------------------
EvolutionAlgorithm::~EvolutionAlgorithm() {
    // Release population memory.

}

// ------------------------------------------------------------------------
// Perform the Genetic Algorithm search
Individual* EvolutionAlgorithm::performSearch() {
    // Create initial population.
    createPopulation();
    auto bestIndividual = evaluatePopulation();
    
    // Iterate generation new generations of the population.
    for(unsigned i =0; i < iterationConfig->nbOfIterations; ++i) {
        if(myDelegate->isIndividualGoodEnough(bestIndividual)) break;
        evolvePopulation();
        auto bestOfGeneration = evaluatePopulation();
        if( bestOfGeneration->fitnessScore > bestIndividual->fitnessScore) {
            bestIndividual = bestOfGeneration;
        }
    }

    return bestIndividual;
}

// ------------------------------------------------------------------------
// Create an initial population with newly created individuals.
void EvolutionAlgorithm::createPopulation() {
    // Allocate storage for populations
    unsigned populationSize = iterationConfig->populationSize;
    if(population == 0) population = new Population();
    population->resize(populationSize);
    
    // Remove existing individuals in the populations
    emptyPopulation();
    
    // Create the initial population
    for( unsigned i = 0; i < populationSize; ++i) {
        (*population)[i] = myDelegate->createIndividual();
    }
}

// ------------------------------------------------------------------------
// Evaluate the fitness score for each individual in the population.
Individual* EvolutionAlgorithm::evaluatePopulation() {
    Individual* best = 0;
    auto end = currentGeneration->end();
    for(auto iter = currentGeneration->begin(); iter != end; ++iter) {
        if(*iter != 0) {
            (*iter)->fitnessScore = myDelegate->evaluateIndividual(*iter);
            if( best == 0 || (*iter)->fitnessScore > best->fitnessScore) {
                best = *iter;
            }
        }
    }
    return best;
}

// ------------------------------------------------------------------------
// Destroy and release memory for all individuals in the given population.
void EvolutionAlgorithm::emptyPopulation() {
    // Deallocate all remaining individuals
    auto end = population->end();
    for(auto iter = population->begin(); iter != end; ++iter) {
        if(*iter != 0) {
            myDelegate->returnIndividual(*iter);
            *iter = 0;
        }
    }
}
 
// ------------------------------------------------------------------------
void EvolutionAlgorithm::addOperator(EvolutionOperator* theOperator) {
    myOperators.push_back(theOperator);
}

// ------------------------------------------------------------------------
// Creates a new generation of the population.
void EvolutionAlgorithm::evolvePopulation() {
}
