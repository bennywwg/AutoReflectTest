cmake_minimum_required(VERSION 3.0.0)
project(TestProject VERSION 0.1.0)

# C++ version 20
set(CMAKE_CXX_STANDARD 20)

# Set source dir
set(TEST_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)

add_subdirectory(AutoReflect)
add_custom_target(GenerateReflection COMMAND AutoReflect ${TEST_SOURCE_DIR}/ReflectionTest.cpp)

add_executable(ReflectionTest
    Source/ReflectionTest.cpp
    Source/ReflectionTest.hpp
)
target_include_directories(ReflectionTest PUBLIC ${PROJECT_SOURCE_DIR}/Source)
target_include_directories(ReflectionTest PUBLIC ${PROJECT_SOURCE_DIR}/AutoReflect/Include)
target_include_directories(ReflectionTest PUBLIC ${PROJECT_SOURCE_DIR}/../glm/)
target_include_directories(ReflectionTest PUBLIC ${PROJECT_SOURCE_DIR}/../json/include/)

add_dependencies(ReflectionTest GenerateReflection)