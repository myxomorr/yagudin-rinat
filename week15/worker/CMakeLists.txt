cmake_minimum_required(VERSION 3.14)
project(client)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

add_executable(worker src/worker.cpp)
target_link_libraries(worker crypto)
