

#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <stdlib.h>




int main() {

    int socketIdentifier;
    const int port = 8080;
    int opt = 1;
    struct sockaddr_in address;


    socketIdentifier = socket(AF_INET, SOCK_STREAM, 0);

    if(socketIdentifier < 0){
        printf ("socket creation failure\n");

        exit(1);
}


    if(setsockopt(socketIdentifier, SOL_SOCKET,SO_REUSEPORT,&opt, sizeof(opt) ) < 0){

        printf ("socket opt failure\n");
        exit(1);
    }


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( 8080);
    printf("port is: %d ", address.sin_port);

   if( bind(socketIdentifier, (struct sockaddr *)& address,sizeof(address)) < 0){
       printf ("bind failure\n");
       exit(1);
   }

    printf ("LISTENING\n");

    if( listen(socketIdentifier,1) < 0) {
        printf ("listen failure\n");
        exit(1);
    }
    printf("HERE1 \n");
    int addressLength = sizeof(address);

    int new_socket = accept(socketIdentifier,(struct sockaddr *)&address,(socklen_t*)&addressLength);

    if(new_socket < 0){
        printf ("socket acceptance failure\n");
        exit(1);

    }
    printf("HERE2 \n");

    char basic [3000];
    if(recv(new_socket,  &basic, sizeof(basic), 0) < 0){
        printf ("receive failure\n");
        exit(1);
    }



    printf ("%s \n", basic);

    char test[30] = "cat test.txt";
    FILE * ptr = popen((char*)basic,"r");

    while(!feof(ptr)){

    }
    if(send(new_socket,(ptr),(size_t) sizeof(*ptr) , 0 ) < 0){
        printf("\nsend Failed \n");
        exit(1);
    }

}