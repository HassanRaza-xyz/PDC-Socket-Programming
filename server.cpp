#include <iostream>
#include <winsock2.h> // Windows specific socket header

#pragma comment(lib, "ws2_32.lib") // Library link karne ke liye

int main() {
    WSADATA wsa;
    SOCKET server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Winsock initialize karna
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Socket create karna
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind karna
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    
    // Listen karna
    listen(server_fd, 3);
    std::cout << "Server listening on port 8080 (Windows)...\n";

    // Client connection accept karna
    new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    
    // Data receive karna
    recv(new_socket, buffer, 1024, 0);
    std::cout << "Message from client: " << buffer << "\n";

    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();
    return 0;
}