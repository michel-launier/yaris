//
//  main.cpp
//  yaris
//
//  Created by Michel Launier on 2021-09-26.
//

#include <iostream>
#include "EvolutionAlgorithm/Mrc.hpp"

class TestObject : public Mrc {
public:
    void dispose() { std::cout << "Disposing the object" << std::endl; }
};

void fnc() {
    std::cout << "Creating object" << std::endl;
    MrcPtr<TestObject> p = new TestObject;
    std::cout << "Retention count = " << p->getRetainCount() << std::endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    // Test Mrc pointer
    fnc();
    
    return 0;
}
