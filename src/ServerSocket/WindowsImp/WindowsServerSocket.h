#ifndef CSOCKET_WINDOWSSERVERSOCKET_H
#define CSOCKET_WINDOWSSERVERSOCKET_H

#include "IServerSocket.h"
#include "winsock2.h"

class WindowsServerSocket : public IServerSocket{
private:
    SOCKET _socket;
    SOCKADDR_IN _addrIn;
public:
    int Configuration(int protocol) override;
    int Bind(const int port, const char* address) override;
    int Listen(int backLog) override;
    IClientSocket* Accept() override;
    void Close() override;
};


#endif //CSOCKET_WINDOWSSERVERSOCKET_H
