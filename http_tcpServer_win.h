// server implementation
#ifndef INCLUDED_HTTP_TCPSERVER_LINUX
#define INCLUDED_HTTP_TCPSERVER_LINUX

#include <cstdio>
// inclure la librairie socket
#include <winsock.h>;
#include <cstdlib>
#include <string>;

namespace http {
    class TcpServer {
    public:
        TcpServer(std::string ip_address, int port);
        ~TcpServer();

        void startListen();

    private:
        std::string m_ip_address;
        int m_port;
        SOCKET m_socket;
        SOCKET m_new_socket;
        long m_incomingMessage;
        struct sockaddr_in m_socketAddress;
        int m_socketAddress_len;
        std::string m_serverMessage;
        WSAData m_wsaData{};

        int startServer();

        void closeServer() const;

        void acceptConnection(SOCKET &new_socket);

        std::string buildResponse();

        void sendResponse();
    };
} // namespace http
#endif