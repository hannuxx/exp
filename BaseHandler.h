#ifndef BASEHANDLER_H
#define BASEHANDLER_H

#include <iostream>
#include <string>

template<typename T>
class BaseHandler {
public:
    BaseHandler() = default;
    ~BaseHandler() = default;
    BaseHandler& Instance() {
        static BaseHandler bh;
        return bh;
    }
    using Sub = T;
    const std::string name = Sub::name;
    const uint16_t max_items = Sub::max_items;

    static void print() {
        std::cout << "BaseHandler print()" << std::endl;
        Sub::print();
    }
    
    int get_int() {
        std::cout << "BaseHandler get_int()" << std::endl;
        return 0;
    }

    int get_interface() {
        std::cout << "BaseHandler get_interface()" << std::endl;
        return static_cast<T*>(this)->get_implementation();
    }
};

#endif
