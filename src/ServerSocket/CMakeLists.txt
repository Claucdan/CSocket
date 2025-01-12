if(WIN32)
    add_library(
            ServerSocket STATIC
            ServerSocket.h
            IServerSocket.h
            WindowsImp/WindowsServerSocket.h
            WindowsImp/WindowsServerSocket.cpp
    )
    target_link_libraries(
            ServerSocket PRIVATE
            wsock32
            ws2_32
            ClientSocket)
    target_include_directories(
            ServerSocket PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}"
    )
else ()
    add_library(
            ServerSocket STATIC
            ServerSocket.h
            IServerSocket.h
            LinuxImp/LinuxServerSocket.h
            LinuxImp/LinuxServerSocket.cpp
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
