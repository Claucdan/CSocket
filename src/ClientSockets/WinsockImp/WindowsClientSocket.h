#ifndef CSOCKET_WINDOWSCLIENTSOCKET_H
#define CSOCKET_WINDOWSCLIENTSOCKET_H

#include "../IClientSocket.h"
#include <winsock2.h>


class WindowsClientSocket : public IClientSocket{
private:
    SOCKET _socket;
    SOCKADDR_IN _addrIn;
    int _protocol;

public:
    int Configuration(int protocol) override;
    int Connect(const int port, const char* address) override;
    int Send(const void* data, const int size) override;
    int Receive(const void* data, const int size) override;
    void Close() override;

public:
    int Configuration(SOCKET socket, int protocol);
};


#endif //CSOCKET_WINDOWSCLIENTSOCKET_H
