cmake_minimum_required(VERSION 3.27)
project(CSocket VERSION 1.0.0
                LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif ()