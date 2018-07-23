#include "basic_type.h"
#include "compound_type.h"

// A type whose size is two
typedef struct {
    char a[2];
} Two;

// A type whose size is one
typedef char One;

#define CHECK_ENUM(T) \
    One check_enum(T);

//bool
CHECK_ENUM(bool)

//characters
CHECK_ENUM(char)
CHECK_ENUM(signed char)
CHECK_ENUM(unsigned char)
CHECK_ENUM(wchar_t)

//integers
CHECK_ENUM(signed short)
CHECK_ENUM(unsigned short)
CHECK_ENUM(signed int)
CHECK_ENUM(unsigned int)
CHECK_ENUM(signed long)
CHECK_ENUM(unsigned long)
CHECK_ENUM(signed long long)
CHECK_ENUM(unsigned long long)

//float numbers
CHECK_ENUM(float)
CHECK_ENUM(double)
CHECK_ENUM(long double)

#undef CHECK_ENUM

// if T's transformed type is not a interger or float type, it's not enum.
Two check_enum(...);

template <typename T, 
    bool can_transform = !CompoundType<T>::kIsFunction && 
                         !CompoundType<T>::kIsArray>
class TypeTransform {
public:
    // type transform function. TypeTransform<T> will be transformed to type T if possible.
    operator T() const;
};

// functions and arrays can't be transformed
template <typename T>
class TypeTransform<T, false> {

};

// void can't be transformed
template <bool can_transform>
class TypeTransform<void, can_transform> {

};

template <typename T>
class IsEnumType {
public:
    enum {
        kYes = IsBuildInType<T>::kNo &&
            !CompoundType<T>::kIsPointer &&
            !CompoundType<T>::kIsReference &&
            !CompoundType<T>::kIsPointerMember &&
            sizeof(check_enum(TypeTransform<T>())) == 1
    };

    enum {
        kNo = !kYes
    };
};
