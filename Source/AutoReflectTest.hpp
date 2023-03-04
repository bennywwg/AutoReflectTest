#pragma once

#include <AutoReflect.hpp>

class A : public AutoReflect
{
public:
    int Value;
};

namespace ns {
    template<typename T>
    class Vec : public AutoReflect {
    public:
        T x;
        T y;
        T z;
    };
}

class Person : public AutoReflect {
public:
    int Age;
    std::string Name;
};
