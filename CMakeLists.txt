cmake_minimum_required(VERSION 3.10)

project(HackAssembler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)

enable_testing()
# Required to enable ctest command
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/download_cxxopt.cmake)

add_subdirectory(src)
add_subdirectory(tests)
