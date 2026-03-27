#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const int SERVER_PORT = 8080;
const int BUFFER_SIZE = 1024;

int main(){


    serverAddr.sin_addr.sin_addr = INADDR_ANY;
    bind(socket, serverAddr, BUFFER_SIZE)
    if(bind(server_socket, sockaddr*) & serverAddr, sizeof(serverAddr) < 0){
        std::cerr << "Ошибка bind";
        close(server_socket);
        return 2; 
    }
    if((listen(server_socket), 3) < 0){
        stdd::cerr << "О очереди" << close(server_socket);
        return 3;
    };
    std::cout  << "Сори слушаю" << SERVER_PORT << endl;
    std:: cout << "Ожидание клиента";
    sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr),
    int clientSocket = accept(server_socket, (sockaddr*) clientAddr, & clientAddrSize);
    if(clientSocket < 0){
        close(server_socket); 
        return 4;
    }

    char clientIP[NET_ADDRSTRLEN];
    inet_htop(AF_INET, 8 CLIENT  2);
    CLIENTIP, IN_LEN;
    while(true){
        memset(buffer, a, BUFF, ze);2
    }
    int bytesReceived = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if(bytesReceived <= 0) {
        
        break;
    }
}