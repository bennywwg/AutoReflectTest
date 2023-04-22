#include <iostream>
#include <string>

#include <AutoReflectTest.hpp>
#include <AutoReflectTest.cpp.gen.inl>

using namespace AutoReflect;

template<typename T>
void Log(T const& Val) {
    Serializer Ser;

    SerializeFields(Ser, Val);

    std::cout << Ser.Data;

    if (!Ser.Binary.empty()) {
		std::cout << " (with binary data of " << Ser.Binary.size() << " bytes)";
	}
    std::cout << std::endl;
}

template<typename T>
std::string ToString(T const& Val) {
    Serializer Ser;

    SerializeFields(Ser, Val);

    return Ser.Data.dump();
}

template<typename T>
T FromString(std::string const& Str) {
    Deserializer Ser;
    Ser.Data = nlohmann::json::parse(Str);

    T Val;
    DeserializeFields(Ser, Val);

    return Val;
}

int main(int argc, char** argv) {
    Vec<int> v;
    v.x = 1;
    v.y = 2;
    v.z = 3;
    Log(v);

    Person p3 { 45, std::string("Robert") };
    Log(p3);

    std::vector<Person> People;
    People.push_back(p3);
    People.push_back(Person { 23, "John" });
    People.push_back(Person { 34, "Jane" });
    Log(People);

    std::vector<Vec<int>> Vectors;
    Vectors.push_back(v);
    Vectors.push_back(Vec<int>(4, 5, 6 ));
    Vectors.push_back(Vec<int>(7, 8, 9 ));
    Log(Vectors);
    
    A a;
    a.Value = 123;
    Log(a);
}
