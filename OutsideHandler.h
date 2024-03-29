#ifndef SUBHANDLER_1
#define SUBHANDLER_1

#include <iostream>
#include <string>

template<typename T>
struct OutsideHandler {
    OutsideHandler() {}
    typedef T ntype;
    static const ntype max_items = 10;
    static const ntype max_lines = 100;
    static const std::string name;

    static void print() {
        std::cout << "OutsideHandler<T>::print()" << std::endl;
    }

    T get_num() {
        std::cout << "OutsideHandler<T>::get_num NOT SUPPORTED!!!" << std::endl;
        return 0;
    }

    static T run_static() {
        std::cout << "OutsideHandler<T> derived_static()" << std::endl;
        return 2000000;
    }
};

template<typename T>
const std::string OutsideHandler<T>::name = "OutsideHandler<T>";

#endif
