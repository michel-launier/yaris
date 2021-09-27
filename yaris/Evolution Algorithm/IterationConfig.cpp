//
//  IterationConfig.cpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#include "IterationConfig.hpp"

IterationConfig::IterationConfig(unsigned populationSize,
                                 unsigned nbOfIterations,
                                 float selectionRatio) {
    this->nbOfIterations = nbOfIterations;
    this->populationSize = populationSize;
    this->selectionSize  = selectionRatio * populationSize;
}
