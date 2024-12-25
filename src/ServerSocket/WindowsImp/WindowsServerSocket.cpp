#include "WindowsServerSocket.h"
#include <WindowsClientSocket.h>

int WindowsServerSocket::Configuration(int protocol) {
    WSAData wsaData;
    if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
        return INVALID_SOCKET;

    _socket = ::socket(AF_INET, SOCK_STREAM, protocol);
    if (_socket == INVALID_SOCKET) {
        Close();
        return INVALID_SOCKET;
    }
    return 0;
}

int WindowsServerSocket::Bind(const int port, const char *address) {
    _addrIn.sin_family = AF_INET;
    _addrIn.sin_addr.s_addr = htonl(INADDR_ANY);
    _addrIn.sin_port = htons(port);

    if (::bind(_socket, (sockaddr*)&_addrIn, sizeof(_addrIn)) == SOCKET_ERROR)
        return SOCKET_ERROR;
    return 0;
}

int WindowsServerSocket::Listen(int backLog) {
    if (::listen(_socket, backLog) == SOCKET_ERROR)
        return SOCKET_ERROR;
    return 0;
}

IClientSocket *WindowsServerSocket::Accept() {
    SOCKET client;
    client = ::accept(_socket, nullptr, nullptr);

    if (client == INVALID_SOCKET)
        return nullptr;

    WindowsClientSocket* clientSocket = new WindowsClientSocket;
    clientSocket->Configuration(client);
    return clientSocket;
}

void WindowsServerSocket::Close() {
    ::closesocket(_socket);
}
