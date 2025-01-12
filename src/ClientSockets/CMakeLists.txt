if(WIN32)
    add_library(
            ClientSocket STATIC
            ClientSocket.h
            IClientSocket.h
            WinsockImp/WindowsClientSocket.h
            WinsockImp/WindowsClientSocket.cpp
    )
    target_link_libraries(ClientSocket wsock32 ws2_32)
    target_include_directories(
            ClientSocket PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}"
    )
else ()
    add_library(
            ClientSocket STATIC
            ClientSocket.h
            IClientSocket.h
            LinuxImp/LinuxClientSocket.h
            LinuxImp/LinuxClientSocket.cpp
    )
    target_include_directories(
            ClientSocket PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}"
    )

endif ()