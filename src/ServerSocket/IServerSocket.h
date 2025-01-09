#ifndef CSOCKET_ISERVERSOCKET_H
#define CSOCKET_ISERVERSOCKET_H

#include "../SocketDefinitionTypes.h"
#include "../ClientSockets/IClientSocket.h"

class IServerSocket{
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
    virtual int Bind(const int port, const char* address) = 0;

    /**
     * Allows socket to listen for connections
     * @param Maximum number of pending connections in queue
     * @return 0 if successul or SOCKET_ERROR  if failed
     */
    virtual int Listen(int backLog) = 0;

    /**
     * Connect permits an incoming connection request to the socket
     * @return Socket object with newly created SOCKET if successful
     */
    virtual IClientSocket* Accept() = 0;

    /**
     * Close the socket connection
     */
    virtual void Close() = 0;
};

#endif //CSOCKET_ISERVERSOCKET_H
