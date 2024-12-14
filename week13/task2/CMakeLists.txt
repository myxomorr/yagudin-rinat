cmake_minimum_required(VERSION 3.10)

project(PasswordCracker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем пути к заголовочным файлам
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/spdlog
)

# Указываем исходные файлы
set(SOURCE_FILES
    src/main.cpp
    src/password_cracker.cpp
)

# Создаем исполнимый файл
add_executable(PasswordCracker ${SOURCE_FILES})

# Ищем библиотеку OpenSSL
find_package(OpenSSL REQUIRED)

# Линковка с OpenSSL и pthread для многозадачности
target_link_libraries(PasswordCracker PRIVATE OpenSSL::Crypto pthread)

# Проверяем поддержку OpenMP
find_package(OpenMP REQUIRED)

# Включаем флаг для компилятора
if(OpenMP_CXX_FOUND)
    target_link_libraries(PasswordCracker PRIVATE OpenMP::OpenMP_CXX)
endif()
