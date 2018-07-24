#include "type.h"
#include <iostream>

#define PRINT_TYPE(EXPR, VAL) \
    std::cout << EXPR << "'s type is: \n" << GetType(VAL) << "\n" << std::endl;

class TestClass {
public:
    int *a;
};

void test_fun() {

}

int main() {

    //build-in
    PRINT_TYPE("1", 1);
    PRINT_TYPE("-1.11", -1.11);
    PRINT_TYPE("\'a\'", 'a');
    PRINT_TYPE("true", true);

    //pointer
    int a = 1;
    bool b = true;
    double c = 3.14;
    double *d = &c;
    PRINT_TYPE("int *a", &a);
    PRINT_TYPE("bool *b", &b);
    PRINT_TYPE("double *c", &c);
    PRINT_TYPE("double **c", &d);

    //reference
    int &f = a;
    PRINT_TYPE("int &f", f);

    //pointer member
    TestClass g;
    PRINT_TYPE("TestClass::a", g.a);

    //array
    char h[] = "helloworld";
    int i[10];
    PRINT_TYPE("char h[]", h);
    PRINT_TYPE("int i[10]", i);

    //function
    PRINT_TYPE("void test_fun()", test_fun);
    PRINT_TYPE("[](){}", [](){});

    //enum
    typedef enum {
        kHello, kWorld
    } TestEnum;
    TestEnum j;
    PRINT_TYPE("enum{}", j);

    //class
    PRINT_TYPE("TestClass g", g);
    PRINT_TYPE("std::cin", std::cin);

    return 0;
}