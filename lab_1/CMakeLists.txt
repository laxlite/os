cmake_minimum_required(VERSION 3.16)
project(hello_world LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11) # указывает стандарт

add_executable(app
    src/main.cpp
	src/print_hello_world.cpp
) # создает исполняемый файл

target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/include) # это как -I, который указывает, где лежат заголовочные файлы
# target_include_directories действует локально (PRIVATE), для указанной цели (app)
# CMAKE_SOURCE_DIR - переенная, указывающая на корень проекта (CmakeLists.txt)

set_target_properties(app PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) # cmake создаст директорию

target_compile_options(app PRIVATE -Wall -Wextra -pedantic) # опции компилятора (аналогично target_include_directories)