#include <iostream>
#include <string>

#include <AutoReflectTest.hpp>
#include <AutoReflectTest.generated.inl>

template<typename T>
void Log(T const& Val) {
    Serializer Ser;

    SerializeFields(Ser, Val);

    std::cout << Ser.Data << std::endl;
}

int main(int argc, char** argv) {
    ns::Vec<int> v = { {}, 1, 2, 3 };
    Log(v);

    Person p3 { {}, 45, std::string("Robert") };
    Log(p3);
}
