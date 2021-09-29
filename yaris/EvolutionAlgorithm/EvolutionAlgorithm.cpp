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
EvolutionAlgorithm::EvolutionAlgorithm(const AlgorithmConfig* algorithmConfig,
                                       EvolutionDelegate* delegate)
    : bestIndividual(0)
{
    this->algorithmConfig = algorithmConfig;
    this->myDelegate      = delegate;
    
    // Create storage for population
    generationA.resize(algorithmConfig->populationSize);
    generationB.resize(algorithmConfig->populationSize);
    currentGeneration = &generationA;
    nextGeneration    = &generationB;
}

// ------------------------------------------------------------------------
/// Release objects allocated by this algorithm run.
///
EvolutionAlgorithm::~EvolutionAlgorithm() {}

// ------------------------------------------------------------------------
/// Run the evolution algorithm and extract the best individual.
///
Individual* EvolutionAlgorithm::run() {
    // Create initial population.
    createInitialPopulation();
    bestIndividual = evaluatePopulation();
    
    // Iterate generation new generations of the population.
    auto maxGeneration = algorithmConfig->maxGeneration;
    for(unsigned i = 0; i < maxGeneration; ++i) {
        // Stop if we found an individual that satisfies the goal
        if(myDelegate->isIndividualGoodEnough(bestIndividual)) break;
        // Create a new generation
        evolvePopulation();
        // Evaluate the new generation of individuals
        auto bestOfGeneration = evaluatePopulation();
        if( bestOfGeneration->fitnessScore > bestIndividual->fitnessScore) {
            bestIndividual = bestOfGeneration;
        }
    }

    // Return the best individual of the run.
    return bestIndividual;
}

// ------------------------------------------------------------------------
/// Create an initial population.
void EvolutionAlgorithm::createInitialPopulation() {
    // Create the initial population
    auto populationSize = currentGeneration->size();
    for( unsigned i = 0; i < populationSize; ++i) {
        (*currentGeneration)[i] = myDelegate->createIndividual();
    }
}

// ------------------------------------------------------------------------
/// Evaluate the fitness score for each individual in the population.
///
Individual* EvolutionAlgorithm::evaluatePopulation() {
    Individual* best = 0;
    auto iter = currentGeneration->begin();
    auto end  = currentGeneration->end();
    for(; iter != end; ++iter) {
        Individual* individual = *iter;
        if( individual != 0 ) {
            individual->fitnessScore = myDelegate->evaluateIndividual(individual);
            if( best == 0 || individual->fitnessScore > best->fitnessScore) {
                best = individual;
            }
        }
    }
    return best;
}

// ------------------------------------------------------------------------
// Destroy and release memory for all individuals in the given population.
void EvolutionAlgorithm::emptyPopulation() {
}
 
// ------------------------------------------------------------------------
/// Add the given evolution operator to the pool of operators.
///
void EvolutionAlgorithm::addOperator(EvolutionOperator* theOperator) {
    myOperators.push_back(theOperator);
}

// ------------------------------------------------------------------------
/// Creates a new generation of the population.
///
void EvolutionAlgorithm::evolvePopulation() {
    // Use evolution operators to create new individuals.
    
    // Avoid duplicate individuals.
    
    // Make newly created population the current generation.
    auto previousdGeneration = currentGeneration;
    currentGeneration = nextGeneration;
    nextGeneration = previousdGeneration;
    
    // Release the individuals of the previoud generation.
    auto iter = previousdGeneration->begin();
    auto end  = previousdGeneration->end();
    for (; iter != end; ++iter) {
        (*iter) = 0;
    }
}
