add_subdirectory(ClientSockets)
add_subdirectory(ServerSocket)


add_library(
        CSocket STATIC
        CSocket.h
)
target_link_libraries(
        CSocket
        ClientSocket
        ServerSocket
)
target_include_directories(
        CSocket PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

#[===[
if(WIN32)
    add_library(
            CSocket STATIC
            CSocket.h
            SocketDefinitionTypes.h
            ClientSockets/IClientSocket.h
            ClientSockets/WinsockImp/WindowsClientSocket.h
            ClientSockets/WinsockImp/WindowsClientSocket.cpp
            ServerSocket/IServerSocket.h
            ServerSocket/WindowsImp/WindowsServerSocket.h
            ServerSocket/WindowsImp/WindowsServerSocket.cpp
    )
    target_link_libraries(CSocket wsock32 ws2_32)
    target_include_directories(
            CSocket PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}"
    )
endif()
if(UNIX)
    add_library(
            CSocket STATIC
            CSocket.h
            SocketDefinitionTypes.h
            ClientSockets/IClientSocket.h
            ClientSockets/LinuxImp/LinuxClientSocket.h
            ClientSockets/LinuxImp/LinuxClientSocket.cpp
            ServerSocket/IServerSocket.h
            ServerSocket/LinuxImp/LinuxServerSocket.h
            ServerSocket/LinuxImp/LinuxServerSocket.cpp
    )
    target_include_directories(
            CSocket PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}"
    )
endif()
]===]