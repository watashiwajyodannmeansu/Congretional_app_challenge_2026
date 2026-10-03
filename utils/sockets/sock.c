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
#ifndef htons
	#include <arpa/inet.h>
#endif
#ifndef close
	#include <unistd.h>
#endif
int mktcpsocket() {
	int sockfd = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0) {
		perror("Socket creation failed");
		exit(1);
	}
	return sockfd;
}

int mkudpsocket() {
	int sockfd = socket(AF_INET6, SOCK_STREAM, IPPROTO_UDP);
	if (sockfd < 0) {
		perror("Socket creation failed");
		exit(1);
	}
	return sockfd;
}

int bindsocket(int fd, int port) {
	struct sockaddr_in6 server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET6;
	server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any address
	server_addr.sin_port = htons(port); // Specify the port number

	bind(fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	return 0;
}

struct sockaddr_in6 acceptsocket(int fd, int *outfd) {
	struct sockaddr_in6 client_addr;
	socklen_t client_len = sizeof(client_addr);
	*outfd = accept(fd, (struct sockaddr *)&client_addr, &client_len);
	return client_addr;
}

int connectsocket(int fd, int port, char *ip) {
	struct sockaddr_in6 server_addr;
 	server_addr.sin_family = AF_INET6;
 	server_addr.sin_addr.s_addr = inet_addr(ip);
 	server_addr.sin_port = htons(port);
	
	if (connect(fd, (struct sockaddr *)&server_addr, sizeof(server_addr))>0) {
		perror("Connection failed");
		close(fd);
		exit(1);
	}
	return 0;
}

int closesocket(int fd) {
	if (close(socket_fd) < 0) {
		perror("Close failed");
	}	
}

