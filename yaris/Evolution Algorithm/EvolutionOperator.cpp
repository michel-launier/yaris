//
//  EvolutionOperator.cpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-23.
//

#include "EvolutionOperator.hpp"

// ---------------------------------------------------------------------------
/// Initialise the evolution operator with the selection criteria
///
/// @param selectionProbability     The probability that this evolution operator is selected
/// @param nbOfIndividualsNeeded   The number of individuals needed for the operator
///
EvolutionOperator::EvolutionOperator(float selectionProbability, unsigned nbOfIndividualsNeeded) {
    this->selectionProbability  = selectionProbability;
    this->nbOfIndividualsNeeded = nbOfIndividualsNeeded;
}
