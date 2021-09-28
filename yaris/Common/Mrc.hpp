//
//  Mrc.hpp
//  yaris
//
//  Created by Michel Launier on 2021-09-28.
//

#ifndef Mrc_hpp
#define Mrc_hpp

// ---------------------------------------------------------------------------
/// Manual Reference Count base type
///
class Mrc {
    int retainCnt;  ///< Count of the number of users

public:
            Mrc()                   { retainCnt = 0; }

            void retain()           { ++retainCnt; }
            void release()          { if (--retainCnt <= 0) dispose(); }
            int  getRetainCount()   { return retainCnt; }

protected:
    virtual void dispose()          { delete this; }
};


// ---------------------------------------------------------------------------
/// Generic pointer to automate the rentention and release of Mrc objects.
///
class _MrcPtr {
protected:
    Mrc*    ptr;
    
public:
    _MrcPtr()       { ptr = 0; }
    _MrcPtr(Mrc* p);
    ~_MrcPtr();

    Mrc* assign(Mrc* p);
    Mrc* getPtr() const { return ptr; }
};

// ---------------------------------------------------------------------------
/// Type specific pointer to automate the retention and release of Mrc objects.
///
template <typename T>
class MrcPtr : _MrcPtr {
public:
    MrcPtr(T* p) : _MrcPtr(p)   {}
    
    T* operator=(T* p)  { return dynamic_cast<T*>( assign(p) ); }
    T* operator->()     { return dynamic_cast<T*>( getPtr() ); }
};

#endif /* Mrc_hpp */