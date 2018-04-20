#include <stdio.h>
// Server side C/C++ program to demonstrate Socket programming
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <iostream>
#define PORT 8080



void askUser(int *port, char* address, char* command ){
  //  printf("Enter server name or IP address: ");
  //  scanf("%s", address);

  //  printf("Enter port:");
  //  scanf("%d", port);
    printf("Enter command:");
    //scanf("%s", command);
    size_t comSize = 200 * sizeof(char);
    getline(&command,&comSize,stdin);

}

FILE* receiveFile(int socketDescriptor, char* fileName){
    FILE * newFile= fopen(fileName,"w");

    int messagesRemaining;
    const int bufferSize= 1024;
    const int firstBufferSize = bufferSize+1;
    char* buffer=(char*)malloc(firstBufferSize*sizeof(char));


        if(recv(socketDescriptor,buffer,bufferSize*sizeof(char) , 0) < 0){
            printf ("receive failure\n");
            exit(1);
        }

    messagesRemaining = (int)buffer[0];
    char* fullBuffer = (char*)malloc(messagesRemaining*bufferSize*sizeof(char));

    for(int i = 0;i < bufferSize;++i ){
        fullBuffer[i]=buffer[i+1];
    }

    free(buffer);
    buffer = (char*)malloc(bufferSize*sizeof(char));

    --messagesRemaining;
    while(messagesRemaining > 0){

        if(recv(socketDescriptor,buffer,bufferSize*sizeof(char) , 0) < 0){
            printf ("receive failure\n");
            exit(1);
        }

        for(int i = 0;i < bufferSize;++i ){
            fullBuffer[i]=buffer[i];
        }

        --messagesRemaining;
    }

    //}while()
    fprintf(newFile,"%s",fullBuffer);
    return newFile;
}
//assuming that buffer is empty


char* parseCommand(char*command){

    int specialCharIndex = strstr(command,">");

}


int main() {

    int* port = malloc(sizeof(int));
    char* addressInput = malloc(100* sizeof(char));
    char* command = malloc(200* sizeof(char));
    askUser(port,addressInput,command);
    *port = 8080;

    int socketIdentifier;
    struct sockaddr_in address;

    memset(&address, '0', sizeof(address));
    socketIdentifier = socket(AF_INET, SOCK_STREAM, 0);

    if(socketIdentifier < 0){
        printf ("socket creation failure\n");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr)<=0)
    {
        printf("Invalid address \n");
        exit(1);
    }





    printf("port is: %d ", address.sin_port);


    if (connect(socketIdentifier, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("\nConnection Failed \n");
        exit(1);
    }


    if(send(socketIdentifier ,(char*) command,(size_t) 200* sizeof(*command) , 0 ) < 0){
        printf("\nsend Failed \n");
        exit(1);

    }


/*    if(recv(socketIdentifier,  &file, 200*sizeof(file), 0) < 0){
        printf ("receive failure\n");
        exit(1);
    }

    char fileCopy[300];
    fgets((char*)fileCopy,100,(FILE*)&file );
    printf("received: %s \n",fileCopy);
*/

    return 0;
}