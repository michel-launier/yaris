//
//  IterationConfig.hpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#ifndef IterationConfig_hpp
#define IterationConfig_hpp

struct IterationConfig {
    unsigned nbOfIterations;
    unsigned populationSize;
    unsigned selectionSize;

    IterationConfig(unsigned populationSize, unsigned nbOfIterations, float selectionRatio = 0.1);
};


#endif /* IterationConfig_hpp */
