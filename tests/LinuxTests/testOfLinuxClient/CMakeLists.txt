add_executable(
        TestsOfLinuxClient
        TestOfLinuxClientSocket.cpp
)

target_link_libraries(
        TestsOfLinuxClient PRIVATE
        GTest::GTest
        CSocket
        FindLocalIp
)

include(GoogleTest)
gtest_discover_tests(TestsOfLinuxClient)