#ifndef CSOCKET_CSOCKET_H
#define CSOCKET_CSOCKET_H

#include "SocketDefinitionTypes.h"

#include "ClientSockets/IClientSocket.h"
#include <ServerSocket/IServerSocket.h>

#if WIN32
#include "ClientSockets/WinsockImp/WindowsClientSocket.h"
#include "ServerSocket/WindowsImp/WindowsServerSocket.h"
#else
#include "ClientSockets/LinuxImp/LinuxClientSocket.h"
#include "ServerSocket/LinuxImp/LinuxServerSocket.h"
#endif

#endif //CSOCKET_CSOCKET_H
