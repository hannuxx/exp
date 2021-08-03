#ifndef BASEHANDLER_H
#define BASEHANDLER_H

#include <functional>
#include <iostream>
#include <string>

template<typename T>
class BaseHandler {
public:
    BaseHandler() = default;
    ~BaseHandler() = default;
    std::function<bool(uint64_t, uint64_t)> eq_n;
    std::function<bool(std::string, std::string)> eq_s;
    BaseHandler& Instance() {
        static T t;
        return t;
    }

    static void print() {
        std::cout << "BaseHandler<T> print(): T::name: " << T::name << std::endl;
    }

    int run() {
        //auto a1 = static_cast<T*>(this)->run_derived();
        auto a1 = run_static();
        auto a2 = T::run_static();
        return a1 + a2;
    }

    void set_eq_n(const std::function<bool(uint64_t, uint64_t)> fparam) {
        if (fparam) {
            eq_n = fparam;
        } else {
            eq_n = [](uint64_t a, uint64_t b) { return a == b; };
        }
    }

    void set_eq_s(const std::function<bool(std::string, std::string)> fparam) {
        if (fparam) {
            eq_s = fparam;
        } else {
            eq_s = [](std::string a, std::string b) { return a == b; };
        }
    }

    int isEqual(uint64_t a, uint64_t b) {
        std::cout << "BaseHandler<T> uint64_t isEqual()" << std::endl;
        return eq_n(a, b);
    }

    int isEqual(std::string a, std::string b) {
        std::cout << "BaseHandler<T> std::string isEqual()" << std::endl;
        return eq_s(a, b);
    }

    int get_num() {
        std::cout << "BaseHandler<T> get_num(): T::max_items: " << T::max_items << std::endl;
        return 0;
    }

    static int run_static() {
        std::cout << "BaseHandler<T> run_static()" << std::endl;
        return 10;
    }
};

#endif
