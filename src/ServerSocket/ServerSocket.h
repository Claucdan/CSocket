#ifndef CSOCKET_SERVERSOCKET_H
#define CSOCKET_SERVERSOCKET_H

#include "../SocketDefinitionTypes.h"

#if WIN32
#include "WindowsImp/WindowsServerSocket.h"
#else
#include "LinuxImp/LinuxServerSocket.h"
#endif


#endif //CSOCKET_SERVERSOCKET_H
