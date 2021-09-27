//
//  EvolutionConfig.cpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#include "EvolutionConfig.hpp"

EvolutionConfig::EvolutionConfig() {
    this->crossoverProbability            = 0.90;
    this->mutationProbability             = 0.01;
    this->reproductionProbability         = 0.09;
    this->architectureAlteringProbability = 0.00;
}
