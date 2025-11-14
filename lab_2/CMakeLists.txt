cmake_minimum_required(VERSION 3.16)
project(hello_library LANGUAGES C)

set(CMAKE_C_STANDARD 11)

add_library(
    proccess_runner
    src/start_process
)