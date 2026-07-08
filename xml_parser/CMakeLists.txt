cmake_minimum_required(VERSION 4.2)
project(xml_parser)

set(CMAKE_CXX_STANDARD 20)

add_executable(xml_parser src/main.cpp
        include/xml_parser.hpp
        src/xml_parser.cpp
        include/parse_exception.hpp)
