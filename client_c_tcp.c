#include <stdio.h>
// Server side C/C++ program to demonstrate Socket programming
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define PORT 8080



void askUser(int *port,char* address, char* command ){
  //  printf("Enter server name or IP address: ");
  //  scanf("%s", address);

  //  printf("Enter port:");
  //  scanf("%d", port);
    printf("Enter command:");
    //scanf("%s", command);
    size_t comSize = 200 * sizeof(char);
    getline(&command,&comSize,stdin);

}



int main() {

    int* port = malloc(sizeof(int));
    *port = 8080;
    char* addressInput = malloc(100* sizeof(char));
    char* command = malloc(200* sizeof(char));
   askUser(port,addressInput,command);
    printf("sending: %s \n", command);

    int socketIdentifier;
    int opt = 1;
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

    char basic [3300];
    FILE* file= malloc(200*sizeof(FILE));

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