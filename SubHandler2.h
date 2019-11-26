#ifndef SUBHANDLER_2
#define SUBHANDLER_2

#include <string>

#include "BaseHandler.h"

struct SubHandler2 : public BaseHandler<SubHandler2> {
    typedef uint16_t value_number;
    typedef std::string value_string;
    static const value_number max_items = 10;
    static const value_number max_lines = 100;
    static const value_string name;

    static void print() {
        std::cout << "sub2 print()" << std::endl;
    }

    int get_int() {
        std::cout << "sub2 get_int()" << std::endl;
        return 222;
    }

    int get_implementation() {
        std::cout << "sub2 get_implementation()" << std::endl;
        return 222;
    }
};
const SubHandler2::value_string SubHandler2::name = "SubHandler2";

#endif // SUBHANDLER_2
