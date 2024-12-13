cmake_minimum_required(VERSION 2.8)

project(trapezoid_area)

set(SOURCE_EXE src/main.cpp)

set(SOURCE_LIB src/trapezoid_area.cpp)

add_library(trapezoid_area STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(main trapezoid_area Threads::Threads)
