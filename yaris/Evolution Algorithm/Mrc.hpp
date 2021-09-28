//
//  Mrc.hpp
//  yaris
//
//  Created by Michel Launier on 2021-09-28.
//

#ifndef Mrc_hpp
#define Mrc_hpp

// ---------------------------------------------------------------------------
/// Manual Reference Count
class Mrc {
    int retainCnt;
public:
    Mrc()           { retainCnt = 1; }
    virtual ~Mrc();

    void retain()   { ++retainCnt; }
    void release()  { if (--retainCnt <= 0) delete this; }
};

// ---------------------------------------------------------------------------
template <typename T>
class MrcPtr {
    T*  ptr;
public:
    MrcPtr()        { ptr = 0; }
    MrcPtr(T* p)    { p->retain(); ptr = p; }
    
    T* operator=(T* p)  {
        if (p != ptr) {
            p->retain();
            ptr->release();
            ptr = p;
        }
    }
    T* operator->() { return ptr; }
};

#endif /* Mrc_hpp */
