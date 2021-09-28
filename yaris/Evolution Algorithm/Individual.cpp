//
//  Individual.cpp
//  genetic-programming
//
//  Created by Michel Launier on 2021-09-08.
//

#include "Individual.hpp"

// ---------------------------------------------------------------------------
/// Create an individual with a retention count of 1.
Individual::Individual() {
    retainCnt = 1;
    fitnessScore = 0.0;
}

// ---------------------------------------------------------------------------
/// Decrease the retention count and destroy the individual if no longer in use.
///
void Individual::release() {
    if (--retainCnt <= 0) {
        delete this;
    }
}
