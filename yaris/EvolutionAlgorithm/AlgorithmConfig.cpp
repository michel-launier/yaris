//
//  AlgorithmConfig.cpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#include "AlgorithmConfig.hpp"

AlgorithmConfig::AlgorithmConfig(unsigned populationSize,
                                 unsigned maxGeneration,
                                 float selectionRatio) {
    this->maxGeneration  = maxGeneration;
    this->populationSize = populationSize;
    this->selectionSize  = selectionRatio * populationSize;
}
