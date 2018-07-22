#include "basic_type.h"
#include "compound_type.h"
#include "class_type.h"
#include "enum_type.h"

template <typename T>
class Type {
public:
    enum {
        kIsBuildInType = IsBuildInType<T>::kYes,
        kIsPointerType = CompoundType<T>::kIsPointerType,
        kIsReferenceType = CompoundType<T>::kIsReferenceType,
        kIsArrayType = CompoundType<T>::kIsArrayType,
        kIsFunctionType = CompoundType<T>::kIsFunctionType,
        kIsPointerMemberType = CompoundType<T>::kIsPointerMemberType,
        kIsEnumType = IsEnumType<T>::kYes,
        kIsClassType = IsClassType<T>::kYes
    };
};