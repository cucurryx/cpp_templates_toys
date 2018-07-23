#include "enum_type.h"

// If type T is not basic type, compound type or enum type, it's a class type.
template <typename T>
class IsClassType {
public:
    enum {
        kYes = IsBuildInType<T>::kNo &&
            IsEnumType<T>::kNo &&
            !CompoundType<T>::kIsPointer &&
            !CompoundType<T>::kIsReference &&
            !CompoundType<T>::kIsArray &&
            !CompoundType<T>::kIsFunction &&
            !CompoundType<T>::kIsPointerMember
    };

    enum {
        kNo = !kYes
    };
};