if (WIN32)
    add_library(
            ServerSocket STATIC
            IServerSocket.h
            WindowsImp/WindowsServerSocket.h
            WindowsImp/WindowsServerSocket.cpp
    )
    target_link_libraries(
            ServerSocket PRIVATE
            ClientSocket
    )
    target_include_directories(
            ServerSocket PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}"
            "${CMAKE_CURRENT_SOURCE_DIR}/WindowsImp"
    )
endif ()