#include <gtest/gtest.h>
#include <ClientSocket.h>
#include <ServerSocket.h>
#include <FindLocalIp.h>

char* localhost;


TEST(TestsOfLinuxServerSocket, Creation){
    IServerSocket* serverSocket;
    EXPECT_NO_THROW(serverSocket = new LinuxServerSocket());
    serverSocket->Close();
}

TEST(TestsOfServerLinuxSocket, Configure){
    IServerSocket* serverSocket = new LinuxServerSocket();
    EXPECT_NO_THROW(serverSocket->Configuration(IPPROTO_TCP));
    serverSocket->Close();
}

TEST(TestsOfServerLinuxSocket, Bind){
    IServerSocket* serverSocket = new LinuxServerSocket();

    serverSocket->Configuration(IPPROTO_TCP);

    EXPECT_EQ(serverSocket->Bind(35098,localhost), 0);
    serverSocket->Close();
}

TEST(TestsOfServerLinuxSocket, Listen){
    IServerSocket* serverSocket = new LinuxServerSocket();

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(12498, localhost);

    EXPECT_EQ(serverSocket->Listen(1), 0);
    serverSocket->Close();
}

TEST(TestsOfServerLinuxSocket, Accept){
    IServerSocket* serverSocket = new LinuxServerSocket();
    IClientSocket* clientSocket = new LinuxClientSocket();

    serverSocket->Configuration(IPPROTO_TCP);
    serverSocket->Bind(12498, localhost);
    serverSocket->Listen(1);
    clientSocket->Configuration(IPPROTO_TCP);
    clientSocket->Connect(12498, localhost);


    EXPECT_NO_THROW(serverSocket->Accept());
    clientSocket->Close();
    serverSocket->Close();
}

TEST(TestOfServerLinuxSocket, Recive){
    IServerSocket* serverSocket = new LinuxServerSocket();
    IClientSocket* clientSocket = new LinuxClientSocket();
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

int main(int argc, char* argv[]){
    localhost = findLocalIp();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
