//
//  EvolutionConfig.hpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#ifndef EvolutionConfig_hpp
#define EvolutionConfig_hpp


struct EvolutionConfig {
    float    crossoverProbability;
    float    mutationProbability;
    float    reproductionProbability;
    float    architectureAlteringProbability;

    EvolutionConfig();
};

#endif /* EvolutionConfig_hpp */
