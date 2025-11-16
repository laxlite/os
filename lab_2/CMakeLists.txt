cmake_minimum_required(VERSION 3.25) # добавлена переменная LINUX 
project(hello_library LANGUAGES CXX)

set(CMAKE_C_STANDARD 11)

add_library(
    process_runner
    SHARED
)
# определяем переменные в зависимости от платформы
if(WIN32)
    set(PLATFORM windows)
    target_sources(process_runner PRIVATE ${CMAKE_SOURCE_DIR}/src/run_process-windows.cpp)
elseif(LINUX)
    set(PLATFORM linux)
    target_sources(process_runner PRIVATE ${CMAKE_SOURCE_DIR}/src/run_process-linux.cpp)
endif()

add_executable(
    app
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

target_include_directories(
    app
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
target_include_directories(
    process_runner
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(
    app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_NAME_RELEASE "app-${PLATFORM}-release"
    RUNTIME_OUTPUT_NAME_DEBUG "app-${PLATFORM}-debug"
)
set_target_properties(
    process_runner PROPERTIES 
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
    LIBRARY_OUTPUT_NAME_RELEASE "process_runner-${PLATFORM}-release"
    LIBRARY_OUTPUT_NAME_DEBUG "process_runner-${PLATFORM}-debug"
)
target_link_libraries(
    app 
    PRIVATE
    process_runner
)

target_compile_options(process_runner PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(app PRIVATE -Wall -Wextra -Wpedantic)