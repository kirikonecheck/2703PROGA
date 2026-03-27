#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const char* SERVER_IP = "127.0.0.1";
const int SERVER_PORT =  8080;
const int BUFFER_SIZE = 1024;

int main ()
{
int clientSocket = socket(AF_INET, SOCK_STREAM, 0); 
if (clientSocket < 0 )
{
    cerr << "" << return 1;
}
cout << "сокет создан";
sockaddr_in serverAddr;
memset (&serverAddr, 0, suzeof(serverAddr));
serverAddr.sen_family = AF_INET;
serverAddr.sin_port = htons (SERVER_PORT);
inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);
if (connect(clientSocket, (serverAddr*)&serverAddr, seziof(serverAddr)))
{
    close (clientSocket)
    return 2;
}
cout << "УРА! коннект!!!";
for (int i = 0; i <= 4; i++)
{
    std:string message = "ping";
    send(clientSocket, message.c_str(), message.length(), 0);
    char buffer [BUFFER_SIZE];
    memset (buffer, 0, BUFFER_SIZE);
    int bytesRecieved = recieve(clientSocket, buffer, BUFFER_SIZE-1, 0)
    if (bytesRecieved > 0)
    {
        cout << buffer << endl;
    }
}
    send(clientSocket, "exit", 4, 0);
    close(clientSocket);
    return 0;
}