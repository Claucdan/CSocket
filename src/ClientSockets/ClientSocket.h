#ifndef CSOCKET_CLIENTSOCKET_H
#define CSOCKET_CLIENTSOCKET_H

#include "IClientSocket.h"
#include "../SocketDefinitionTypes.h"

#if WIN32
#include "WinsockImp/WindowsClientSocket.h"
#else
#include "LinuxImp/LinuxClientSocket.h"
#endif

#endif //CSOCKET_CLIENTSOCKET_H
