cmake_minimum_required(VERSION 3.0.0)
project(AutoReflectTest VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

# Set source dir
set(TEST_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)

add_subdirectory(AutoReflect)
add_custom_target(GenerateReflection COMMAND AutoReflect ${TEST_SOURCE_DIR}/AutoReflectTest.cpp)

add_executable(AutoReflectTest
    Source/AutoReflectTest.cpp
    Source/AutoReflectTest.hpp
)
target_include_directories(AutoReflectTest PUBLIC ${PROJECT_SOURCE_DIR}/Source)
target_include_directories(AutoReflectTest PUBLIC ${PROJECT_SOURCE_DIR}/AutoReflect/Include)
#target_include_directories(AutoReflectTest PUBLIC ${PROJECT_SOURCE_DIR}/../glm/)
target_include_directories(AutoReflectTest PUBLIC ${PROJECT_SOURCE_DIR}/AutoReflect/json/include/)

add_dependencies(AutoReflectTest GenerateReflection)
