cmake_minimum_required(VERSION 3.26)
project(helloWorld)

set(CMAKE_CXX_STANDARD 23)

add_executable(helloWorld main.cpp
        http_tcpServer_linux.h
        server_linux.cpp
        http_tcpServer_linux.cpp)
