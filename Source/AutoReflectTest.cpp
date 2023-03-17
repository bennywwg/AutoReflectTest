#include <iostream>
#include <string>

#include <AutoReflectTest.hpp>
#include <AutoReflectTest.generated.inl>

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

int main(int argc, char** argv) {
    Vec<int> v = { 1, 2, 3 };
    Log(v);

    Person p3 { 45, "Robert" };
    Log(p3);

    std::vector<Person> People;
    People.push_back(p3);
    People.push_back(Person { 23, "John" });
    People.push_back(Person { 34, "Jane" });
    Log(People);

    std::vector<Vec<int>> Vectors;
    Vectors.push_back(v);
    Vectors.push_back(Vec<int> { 4, 5, 6 });
    Vectors.push_back(Vec<int> { 7, 8, 9 });
    Log(Vectors);

    std::vector<std::vector<Vec<int>>> Vectors2;
    Vectors2.push_back(Vectors);
    Vectors2.push_back(Vectors);
    Vectors2.push_back(Vectors);
    Log(Vectors2);

    std::vector<uint8_t> BinaryData;
    BinaryData.push_back(0x01);
    BinaryData.push_back(0x02);
    BinaryData.push_back(0x03);
    BinaryData.push_back(0x04);
    Log(BinaryData);
}
