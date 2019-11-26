#include <iostream>
#include <string>

#include "BaseHandler.h"
#include "SubHandler1.h"
#include "SubHandler2.h"

int test(int argc, char* argv[])
{
    BaseHandler<SubHandler1> s1;
    s1.print();
    auto i1 = s1.get_int();

    SubHandler2 s2;
    s2.print();
    auto i2 = s2.get_int();
    auto i22 = s2.get_interface();

    return 0;
}

int main(int argc, char* argv[])
{
    return test(argc, argv);
}
