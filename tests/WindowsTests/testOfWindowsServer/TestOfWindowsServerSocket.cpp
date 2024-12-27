#include <gtest/gtest.h>
#include "WindowsImp/WindowsServerSocket.h"
#include "WinsockImp/WindowsClientSocket.h"

char* localhost;

TEST(TestsOfWindowsServerSocket, Creation){
    IServerSocket* serverSocket;
    EXPECT_NO_THROW(serverSocket = new WindowsServerSocket());
}

TEST(TestsOfServerWindowsSocket, Configure){
    IServerSocket* serverSocket = new WindowsServerSocket();
    EXPECT_NO_THROW(serverSocket->Configuration(IPPROTO_TCP));
    serverSocket->Close();
}

TEST(TestsOfServerWindowsSocket, Bind){
    IServerSocket* serverSocket = new WindowsServerSocket();

    serverSocket->Configuration(IPPROTO_TCP);

    EXPECT_EQ(serverSocket->Bind(35098,localhost), 0);
    serverSocket->Close();
}

TEST(TestsOfServerWindowsSocket, Listen){
    IServerSocket* serverSocket = new WindowsServerSocket();

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(12498, localhost);

    EXPECT_EQ(serverSocket->Listen(1), 0);
    serverSocket->Close();
}

TEST(TestsOfServerWindowsSocket, Accept){
    IServerSocket* serverSocket = new WindowsServerSocket();
    IClientSocket* clientSocket = new WindowsClientSocket();

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(12498, localhost);
    serverSocket->Listen(1);
    clientSocket->Configuration(IPPROTO_TCP);
    clientSocket->Connect(12498, localhost);


    EXPECT_NO_THROW(serverSocket->Accept());
    clientSocket->Close();
    serverSocket->Close();
}

TEST(TestOfServerWindowsSocket, Recive){
    IServerSocket* serverSocket = new WindowsServerSocket();
    IClientSocket* clientSocket = new WindowsClientSocket();
    char data = 0,
         reciveData = 1;

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(12498, localhost);
    serverSocket->Listen(1);
    clientSocket->Configuration(IPPROTO_TCP);
    clientSocket->Connect(12498, localhost);
    IClientSocket* acceptSocket = serverSocket->Accept();
    clientSocket->Send(&data, sizeof(char));

    EXPECT_NO_THROW(acceptSocket->Receive(&reciveData, sizeof(char)));
    clientSocket->Close();
    serverSocket->Close();
}

TEST(TestOfServerWindowsSocket, ReciveAndCheckData){
    IServerSocket* serverSocket = new WindowsServerSocket();
    IClientSocket* clientSocket = new WindowsClientSocket();
    char data = 0,
            reciveData = 1;

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(12498, localhost);
    serverSocket->Listen(1);
    clientSocket->Configuration(IPPROTO_TCP);
    clientSocket->Connect(12498, localhost);
    IClientSocket* acceptSocket = serverSocket->Accept();
    clientSocket->Send(&data, sizeof(char));
    acceptSocket->Receive(&reciveData, sizeof(char));

    EXPECT_EQ(data, reciveData);
    clientSocket->Close();
    serverSocket->Close();
}





int main(int argc, char* argv[]){
    WSADATA wsaData;
    if (!WSAStartup(WINSOCK_VERSION, &wsaData))
    {
        char chInfo[64];
        if (!gethostname(chInfo, sizeof(chInfo)))
        {
            struct hostent *sh;
            sh=gethostbyname((char*)&chInfo);
            if (sh!=NULL)
            {
                struct sockaddr_in adr;
                memcpy(&adr.sin_addr, sh->h_addr_list[0], sh->h_length);
                localhost = inet_ntoa(adr.sin_addr);
            }
        }
    }
    WSACleanup();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
