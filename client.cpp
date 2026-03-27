#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET sock = 0;
    struct sockaddr_in serv_addr;
    const char *message = "Hello Server from Windows";

    WSAStartup(MAKEWORD(2, 2), &wsa);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Server se connect hona
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Message bhejna
    send(sock, message, strlen(message), 0);
    std::cout << "Message sent to server.\n";

    closesocket(sock);
    WSACleanup();
    return 0;
}