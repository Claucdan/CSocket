#include "LinuxServerSocket.h"
#include <ClientSocket.h>

int LinuxServerSocket::Configuration(int protocol) {
    _socket = socket(AF_INET, SOCK_STREAM, protocol);
    if (_socket == INVALID_SOCKET){
        Close();
        return INVALID_SOCKET;
    }
    return 0;
}

int LinuxServerSocket::Bind(const int port, const char *address) {
    _sockAddr.sin_family = AF_INET;
    if (!address[0])
        _sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    else
        _sockAddr.sin_addr.s_addr = inet_addr(address);
    _sockAddr.sin_port = htons(port);

    if (bind(_socket, (sockaddr*)&_sockAddr, sizeof(_sockAddr)) == SOCKET_ERROR)
        return SOCKET_ERROR;
    return 0;
}

int LinuxServerSocket::Listen(int backLog) {
    if (listen(_socket, backLog) == SOCKET_ERROR)
        return SOCKET_ERROR;
    return 0;
}

IClientSocket *LinuxServerSocket::Accept() {
    int client;
    client = accept(_socket, nullptr, nullptr);

    if (client == INVALID_SOCKET)
        return nullptr;

    LinuxClientSocket* clientSocket = new LinuxClientSocket();
    clientSocket->lConfiguration(client);
    return clientSocket;
}

void LinuxServerSocket::Close() {
    close(_socket);
}
