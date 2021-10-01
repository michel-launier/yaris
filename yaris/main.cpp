//
//  main.cpp
//  yaris
//
//  Created by Michel Launier on 2021-09-26.
//

#include <iostream>

#include "EvolutionAlgorithm/Individual.hpp"
#include "EvolutionAlgorithm/EvolutionDelegate.hpp"
#include "EvolutionAlgorithm/AlgorithmConfig.hpp"
#include "EvolutionAlgorithm/EvolutionAlgorithm.hpp"

class TestIndividual : public Individual {
public:
    TestIndividual() { std::cout << "creating individual\n"; }
protected:
    void dipose() { std::cout << "disposing of individual\n"; delete this; }
};

class TestDelegate : public EvolutionDelegate {
    Individual*  createIndividual() const { return new TestIndividual; }
    void         releaseIndividual(Individual* i) { delete i; }
    float        evaluateIndividual(const Individual*) const { return 0.5f; }
    bool         isIndividualGoodEnough(const Individual* i) const { return i->fitnessScore > 0.95f; }
};

AlgorithmConfig testConfig(10,10);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    TestDelegate delegate;
    auto algo = EvolutionAlgorithm(&testConfig, &delegate);
    
    algo.run();
    
    return 0;
}
