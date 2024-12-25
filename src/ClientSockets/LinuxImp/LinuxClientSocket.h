#ifndef CSOCKET_LINUXCLIENTSOCKET_H
#define CSOCKET_LINUXCLIENTSOCKET_H

#include "../IClientSocket.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class LinuxClientSocket : public IClientSocket{
private:
    int _socket;
    sockaddr_in _sockAddr;

public:
    int Configuration(int protocol) override;
    int Connect(const int port, const char* address) override;
    int Send(const void* data, const int size) override;
    int Receive(const void* data, const int size) override;
    void Close() override;

public:
    int lConfiguration(int socket);
};


#endif //CSOCKET_LINUXCLIENTSOCKET_H
