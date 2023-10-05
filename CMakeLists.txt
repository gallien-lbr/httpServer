cmake_minimum_required(VERSION 3.26)
# set the project name
project(httpServer)
set(CMAKE_CXX_STANDARD 23)
add_executable(httpServer server_win.cpp http_tcpServer_win.cpp)
target_link_libraries(httpServer libwsock32.a)