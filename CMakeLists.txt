cmake_minimum_required(VERSION 3.20)
project(nova VERSION 0.4.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(nova
    src/main.cpp
    src/lexer.cpp
    src/parser.cpp
    src/runtime.cpp
    src/vm.cpp
    src/compiler.cpp
)

target_include_directories(nova PRIVATE include)

if(MSVC)
    target_compile_options(nova PRIVATE /W4 /O2)
else()
    target_compile_options(nova PRIVATE -Wall -Wextra -O2)
endif()
