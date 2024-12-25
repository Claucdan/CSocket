add_executable(
        TestsOfWindowsServer
        TestOfWindowsServerSocket.cpp
)

target_link_libraries(
        TestsOfWindowsServer PRIVATE
        GTest::GTest
        ClientSocket
        ServerSocket
)

include(GoogleTest)
gtest_discover_tests(TestsOfWindowsServer)



