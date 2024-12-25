if(WIN32)
    add_library(
            ClientSocket STATIC
            IClientSocket.h
            WinsockImp/WindowsClientSocket.h
            WinsockImp/WindowsClientSocket.cpp
            ../SocketDefinitionTypes.h
    )
    target_link_libraries(ClientSocket wsock32 ws2_32)
    target_include_directories(
            ClientSocket PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}"
            "${CMAKE_CURRENT_SOURCE_DIR}/WinsockImp"
    )
endif()
if(UNIX)
    add_library(
            ClientSocket STATIC
            IClientSocket.h
            ../SocketDefinitionTypes.h
            LinuxImp/LinuxClientSocket.h
            LinuxImp/LinuxClientSocket.cpp
    )
    target_link_libraries(ClientSocket wsock32 ws2_32)
    target_include_directories(
            ClientSocket PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}"
            "${CMAKE_CURRENT_SOURCE_DIR}/LinuxImp"
    )
endif()