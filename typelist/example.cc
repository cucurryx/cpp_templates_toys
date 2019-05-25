#include "typelist.h"
#include <type_traits>
#include <iostream>

int main() {
    using SimpleTypeList = TypeList<int, char, bool, long, double, float>;
    using Int = Front<SimpleTypeList>;
    static_assert(std::is_same<Int, int>::value);
    std::cout << sizeof...(SimpleTypeList) << std::endl;
}