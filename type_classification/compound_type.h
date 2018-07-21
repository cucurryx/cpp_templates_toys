// Compount type is a kind of type which is constructed from other types. 
// We also use local specialization to implement it.

template <typename T>
class CompoundType {
public:
    enum {
        kIsPointer = 0,
        kIsReference = 0,
        kIsArray = 0,
        kIsFunction = 0,
        kIsPointerMember = 0
    };

    typedef T BaseType;
    typedef T BottomTYpe;
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
    typedef T BottomTYpe;
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
    typedef T BottomTYpe;
    typedef CompoundType<void> ClassType;
};

// array
// TODO(other types)
