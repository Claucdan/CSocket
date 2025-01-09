add_executable(
        TestsOfWindowsClient
        TestsOfWindowsClientSocket.cpp
)

target_link_libraries(
        TestsOfWindowsClient PRIVATE
        GTest::GTest
        CSocket
)

include(GoogleTest)
gtest_discover_tests(TestsOfWindowsClient)