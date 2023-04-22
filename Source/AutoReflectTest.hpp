#pragma once

#include <any>
#include <string>

namespace AutoReflect {
    class A
    {
    public:
        int Value;
    };

    template<typename T>
    class Vec {
    public:
        T x;
        T y;
        T z;

        Vec() : x(0), y(0), z(0) { }
        Vec(int X, int Y, int Z) : x(X), y(Y), z(Z) { }
    };

    class Person {
    public:
        int Age;
        std::string Name;

        Vec<int> Position;
    };
}
