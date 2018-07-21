#include "basic_type.h"
#include "compound_type.h"
#include <iostream>

template <typename T>
void TestBuildIn(const T &val) {
    if (IsBuildInType<T>::kYes) {
        std::cout << "build-in type" << std::endl;
    } else {
        if (CompoundType<T>::kIsPointer) {
            std::cout << "pointer type" << std::endl;
        } else if (CompoundType<T>::kIsReference) {
            std::cout << "reference type" << std::endl;
        } else if (CompoundType<T>::kIsArray) {
            std::cout << "array type" << std::endl;
        } else {
            std::cout << "TODO" << std::endl;
        }
    }
}

class Test {

};

int main() {
    TestBuildIn(10);
    TestBuildIn("helloworld"); //should be array type
    TestBuildIn('a');
    TestBuildIn(-3.14159);
    TestBuildIn(true);

    // TestBuildIn(std::cin);
    // TestBuildIn(std::cout);
    // TestBuildIn(Test());

    int a = 10;
    TestBuildIn(&a);
    int &b = a;
    TestBuildIn<int&>(b);

    int c[1] = {0};
    TestBuildIn(c); 

    return 0;
}