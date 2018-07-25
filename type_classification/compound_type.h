#include <cstddef>

// Compount type is a kind of type which is constructed from other types. 
// We also use local specialization to implement it.


// tools for finding function types
template <typename T>
class IsFunctionType {
private:
    //sizeof(char) == 1
    using One = char;

    //sizeof(Two) == 2
    using Two = struct {
        char a[2];
    };           
    
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

    using BaseType = T;
    using BottomType = T;
    using ClassType = CompoundType<void>;
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

    using BaseType = T;
    using BottomType = T;
    using ClassType = CompoundType<void>;
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

    using BaseType = T;
    using BottomType = T;
    using ClassType = CompoundType<void>;
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

    using BaseType = T;
    using BottomType = typename CompoundType<T>::BottomType;
    using ClassType = CompoundType<void>;
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

    using BaseType = T;
    using BottomType = typename CompoundType<T>::BottomType;
    using ClassType = CompoundType<void>;
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

    using BaseType = T;
    using BottomType = typename CompoundType<T>::BottomType;
    using ClassType = C;
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

    using BaseType = R();
    using BottomType = R();
    using ClassType = CompoundType<void>;
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

    using BaseType = R(P1);
    using BottomType = R(P1);
    using ClassType = CompoundType<void>;
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

    using BaseType = R(P1);
    using BottomType = R(P1);
    using ClassType = CompoundType<void>;
};
