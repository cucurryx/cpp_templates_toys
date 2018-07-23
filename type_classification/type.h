#include "class_type.h"
#include <string>

template <typename T>
class Type {
public:
    enum {
        kIsBuildInType = IsBuildInType<T>::kYes,
        kIsPointerType = CompoundType<T>::kIsPointer,
        kIsReferenceType = CompoundType<T>::kIsReference,
        kIsArrayType = CompoundType<T>::kIsArray,
        kIsFunctionType = CompoundType<T>::kIsFunction,
        kIsPointerMemberType = CompoundType<T>::kIsPointerMember,
        kIsEnumType = IsEnumType<T>::kYes,

        kIsClassType = IsClassType<T>::kYes
    };
};

template <typename T>
std::string GetType() {
    std::string type;
    
    if (Type<T>::kIsArrayType) {
        type += "array type, bottom type:\n";
        type += "\t";
        // // type += GetType<CompoundType<T>::BottomType>();
    }
    if (Type<T>::kIsBuildInType) {
        type += "build-in type";
    }
    if (Type<T>::kIsClassType) {
        type += "class type";
    }
    if (Type<T>::kIsEnumType) {
        type += "enum type";
    }
    if (Type<T>::kIsFunctionType) {
        type += "function type";
    }
    if (Type<T>::kIsPointerMemberType) {
        type += "pointer member type, bottom type:\n";
        type += "\t";
        // // type += GetType<CompoundType<T>::BottomType>();    
    }
    if (Type<T>::kIsPointerType) {
        type += "pointer type, bottom type:\n";
        type += "\t";
        // // type += GetType<CompoundType<T>::BottomType>();   
    }
    if (Type<T>::kIsReferenceType) {
        type += "reference type, bottom type:\n";
        type += "\t";
        // type += GetType<CompoundType<T>::BottomType>();   
    }
    return type;
}

template <typename T>
std::string GetType(const T &val) {
    return GetType<T>();
}

