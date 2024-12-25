#include <gtest/gtest.h>
#include <LinuxImp/LinuxClientSocket.h>
#include <LinuxImp/LinuxServerSocket.h>

#define localhost "192.168.0.86"

TEST(TestsOfLinuxClientSocket, Creation){
    IClientSocket* clientSocket;
    EXPECT_NO_THROW(clientSocket = new LinuxClientSocket());
    clientSocket->Close();
}

TEST(TestsOfLinuxClientSocket, Configure){
    IClientSocket* clientSocket = new LinuxClientSocket();
    EXPECT_NO_THROW(clientSocket->Configuration(IPPROTO_TCP));
    clientSocket->Close();
}

TEST(TestsOfLinuxClientSocket, Connect){
    IClientSocket* clientSocket = new LinuxClientSocket();
    IServerSocket* serverSocket = new LinuxServerSocket();

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(8950, localhost);
    serverSocket->Listen(1);
    clientSocket->Configuration(IPPROTO_TCP);

    EXPECT_EQ(clientSocket->Connect(8950, localhost), 0);
    clientSocket->Close();
    serverSocket->Close();
}
TEST(TestsOfLinuxClientSocket, Send){
    IClientSocket* clientSocket = new LinuxClientSocket();
    IServerSocket* serverSocket = new LinuxServerSocket();
    char data = 7,
            fakeData =10;

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(8950, localhost);
    serverSocket->Listen(1);
    clientSocket->Configuration(IPPROTO_TCP);
    clientSocket->Connect(8950, localhost);
    clientSocket->Send(&data, sizeof(data));
    EXPECT_NO_THROW(serverSocket->Accept()->Receive(&fakeData, sizeof(char)));
    clientSocket->Close();
    serverSocket->Close();
}

TEST(TestsOfLinuxClientSocket, SendAndCheckData){
    IClientSocket* clientSocket = new LinuxClientSocket();
    IServerSocket* serverSocket = new LinuxServerSocket();
    char data = 7,
            fakeData =10;

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(8950, localhost);
    serverSocket->Listen(1);
    clientSocket->Configuration(IPPROTO_TCP);
    clientSocket->Connect(8950, localhost);
    clientSocket->Send(&data, sizeof(data));
    serverSocket->Accept()->Receive(&fakeData, sizeof(char));

    EXPECT_EQ(data, fakeData);
    clientSocket->Close();
    serverSocket->Close();
}
