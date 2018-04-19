

#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main() {

    int socketIdentifier;
    const int port = 8080;
    int opt = 1;
    sockaddr_in address;
    

    socketIdentifier = socket(AF_INET, SOCK_STREAM, 0);

    if(socketIdentifier < 0){
        std::cout << "socket creation failure" << std::endl;

        exit(1);
}


    if(setsockopt(socketIdentifier, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT,opt, sizeof(opt) ) < 0){

        std::cout << "socket opt failure" << std::endl;
        exit(1);
    }


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( port);

   if( bind(socketIdentifier, (struct sockaddr *)& address,sizeof(address)) < 0){
       std::cout << "bind failure" << std::endl;
       exit(1);
   }


    if( listen(socketIdentifier,1) < 0) {
        std::cout << "listen failure" << std::endl;
        exit(1);
    }

    new_socket = accept(server_fd, (struct sockaddr *)&address,sizeof(address));

}