add_executable(
        TestsOfLinuxServer
        TestOfLinuxServerSocket.cpp
)

target_link_libraries(
        TestsOfLinuxServer PRIVATE
        GTest::GTest
        ClientSocket
        ServerSocket
        FindLocalIp
)

include(GoogleTest)
gtest_discover_tests(TestsOfLinuxServer)
