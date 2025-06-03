#include <stdio.h>              // printf(), perror()
#include <stdlib.h>             // exit()
#include <string.h>             // memset()
//#include <unistd.h>             // close()
//#include <arpa/inet.h>          // inet_pton()
#include <sys/socket.h>         // socket(), connect()
#include <netinet/in.h>         // sockaddr_in


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP> <PORT>", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);    // convert string to integer

    printf("IP_ADDRESS: %s, PORT: %d\n", ip_address, port);

    // 1. Create socket
    // AF_INET - Address Family Internet, SOCK STREAM - TCP
    int sock = socket(AF_INET, SOCK_STREAM, 0);  // TCP
    printf("SOCK: %d\n", sock);
    if (sock < 0) {
        perror("Socket creation failed.");
        return 1;
    }

    // 2. Setup server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));  // zero the struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);            // convert to network byte order

    printf("Sin Family: %d\n", server_addr);


    

    
    
    return 0;
}