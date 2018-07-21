
// This class template is used to recogonize type T is a build-in type or not.
// If yes, kYes will be set to 1. The default value of kYes is 0.
template <typename T>
class IsBuildInType {
public:
    enum {
        kYes = 0,
        kNo = 1
    };
};


#define MAKE_BUILD_IN_TYPE(T)   \
    template <>                 \
    class IsBuildInType<T> {    \
    public:                     \
        enum {                  \
            kYes = 1,           \
            kNo = 0             \
        };                      \
    };                              

//void
MAKE_BUILD_IN_TYPE(void)

//bool
MAKE_BUILD_IN_TYPE(bool)

//characters
MAKE_BUILD_IN_TYPE(char)
MAKE_BUILD_IN_TYPE(signed char)
MAKE_BUILD_IN_TYPE(unsigned char)
MAKE_BUILD_IN_TYPE(wchar_t)

//integers
MAKE_BUILD_IN_TYPE(signed short)
MAKE_BUILD_IN_TYPE(unsigned short)
MAKE_BUILD_IN_TYPE(signed int)
MAKE_BUILD_IN_TYPE(unsigned int)
MAKE_BUILD_IN_TYPE(signed long)
MAKE_BUILD_IN_TYPE(unsigned long)
MAKE_BUILD_IN_TYPE(signed long long)
MAKE_BUILD_IN_TYPE(unsigned long long)

//float numbers
MAKE_BUILD_IN_TYPE(float)
MAKE_BUILD_IN_TYPE(double)
MAKE_BUILD_IN_TYPE(long double)

#undef MAKE_BUILD_IN_TYPE