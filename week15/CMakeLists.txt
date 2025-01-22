cmake_minimum_required(VERSION 3.10)
project(MasterWorker)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${CMAKE_SOURCE_DIR}/master/include
    ${CMAKE_SOURCE_DIR}/worker/include
)

add_executable(master
    master/src/master.cpp
)

add_executable(worker
    worker/src/worker.cpp
)

find_package(Threads REQUIRED)
target_link_libraries(master Threads::Threads)
target_link_libraries(worker Threads::Threads)

find_package(OpenSSL REQUIRED)
target_link_libraries(master OpenSSL::SSL)
target_link_libraries(worker OpenSSL::SSL)
