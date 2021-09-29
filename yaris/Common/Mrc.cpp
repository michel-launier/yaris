//
//  Mrc.cpp
//  yaris
//
//  Created by Michel Launier on 2021-09-28.
//

#include "Mrc.hpp"

// ---------------------------------------------------------------------------
/// Creation & destruction of the MRC pointer
///
_MrcPtr::_MrcPtr(Mrc* p) { if (p != 0)   p->retain(); ptr = p; }
_MrcPtr::~_MrcPtr()      { if (ptr != 0) ptr->release(); }

// ---------------------------------------------------------------------------
/// Reassignment of the MRC pointer.
///
Mrc* _MrcPtr::assign(Mrc* p) {
    if (p != ptr) {
        if (p != 0)     p->retain();
        if (ptr != 0)   ptr->release();
        ptr = p;
    }
    return ptr;
}

// ---------------------------------------------------------------------------
/// Reassignment of the MRC pointer.
///
Mrc* _MrcPtr::assign(_MrcPtr p) {
    if (p.ptr != ptr) {
        if (p.ptr != 0) p.ptr->retain();
        if (ptr != 0)   ptr->release();
        ptr = p.ptr;
    }
    return ptr;
}
