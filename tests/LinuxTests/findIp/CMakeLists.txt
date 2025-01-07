add_library(
        FindLocalIp SHARED
        FindLocalIp.h
        FindLocalIp.cpp
)
target_include_directories(
        FindLocalIp PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
)