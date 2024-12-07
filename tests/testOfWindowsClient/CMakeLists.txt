add_executable(
        TestsOfWindowsClient
        TestsOfWindowsClientSocket.cpp
)

target_link_libraries(
        TestsOfWindowsClient PRIVATE
        GTest::GTest
        ClientSocket
        ServerSocket
)

include(GoogleTest)
gtest_discover_tests(TestsOfWindowsClient)