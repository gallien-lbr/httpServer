#include "http_tcpServer_linux.h"

namespace {
    void log(const std::string &message)
    {
        std::cout << message << std::endl;
    }
    void exitWithError(const std::string &errorMessage)
    {
        std::cout << WSAGetLastError() << std::endl;
        log("ERROR: " + errorMessage);
        exit(1);
    }
}

namespace http
{
    TcpServer::TcpServer(std::string ip, int port):
    m_ip_address(ip_address),
    m_port(port),
    m_socket(),
    m_new_socket(),
    m_incomingMessage(),
    m_socketAddress(),
    m_socketAddress_len(sizeof (m_socketAddress)),
    m_serverMessage(buildResponse())
    {
        startServer();
    }
    TcpServer::~TcpServer()
    {
        closeServer();
    }


    //Windows
    int startServer()
    {
        if (WSAStartup(MAKEWORD(2, 0), &m_wsaData) != 0)
        {
            exitWithError("WSAStartup failed");
        }
        m_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (m_socket < 0)
        {
            exitWithError("Cannot create socket");
            return 1;
        }
        return 0;
    }

    void closeServer()
    {
        closesocket(m_socket);
        closesocket(m_new_socket);
        WSACleanup();
        exit(0);
    }
} // namespace http