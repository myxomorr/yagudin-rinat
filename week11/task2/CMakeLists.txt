cmake_minimum_required(VERSION 3.10)

# Указываем имя проекта
project(EntropyCalculator)

# Источники для библиотеки и исполнимого файла
set(SOURCE_EXE src/main.cpp)
set(SOURCE_LIB src/entropy_calculator.cpp)

# Создаем статическую библиотеку
add_library(entropy_calculator STATIC ${SOURCE_LIB})

# Создаем исполнимый файл
add_executable(main ${SOURCE_EXE})

# Найти потоки для многозадачности
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Линкуем библиотеку и потоки с исполнимым файлом
target_link_libraries(main entropy_calculator Threads::Threads)
