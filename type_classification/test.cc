#include "type.h"
#include <iostream>

#define PRINT_TYPE(VAL) \
    std::cout << GetType(VAL) << std::endl;

class Test {

};

void test_fun() {

}

int main() {

    //build-in
    PRINT_TYPE(1);
    PRINT_TYPE(-1.11);
    PRINT_TYPE('a');

    //pointer

    //reference

    //pointer member

    //array

    //function

    //enum

    //class

    return 0;
}