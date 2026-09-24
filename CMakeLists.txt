cmake_minimum_required(VERSION 3.16)
project(cs210_cpp_intro CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------------------------------------------------------------------
# CS 210 -- C++ Bootcamp
#
# Each block below builds ONE small executable for ONE task in the bootcamp.
# In CLion, the dropdown next to the Run/Debug button (top right toolbar)
# lists every target here by name. Switching the dropdown and hitting Run
# is how we move from task to task during class, no new project, no
# reconfiguring, just pick the next target and go.
#
# Tasks are numbered to match the order we teach them in. Work top to
# bottom during lectures.
# ---------------------------------------------------------------------------

add_executable(01_compile_model
        01_compile_model/main.cpp)

add_executable(02_header_cpp_split
        02_header_cpp_split/main.cpp
        02_header_cpp_split/shape_utils.cpp
        02_header_cpp_split/shape_utils.h)

add_executable(03_adt_stack
        03_adt_stack/main.cpp
        03_adt_stack/Stack.cpp
        03_adt_stack/Stack.h)

add_executable(04_classes_objects
        04_classes_objects/main.cpp
        04_classes_objects/Rectangle.cpp
        04_classes_objects/Rectangle.h)

add_executable(05_namespaces
        05_namespaces/main.cpp
        05_namespaces/geometry.cpp
        05_namespaces/geometry.h)

add_executable(06_constructors_modern
        06_constructors_modern/main.cpp
        06_constructors_modern/Point.cpp
        06_constructors_modern/Point.h)

add_executable(07_overloading
        07_overloading/main.cpp
        07_overloading/Calculator.cpp
        07_overloading/Calculator.h)

add_executable(08_overriding_virtual
        08_overriding_virtual/main.cpp
        08_overriding_virtual/Shape.cpp
        08_overriding_virtual/Shape.h
        08_overriding_virtual/Circle.cpp
        08_overriding_virtual/Circle.h
        08_overriding_virtual/Square.cpp
        08_overriding_virtual/Square.h)

add_executable(09_diamond_inheritance
        09_diamond_inheritance/main.cpp
        09_diamond_inheritance/Animal.cpp
        09_diamond_inheritance/Animal.h
        09_diamond_inheritance/Swimmer.cpp
        09_diamond_inheritance/Swimmer.h
        09_diamond_inheritance/Runner.cpp
        09_diamond_inheritance/Runner.h
        09_diamond_inheritance/Duck.cpp
        09_diamond_inheritance/Duck.h)

add_executable(10_access_specifiers
        10_access_specifiers/main.cpp
        10_access_specifiers/BankAccount.cpp
        10_access_specifiers/BankAccount.h
        10_access_specifiers/SavingsAccount.cpp
        10_access_specifiers/SavingsAccount.h)

add_executable(11_main_wrapup
        11_main_wrapup/main.cpp
        11_main_wrapup/Book.cpp
        11_main_wrapup/Book.h
        11_main_wrapup/Catalog.cpp
        11_main_wrapup/Catalog.h)
add_executable(Lab3
        Lab3/ArrayList.h
        Lab3/Data.cpp
        Lab3/Data.h
        Lab3/LinkedList.h
        Lab3/List.h
        Lab3/main.cpp
        Lab3/Node.h
        )