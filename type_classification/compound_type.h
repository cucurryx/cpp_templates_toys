#include <cstddef>

// Compount type is a kind of type which is constructed from other types. 
// We also use local specialization to implement it.


// tools for finding function types
template <typename T>
class IsFunctionType {
private:
    typedef char One; //sizeof(char) == 1
    typedef struct {
        char a[2];
    } Two;            //sizeof(Two) == 2
    
    template <typename X>
    static One test(...); //if choose this template, it's function or const void or void or reference.

    template <typename X>
    static Two test(X (*)[1]); //if choose this template, it's else.

public:
    //if T's function type or void or const void or reference, sizeof() will be 1
    // else, sizeof() will be 2
    enum {
        kYes = sizeof(IsFunctionType<T>::test<T>(0)) == 1
    };

    enum {
        kNo = !kYes
    };
};

template <typename T>
class IsFunctionType<T&> {
public:
    enum {
        kYes = 0,
        kNo = 1
    };
};

template <>
class IsFunctionType<void> {
public:
    enum {
        kYes = 0,
        kNo = 1
    };
};

template <>
class IsFunctionType<const void> {
public:
    enum {
        kYes = 0,
        kNo = 1
    };
};

//
//compound types
//

template <typename T>
class CompoundType {
public:
    enum {
        kIsPointer = 0,
        kIsReference = 0,
        kIsArray = 0,
        kIsFunction = IsFunctionType<T>::kYes,
        kIsPointerMember = 0
    };

    typedef T BaseType;
    typedef T BottomType;
    typedef CompoundType<void> ClassType;
};

//pointer
template <typename T>
class CompoundType<T*> {
public:
    enum {
        kIsPointer = 1,
        kIsReference = 0,
        kIsArray = 0,
        kIsFunction = 0,
        kIsPointerMember = 0
    };

    typedef T BaseType;
    typedef T BottomType;
    typedef CompoundType<void> ClassType;
};

//reference
template <typename T>
class CompoundType<T&> {
public:
    enum {
        kIsPointer = 0,
        kIsReference = 1,
        kIsArray = 0,
        kIsFunction = 0,
        kIsPointerMember = 0
    };

    typedef T BaseType;
    typedef T BottomType;
    typedef CompoundType<void> ClassType;
};

// empty array
template <typename T>
class CompoundType<T[]> {
public:
    enum {
        kIsPointer = 0,
        kIsReference = 0,
        kIsArray = 1,
        kIsFunction = 0,
        kIsPointerMember = 0
    };

    typedef T BaseType;
    typedef typename CompoundType<T>::BottomType BottomType;
    typedef CompoundType<void> ClassType;
};

//array
template <typename T, size_t N>
class CompoundType<T[N]> {
public:
    enum {
        kIsPointer = 0,
        kIsReference = 0,
        kIsArray = 1,
        kIsFunction = 0,
        kIsPointerMember = 0
    };

    typedef T BaseType;
    typedef typename CompoundType<T>::BottomType BottomType;
    typedef CompoundType<void> ClassType;
};

//member pointer
template <typename T, typename C>
class CompoundType<T C::*> {
public:
    enum {
        kIsPointer = 0,
        kIsReference = 0,
        kIsArray = 0,
        kIsFunction = 0,
        kIsPointerMember = 1
    };

    typedef T BaseType;
    typedef typename CompoundType<T>::BottomType BottomType;
    typedef C ClassType;
};

// functions
template <typename R>
class CompoundType<R()> {
public:
    enum {
        kIsPointer = 0,
        kIsReference = 0,
        kIsArray = 0,
        kIsFunction = 1,
        kIsPointerMember = 0
    };

    typedef R BaseType();
    typedef R BottomType();
    typedef CompoundType<void> ClassType;
};

template <typename R, typename P1>
class CompoundType<R(P1)> {
public:
    enum {
        kIsPointer = 0,
        kIsReference = 0,
        kIsArray = 0,
        kIsFunction = 1,
        kIsPointerMember = 0
    };

    typedef R BaseType(P1);
    typedef R BottomType(P1);
    typedef CompoundType<void> ClassType;
};

template <typename R, typename P1>
class CompoundType<R(P1, ...)> {
public:
    enum {
        kIsPointer = 0,
        kIsReference = 0,
        kIsArray = 0,
        kIsFunction = 1,
        kIsPointerMember = 0
    };

    typedef R BaseType(P1);
    typedef R BottomType(P1);
    typedef CompoundType<void> ClassType;
};
