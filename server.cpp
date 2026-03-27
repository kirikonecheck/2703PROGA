#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const int SERVER_PORT = 8080;
const int BUFFER_SIZE = 1024;

int main() {
    
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        std::cerr << "Ошибка создания сокета" << std::endl;
        return 1;
    }

    
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    
    if (bind(server_socket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Ошибка bind" << std::endl;
        close(server_socket);
        return 2;
    }

    
    if (listen(server_socket, 3) < 0) {
        std::cerr << "Ошибка listen" << std::endl;
        close(server_socket);
        return 3;
    }

    std::cout << "Сервер слушает порт: " << SERVER_PORT << std::endl;
    std::cout << "Ожидание клиента..." << std::endl;

    
    sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    int clientSocket = accept(server_socket, (struct sockaddr*)&clientAddr, &clientAddrSize);
    
    if (clientSocket < 0) {
        std::cerr << "Ошибка accept" << std::endl;
        close(server_socket);
        return 4;
    }

    char clientIP[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, INET_ADDRSTRLEN);
    std::cout << "Подключен клиент: " << clientIP << std::endl;

    char buffer[BUFFER_SIZE];

    
    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
        if (bytesReceived <= 0) {
            std::cout << "Клиент отключился" << std::endl;
            break;
        }

        std::string message(buffer);
        if (message == "exit") {
            std::cout << "Выход..." << std::endl;
            break;
        }

        std::string response;
        if (message == "ping") {
            response = "pong";
        } else {
            response = "Неизвестно";
        }

        std::cout << "Получено: " << message << " -> Ответ: " << response << std::endl;
        send(clientSocket, response.c_str(), response.length(), 0);
    }

    close(clientSocket);
    close(server_socket);
    return 0;
}