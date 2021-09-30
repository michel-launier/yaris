//
//  Prelude.hpp
//  yaris
//
//  Created by Michel Launier on 2021-09-29.
//

#ifndef Prelude_hpp
#define Prelude_hpp

#include <vector>

namespace Prelude {

// ---------------------------------------------------------------------------
/// Implements a high-order for each functionality on vectors.
///
template <typename T, typename Predicate>
void forEach(const std::vector<T>& vec, Predicate p, void (f)(T&)) {
    auto iter = vec.begin();
    auto end  = vec.end();
    for (; iter != end; ++iter) {
        f (*iter);
    }
}

} /* Prelude */

#endif /* Prelude_hpp */
