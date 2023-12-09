cmake_minimum_required(VERSION 3.5)

project(LogViewer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

LINK_DIRECTORIES(/usr/lib/x86_64-linux-gnu)

link_libraries(/usr/lib/x86_64-linux-gnu/libncurses.so)

add_executable(LogViewer main.cpp date.h date.cpp time.h time.cpp console.h console.cpp window.h window.cpp structures.h)

install(TARGETS LogViewer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})



