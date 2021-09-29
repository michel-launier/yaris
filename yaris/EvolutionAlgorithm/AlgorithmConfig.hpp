//
//  AlgorithmConfig.hpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#ifndef AlgorithmConfig_hpp
#define AlgorithmConfig_hpp

class AlgorithmConfig {
public:
    unsigned maxGeneration;
    unsigned populationSize;
    unsigned selectionSize;

    AlgorithmConfig(unsigned populationSize, unsigned maxGeneration, float selectionRatio = 0.1);
};


#endif /* AlgorithmConfig_hpp */
