#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const char* SERVER_IP = "127.0.0.1";
const int SERVER_PORT = 8080;
const int BUFFER_SIZE = 1024;

int main() {
    
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0); 
    if (clientSocket < 0) {
        std::cerr << "Ошибка создания сокета" << std::endl;
        return 1;
    }
    std::cout << "Сокет создан" << std::endl;

    
    sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr)); 
    serverAddr.sin_family = AF_INET;           
    serverAddr.sin_port = htons(SERVER_PORT);
    
    
    if (inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr) <= 0) {
        std::cerr << "Неверный адрес" << std::endl;
        close(clientSocket);
        return 3;
    }

    
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Ошибка соединения" << std::endl;
        close(clientSocket);
        return 2;
    }
    std::cout << "УРА! коннект!!!" << std::endl;


    for (int i = 0; i <= 4; i++) {
        std::string message = "ping";
        send(clientSocket, message.c_str(), message.length(), 0);
        
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        
        
        int bytesRecieved = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
        if (bytesRecieved > 0) {
            std::cout << "Ответ от сервера: " << buffer << std::endl;
        }
        
        sleep(1); 
    }

    
    send(clientSocket, "exit", 4, 0);
    close(clientSocket);
    
    return 0; 
}