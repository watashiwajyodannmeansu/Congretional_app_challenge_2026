#ifndef EXIT_FAILIURE
    #include <sys/types.h>
#endif
#ifndef socket
    #include <sys/socket.h>
#endif
#ifndef perror
    #include <stdio.h>
#endif
#ifndef htons
    #include <netinet/in.h>
#endif
#include <arpa/inet.h>

int mkrawtcpsocket() {
    int sockfd = socket(AF_INET6, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    return sockfd;
}

int mkrawudpsocket() {
    int sockfd = socket(AF_INET6, SOCK_RAW, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    return sockfd;
}

int bindsocket(int fd, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any address
    server_addr.sin_port = htons(port); // Specify the port number

    bind(fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    return 0;
}

struct sockaddr_in acceptsocket(int fd, int *outfd) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    *outfd = accept(fd, (struct sockaddr *)&client_addr, &client_len);
    return client_addr;
}