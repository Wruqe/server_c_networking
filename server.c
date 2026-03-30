#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define PORT "3000" 
#define BACKLOG 1

int main(void){
    struct addrinfo hints, *res;
    int status;
    int socketfd;
    int new_fd; 
    
    memset(&hints, 0, sizeof(hints)); 
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; 

    status = getaddrinfo(NULL, PORT, &hints, &res);

    if (status != 0){
        fprintf(stderr, "gai error: %s\n", gai_strerror(status));
        return 1;
    }; 

    socketfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (socketfd == -1){
            perror("socket error");
            return 1; 
    }
    

    if((bind(socketfd, res->ai_addr, res->ai_addrlen)) != 0){
            perror("bind");
            return 1; 
    }

    if((listen(socketfd,BACKLOG )) != 0){
        perror("listen");
        return 1;
    } else {
        printf("The server is now listening on %s \n", PORT);
    }
   for (;;){
       new_fd = accept(socketfd, NULL, NULL);
       if (new_fd == -1){
           perror("accept");
           return 1;  
       }
       // im putting this here to kind of sim what heavy thread blocking would look like
       sleep(8);
       printf("I got a connection \n");

       char buffer[1024];
       int numbytes = recv(new_fd, buffer, sizeof(buffer) -1, 0);

       if (numbytes == -1){
           perror("recv");
           return 1;
       }
       buffer[numbytes] = '\0';

       char *response =
           "HTTP/1.1 200 OK\r\n"
           "Content-Type: text/plain\r\n"
           "Content-Length: 14\r\n"
           "\r\n"
           "Hello, world!\n";

       if (send(new_fd, response, strlen(response),0) == -1) {
           perror("send");
           return 1; 
       }
       close(new_fd); 
   } 


    return 0;
}
