cmake_minimum_required(VERSION 3.7)
project(LinuxC C)
set(CMAKE_C_STANDARD 99)
add_executable(Server ./socket/server.c)
add_executable(Client ./socket/client.c)
add_executable(Define ./define/main.c)
add_executable(Test ./algorithm/test.c)
add_subdirectory(CPPProject)





