cmake_minimum_required(VERSION 3.10)
project(MasterWorker)

set(CMAKE_CXX_STANDARD 17)

add_executable(master
   src/master.cpp
)


find_package(Threads REQUIRED)
target_link_libraries(master Threads::Threads)

find_package(OpenSSL REQUIRED)
target_link_libraries(master OpenSSL::SSL)
