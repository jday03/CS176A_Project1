//
// Created by juliann on 4/16/2018.
//



#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main() {

    int socketIdentifier;
    sockaddr_in serverDetails;

    socketIdentifier = socket(AF_INET, SOCK_STREAM, 0);
    serverDetails.sin_addr.s_addr = inet_addr("74.125.235.20");

}