# CSocket
## Languages and Tools in Project
![My Skills](https://skillicons.dev/icons?i=c,cpp,cmake,git,linux&theme=light)

## Basic information
***
A simple c++ socket library that makes it easier to use sockets on different platforms (Linux and Windows). 
To separate the work with sockets, two socket interfaces are made - the client and the server.
This project was made to adapt the work with sockets on different platforms. 

## Interfaces
***
### Client Socket
* ```int Configuration(int protocol)``` - this method is needed to configure the socket and prepare it for operation
* ```int Connect(const int port, const char* address)``` - this method is needed to connect to another user's socket
* ```int Send(const void* data, const int size)``` - This method is needed to send data over the selected protocol in the configuration
* ```int Receive(const void* data, const int size)``` - this method is needed to receive data sent by another user or server
### Server Socket
* ```int Configuration(int protocol)``` - this method is needed to configure the socket and prepare it for operation
* ```int Bind(const int port, const char* address)``` - this method is needed to bind socket to port, and get data from all or from single address
* ```int Listen(int backlog)``` - This method is needed to allow socket to listen for connections
* ```IClientSocket* Accept()``` - this method is needed to connect permits an incoming connection request to the socket

## Building
***
Building process has been tested using CMake 3.27 and g++ 4.9.2 And library can be build easily as follows:
```bash
git clone https://github.com/Claucdan/CSocket.git
cd ./CSocket/
cmake -S . ./cmake-build
cmake --build .
```

## Using in CMake
***
You can use that library like fetch content in CMake.
```cmake
include(FetchContent)
FetchContent_Declare(
    CSocket
    GIT_REPOSITORY https://github.com/Claucdan/CSocket.git
    GIT_TAG        v1.0.0
)
FetchContent_MakeAvailable(CSocket)
```