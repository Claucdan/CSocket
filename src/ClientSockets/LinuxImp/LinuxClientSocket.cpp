#include "LinuxClientSocket.h"


int LinuxClientSocket::Configuration(int protocol) {
    _protocol = protocol;
    switch (protocol) {
        case IPPROTO_TCP:
            _socket = socket(AF_INET, SOCK_STREAM, protocol);
            break;
        case IPPROTO_UDP:
            _socket = socket(AF_INET, SOCK_DGRAM, protocol);
            break;
        default:
            return INVALID_SOCKET;
    }
    if (_socket == INVALID_SOCKET) {
        Close();
        return INVALID_SOCKET;
    }
    return 0;
}

int LinuxClientSocket::Connect(const int port, const char *address) {
    _sockAddr.sin_family = AF_INET;
    _sockAddr.sin_addr.s_addr = inet_addr(address);
    _sockAddr.sin_port = htons(port);

    if (connect(_socket, (sockaddr*)&_sockAddr, sizeof(_sockAddr)) == SOCKET_ERROR) {
        Close();
        return SOCKET_ERROR;
    }
    return 0;
}

int LinuxClientSocket::Send(const void *data, const int size) {
    if (send(_socket, (char*)data, size, 0 ) == SOCKET_ERROR)
        return SOCKET_ERROR;
    return 0;
}

int LinuxClientSocket::Receive(const void *data, const int size) {
    if (recv(_socket, (char*)data, size, 0 ) == SOCKET_ERROR)
        return SOCKET_ERROR;
    return 0;
}

void LinuxClientSocket::Close() {
    close(_socket);
}

int LinuxClientSocket::Configuration(int socket, int protocol) {
    _protocol = protocol;
    _socket = socket;
    return 0;
}

