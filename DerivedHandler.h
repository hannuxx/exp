#ifndef SUBHANDLER_2
#define SUBHANDLER_2

#include <string>

#include "BaseHandler.h"

template<typename T>
struct DerivedHandler : public BaseHandler<DerivedHandler<T>> {
    DerivedHandler() {
        this->set_eq_n([](uint64_t a, uint64_t b) {
            return a == b && a != 0;
        });
        this->set_eq_s([](const std::string& a, const std::string& b) {
            return a == b || b.empty();
        });
    }
    typedef T ntype;
    static const ntype max_items = 10;
    static const ntype max_lines = 100;
    static const std::string name;

    int run_derived() {
        std::cout << "DerivedHandler<T> derived()" << std::endl;
        return 2000;
    }

    static int run_static() {
        std::cout << "DerivedHandler<T> derived_static()" << std::endl;
        return 2000000;
    }
};

template<typename T>
const std::string DerivedHandler<T>::name = "DerivedHandler<T>";

#endif