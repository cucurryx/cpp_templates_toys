
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


#define MARK_BUILD_IN_TYPE(T)   \
    template <>                 \
    class IsBuildInType<T> {    \
    public:                     \
        enum {                  \
            kYes = 1,           \
            kNo = 0             \
        };                      \
    };                              

//void
MARK_BUILD_IN_TYPE(void)

//bool
MARK_BUILD_IN_TYPE(bool)

//characters
MARK_BUILD_IN_TYPE(char)
MARK_BUILD_IN_TYPE(signed char)
MARK_BUILD_IN_TYPE(unsigned char)
MARK_BUILD_IN_TYPE(wchar_t)

//integers
MARK_BUILD_IN_TYPE(signed short)
MARK_BUILD_IN_TYPE(unsigned short)
MARK_BUILD_IN_TYPE(signed int)
MARK_BUILD_IN_TYPE(unsigned int)
MARK_BUILD_IN_TYPE(signed long)
MARK_BUILD_IN_TYPE(unsigned long)
MARK_BUILD_IN_TYPE(signed long long)
MARK_BUILD_IN_TYPE(unsigned long long)

//float numbers
MARK_BUILD_IN_TYPE(float)
MARK_BUILD_IN_TYPE(double)
MARK_BUILD_IN_TYPE(long double)

#undef MARK_BUILD_IN_TYPE
