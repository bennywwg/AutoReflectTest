#pragma once

#include <any>
#include <string>

namespace AutoReflect {

    enum class TheBlooper : long
    {
        A = 1,
        B = 2,
        C = 3
    };


    enum class E : int
    {
        A = 1,
        B = 2,
        C = 3
    };
    class A
    {
    public:
        int Value;

        E TheE = E::A;
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
