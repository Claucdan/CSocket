add_executable(
        TestsOfWindowsServer
        TestOfWindowsServerSocket.cpp
)

target_link_libraries(
        TestsOfWindowsServer PRIVATE
        GTest::GTest
        CSocket
)

include(GoogleTest)
gtest_discover_tests(TestsOfWindowsServer)



