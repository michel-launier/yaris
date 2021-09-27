//
//  AlgorithmConfig.cpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#include "AlgorithmConfig.hpp"

AlgorithmConfig::AlgorithmConfig(unsigned populationSize,
                                 unsigned nbOfIterations,
                                 float selectionRatio) {
    this->nbOfIterations = nbOfIterations;
    this->populationSize = populationSize;
    this->selectionSize  = selectionRatio * populationSize;
}
