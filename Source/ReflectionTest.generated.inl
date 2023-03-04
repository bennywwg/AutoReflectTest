#pragma once

#include <SerializeBaseImpl.hpp>

inline void SerializeFields(Serializer& Ser, A const& Val) {
    Serialize(Ser, "Value", Val.Value);
}

inline void DeserializeFields(Deserializer& Ser, A& Val) {
    Deserialize(Ser, "Value", Val.Value);
}

inline void Serialize(Serializer& Ser, char const* Name, A const& Val) {
    BeginObject(Ser, Name);
    SerializeFields(Ser, Val);
    EndObject(Ser);
}

inline void Deserialize(Deserializer& Ser, char const* Name, A& Val) {
    BeginObject(Ser, Name);
    DeserializeFields(Ser, Val);
    EndObject(Ser);
}

template<typename T>
inline void SerializeFields(Serializer& Ser,  ns::Vec<T> const& Val) {
    Serialize(Ser, "x", Val.x);
    Serialize(Ser, "y", Val.y);
    Serialize(Ser, "z", Val.z);
}

template<typename T>
inline void DeserializeFields(Deserializer& Ser,  ns::Vec<T>& Val) {
    Deserialize(Ser, "x", Val.x);
    Deserialize(Ser, "y", Val.y);
    Deserialize(Ser, "z", Val.z);
}

template<typename T>
inline void Serialize(Serializer& Ser, char const* Name,  ns::Vec<T> const& Val) {
    BeginObject(Ser, Name);
    SerializeFields(Ser, Val);
    EndObject(Ser);
}

template<typename T>
inline void Deserialize(Deserializer& Ser, char const* Name,  ns::Vec<T>& Val) {
    BeginObject(Ser, Name);
    DeserializeFields(Ser, Val);
    EndObject(Ser);
}

