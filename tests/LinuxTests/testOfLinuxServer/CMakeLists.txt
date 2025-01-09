add_executable(
        TestsOfLinuxServer
        TestOfLinuxServerSocket.cpp
)

target_link_libraries(
        TestsOfLinuxServer PRIVATE
        GTest::GTest
        CSocket
        FindLocalIp
)

include(GoogleTest)
gtest_discover_tests(TestsOfLinuxServer)
