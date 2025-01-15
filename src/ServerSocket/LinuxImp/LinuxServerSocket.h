#ifndef CSOCKET_LINUXSERVERSOCKET_H
#define CSOCKET_LINUXSERVERSOCKET_H

#include "../IServerSocket.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


class LinuxServerSocket : public IServerSocket{
private:
    int _socket;
    sockaddr_in _sockAddr;
    int _protocol;
public:
    int Configuration(int protocol) override;
    int Bind(const int port, const char* address) override;
    int Listen(int backLog) override;
    IClientSocket* Accept() override;
    void Close() override;
};


#endif //CSOCKET_LINUXSERVERSOCKET_H
