#include <stdio.h>
// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <winsock.h>
#include <stdlib.h>
#include <sys/socket>
#include <string.h>
#define PORT 8080



void askUser(int *port,char* address, char* command ){
    printf("Enter server name or IP address: ");
    scanf("%s", address);

    printf("Enter port:");
    scanf("%d", port);

    printf("Enter command:");
    scanf("%s", command);

}



int main() {

    int* port;
    char* address;
    char* command;
    askUser(port,address,command);



    printf("Hello, World!\n");
    return 0;
}