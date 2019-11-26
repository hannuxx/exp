#ifndef SUBHANDLER_1
#define SUBHANDLER_1

#include <iostream>
#include <string>

struct SubHandler1 {
    typedef uint16_t value_number;
    typedef std::string value_string;
    static const value_number max_items = 10;
    static const value_number max_lines = 100;
    static const value_string name;

    static void print() {
        std::cout << "sub1 print()" << std::endl;
    }

    int get_int() {
        std::cout << "sub1 get_int NOT SUPPORTED!!!" << std::endl;
        return 0;
    }
};
const SubHandler1::value_string SubHandler1::name = "SubHandler1";

#endif // SUBHANDLER_1
