#include "LinuxClientSocket.h"


int LinuxClientSocket::Configuration(int protocol) {
    _socket = socket(AF_INET, SOCK_STREAM, protocol);
    _protocol = protocol;
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
    switch(_protocol){
        case IPPROTO_UDP:
            sendto(_socket, (char*)data, size, 0, (const sockaddr*)&_sockAddr, sizeof(_sockAddr));
            break;
        case IPPROTO_TCP:
            if (send(_socket, (char*)data, size, 0 ) == SOCKET_ERROR)
                return SOCKET_ERROR;
            break;
        default:
            return 0;
    }
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

int LinuxClientSocket::lConfiguration(int socket) {
    _socket = socket;
    return 0;
}

