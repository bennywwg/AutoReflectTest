#include <iostream>
#include <string>

#include <AutoReflectTest.hpp>
#include <AutoReflectTest.generated.inl>

using namespace AutoReflect;

template<typename T>
void Log(T const& Val) {
    Serializer Ser;

    SerializeFields(Ser, Val);

    std::cout << Ser.Data << std::endl;
}

int main(int argc, char** argv) {
    Vec<int> v = { 1, 2, 3 };
    Log(v);

    Person p3 { 45, std::string("Robert") };
    Log(p3);

    std::vector<Person> People;
    People.push_back(p3);
    People.push_back(Person { 23, std::string("John") });
    People.push_back(Person { 34, std::string("Jane") });
    Log(People);

    std::vector<Vec<int>> Vectors;
    Vectors.push_back(v);
    Vectors.push_back(Vec<int> { 4, 5, 6 });
    Vectors.push_back(Vec<int> { 7, 8, 9 });
    Log(Vectors);
}
