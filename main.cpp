#include <iostream>
#include <string>

#include "BaseHandler.h"
#include "OutsideHandler.h"
#include "DerivedHandler.h"
#include <optional>
#include <variant>

template<typename ... T>
auto add(const T & ... param) {
    return (param + ...);
}

// union crazy
union Crazy {
    std::string s;
    std::vector<uint8_t> v;
    ~Crazy() {}
};

class MyClass {
public:
    MyClass() {
        name = new char[128];
        strcpy_s(name, 13, "Hello World!");
    }
    MyClass(const MyClass& other) {
        if (this != &other) {
            delete name;
            name = new char[128];
            if (other.name != nullptr) {
                const auto sz = strlen(other.name);
                strcpy_s(name, sz, other.name);
            }
        }
    }
    ~MyClass() {
        delete name;
        name = nullptr;
    }
    char* name = nullptr;
};

int test_templates(int argc, char* argv[]) {
    BaseHandler<OutsideHandler<uint32_t>> s1;
    s1.set_eq_n([](uint64_t a, uint64_t b) { return a == b && a != 0; });
    s1.set_eq_s([](const std::string& a, const std::string& b) { return a == b || b.empty(); });
    const auto b = s1.isEqual(123, 555);
    s1.print();
    auto i1 = s1.get_num();
    auto iRun1 = s1.run();

    DerivedHandler<uint64_t> s2;
    const auto b2 = s2.isEqual(123, 555);
    s2.print();
    auto iRun2 = s2.run();

    return 0;
}

int test_optional() {
    std::optional<std::string> o1; // empty
    o1 = "Yes";

    std::optional<std::string> oEmpty;

    // emplace:
    oEmpty.emplace("Steve");

    // calls ~Steve and creates new Mark:
    oEmpty.emplace("Mark");


    // reset so it's empty again
    oEmpty.reset(); // calls ~Mark
    // same as:
    //oEmpty = std::nullopt;

    // assign a new value:
    oEmpty.emplace("Fred");
    oEmpty = std::string("Joe");

    return 0;
}

int test_allocations() {
    MyClass mc;
    return 0;
}

int main(int argc, char* argv[]) {
    int i1 = test_templates(argc, argv);
    int i2 = test_optional();
    
    const auto x = add(1, 2, 3, 4, 5);

    Crazy c = { "Hello, world" };
    c.s = "Hello";
    c.s.~basic_string();

    // optional

    // variant
    //std::variant<int, float, std::string> var{ 10.5f };
    //std::variant<int, float, std::string> var{ "Kissa" };
    std::variant<int, float, std::string> var{ 0 };
    var = 123.5f;
    if (var.index() == 0) {
        std::cout << var.index() << ", value " << std::get<int>(var) << "\n";
    } else if (var.index() == 1) {
        std::cout << var.index() << ", value " << std::get<float>(var) << "\n";
    } else if (var.index() == 2) {
        std::cout << var.index() << ", value " << std::get<std::string>(var) << "\n";
    }

    test_allocations();

    return i1 + i2;
}
