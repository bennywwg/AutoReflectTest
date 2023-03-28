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
    };

    class Person {
    public:
        int Age;
        std::string Name;

        std::any AorVec;
    };
}
