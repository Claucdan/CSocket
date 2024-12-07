# CSocket
## Languages and Tools in Project
![My Skills](https://skillicons.dev/icons?i=c,cpp,cmake,git&theme=light)
***
## Basic information
This project was made to adapt the work with sockets on different platforms. 
The project also uses CMake to create libraries and test
***
## Client Socket
* ```int Configuration(int protocol)``` - this method is needed to configure the socket and prepare it for operation
* ```int Connect(const int port, const char* address)``` - this method is needed to connect to another user's socket
* ```int Send(const void* data, const int size)``` - This method is needed to send data over the selected protocol in the configuration
* ```int Receive(const void* data, const int size)``` - this method is needed to receive data sent by another user or server
