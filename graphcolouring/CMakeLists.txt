cmake_minimum_required(VERSION 3.17)
project(graphcolouring)

set(CMAKE_CXX_STANDARD 14)

add_executable(graphcolouring main.cpp List.h ListNode.h Graph.cpp Graph.h)