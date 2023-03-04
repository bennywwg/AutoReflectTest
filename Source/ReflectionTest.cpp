#include <iostream>

#include <ReflectionTest.hpp>
#include <ReflectionTest.generated.inl>

template<typename T>
void Log(T const& Val) {
    Serializer Ser;

    SerializeFields(Ser, Val);

    std::cout << Ser.Data << std::endl;
}

int main(int argc, char** argv) {
    ns::Vec<int> v;
    v.x = 1;
    v.y = 2;
    v.z = 3;
    Log(v);
}
