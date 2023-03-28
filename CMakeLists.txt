cmake_minimum_required(VERSION 3.0.0)
project(AutoReflectTest VERSION 0.1.0)

# C++ version 20
set(CMAKE_CXX_STANDARD 20)

# Set source dir
set(TEST_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)

set(TEST_SOURCES
    ${TEST_SOURCE_DIR}/AutoReflectTest.cpp
    ${TEST_SOURCE_DIR}/AdditionalCpp.cpp
)

set(INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/Source
    ${PROJECT_SOURCE_DIR}/AutoReflect/Include
    ${PROJECT_SOURCE_DIR}/AutoReflect/json/include/
)

# Include dirs with -I in front of them
foreach(INCLUDE_DIR ${INCLUDE_DIRS})
    set(REFLECTION_INCLUDES ${REFLECTION_INCLUDES} -I ${INCLUDE_DIR})
endforeach()

add_subdirectory(AutoReflect)
add_custom_target(GenerateReflection COMMAND AutoReflect -S ${TEST_SOURCES} ${REFLECTION_INCLUDES})

add_executable(AutoReflectTest
    ${TEST_SOURCE_DIR}/AutoReflectTest.hpp

    ${TEST_SOURCES}
)

foreach(INCLUDE_DIR ${INCLUDE_DIRS})
    target_include_directories(AutoReflectTest PUBLIC ${INCLUDE_DIR})
endforeach()

add_dependencies(AutoReflectTest GenerateReflection)