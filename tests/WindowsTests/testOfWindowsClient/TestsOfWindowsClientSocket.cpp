#include <gtest/gtest.h>
#include <ClientSocket.h>
#include <ServerSocket.h>

char* localhost;

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