//
//  Mrc.cpp
//  yaris
//
//  Created by Michel Launier on 2021-09-28.
//

#include "Mrc.hpp"

_MrcPtr::_MrcPtr(Mrc* p) { if (p != 0)   p->retain(); ptr = p; }
_MrcPtr::~_MrcPtr()      { if (ptr != 0) ptr->release(); }

Mrc* _MrcPtr::assign(Mrc* p) {
    if (p != ptr) {
        if (p != 0)     p->retain();
        if (ptr != 0)   ptr->release();
    }
    return ptr;
}
