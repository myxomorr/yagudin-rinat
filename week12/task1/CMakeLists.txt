cmake_minimum_required(VERSION 3.14)

project(PrimeCalculator)

set(CMAKE_CXX_STANDARD 17)

# Подключаем FetchContent
include(FetchContent)

# Загружаем spdlog
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.10.0
)

FetchContent_MakeAvailable(spdlog)

# Определение исходных файлов
set(SOURCE_FILES
    src/prime_calculator.cpp
    src/main.cpp
)

# Добавляем библиотеку
add_executable(main ${SOURCE_FILES})

# Линкуем spdlog
target_link_libraries(main spdlog::spdlog)

# Использование потоков
find_package(Threads REQUIRED)
target_link_libraries(main Threads::Threads)
