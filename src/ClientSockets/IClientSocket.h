#ifndef CSOCKET_ICLIENTSOCKET_H
#define CSOCKET_ICLIENTSOCKET_H

#include "../SocketDefinitionTypes.h"

class IClientSocket{
public:
    /**
     * Configuration socket before start work
     * @return 0 if successful or INVALID_SOCKET if failure
     */
    virtual int Configuration(int protocol) = 0;

    /**
     * Connects socket to target
     * @param Port to connect to
     * @param IP Address to connect to
     * @return 0 if successful or SOCKET_ERROR if failure
     */
    virtual int Connect(const int port, const char* address) = 0;

    /**
     * Send data to connected socket
     * @param data ptr for data
     * @param SizeOfData size of send data
     * @return 0 if successful or SOCKET_ERROR id failure
     */
    virtual int Send(const void* data, const int size) = 0;

    /**
     * Receive data from connected socket
     * @param data ptr for data
     * @param SizeOfData size of send data
     * @return 0 if successful or INVALID_SOCKET id failure
     */
    virtual int Receive(const void* data, const int size) = 0;

    /**
     * Close the socket connection
     */
    virtual void Close() = 0;
};

#endif //CSOCKET_ICLIENTSOCKET_H
