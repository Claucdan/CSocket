#include "WindowsClientSocket.h"

int WindowsClientSocket::Configuration(int protocol) {
    WSAData wsaData;
    if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0){
        return INVALID_SOCKET;
    }

    _socket = ::socket(AF_INET,SOCK_STREAM, protocol);
    if (_socket == INVALID_SOCKET){
        Close();
        return INVALID_SOCKET;
    }
    return 0;
}

int WindowsClientSocket::Connect(const int port, const char *address) {
    _addrIn.sin_family = AF_INET;
    _addrIn.sin_addr.s_addr = inet_addr(address);
    _addrIn.sin_port = htons(port);

    if (::connect(_socket, (sockaddr*)&_addrIn, sizeof(_addrIn)) == SOCKET_ERROR) {
        Close();
        return SOCKET_ERROR;
    }
    return 0;
}

int WindowsClientSocket::Send(const void *data, const int size) {
    if (::send(_socket, (char*)data, size, 0 ) == SOCKET_ERROR)
        return SOCKET_ERROR;
    return 0;
}

int WindowsClientSocket::Receive(const void *data, const int size) {
    if (::recv(_socket, (char*)data, size, 0) == SOCKET_ERROR)
        return SOCKET_ERROR;
    return 0;
}

void WindowsClientSocket::Close() {
    ::closesocket(_socket);
}

int WindowsClientSocket::Configuration(SOCKET socket) {
    _socket = socket;
    return 0;
}