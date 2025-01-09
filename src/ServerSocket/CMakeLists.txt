if (WIN32)
    add_library(
            ServerSocket STATIC
            IServerSocket.h
            WindowsImp/WindowsServerSocket.h
            WindowsImp/WindowsServerSocket.cpp
            ServerSocket.h
    )
    target_link_libraries(
            ServerSocket PRIVATE
            ClientSocket
    )
    target_include_directories(
            ServerSocket PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}"
    )
endif ()
if(UNIX)
    add_library(
            ServerSocket STATIC
            IServerSocket.h
            LinuxImp/LinuxServerSocket.h
            LinuxImp/LinuxServerSocket.cpp
            ServerSocket.h
    )
    target_link_libraries(
            ServerSocket PRIVATE
            ClientSocket
    )
    target_include_directories(
            ServerSocket PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}"
    )
endif()