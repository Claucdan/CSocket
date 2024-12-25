#include <gtest/gtest.h>
#include "WinsockImp/WindowsClientSocket.h"
#include "WindowsImp/WindowsServerSocket.h"

#define localhost "192.168.0.200"

TEST(TestsOfWindowsClienSocket, Creation){
    IClientSocket* clientSocket;
    EXPECT_NO_THROW(clientSocket = new WindowsClientSocket());
    clientSocket->Close();
}

TEST(TestsOfWindowsClienSocket, Configure){
    IClientSocket* clientSocket = new WindowsClientSocket();
    EXPECT_NO_THROW(clientSocket->Configuration(IPPROTO_TCP));
    clientSocket->Close();
}

TEST(TestsOfWindowsClienSocket, Connect){
    IClientSocket* clientSocket = new WindowsClientSocket();
    IServerSocket* serverSocket = new WindowsServerSocket();

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(489, localhost);
    serverSocket->Listen(1);
    clientSocket->Configuration(IPPROTO_TCP);

    EXPECT_EQ(clientSocket->Connect(489, localhost), 0);
    clientSocket->Close();
    serverSocket->Close();
}
TEST(TestsOfWindowsClienSocket, Send){
    IClientSocket* clientSocket = new WindowsClientSocket();
    IServerSocket* serverSocket = new WindowsServerSocket();
    char data = 7,
         fakeData =10;

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(489, localhost);
    serverSocket->Listen(1);
    clientSocket->Configuration(IPPROTO_TCP);
    clientSocket->Connect(489, localhost);
    clientSocket->Send(&data, sizeof(data));
    EXPECT_NO_THROW(serverSocket->Accept()->Receive(&fakeData, sizeof(char)));
    clientSocket->Close();
    serverSocket->Close();
}

TEST(TestsOfWindowsClienSocket, SendAndCheckData){
    IClientSocket* clientSocket = new WindowsClientSocket();
    IServerSocket* serverSocket = new WindowsServerSocket();
    char data = 7,
         fakeData =10;

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(489, localhost);
    serverSocket->Listen(1);
    clientSocket->Configuration(IPPROTO_TCP);
    clientSocket->Connect(489, localhost);
    clientSocket->Send(&data, sizeof(data));
    serverSocket->Accept()->Receive(&fakeData, sizeof(char));

    EXPECT_EQ(data, fakeData);
    clientSocket->Close();
    serverSocket->Close();
}
