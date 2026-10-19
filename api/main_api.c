#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <limits.h>
#include <memory.h>
#include <setjmp.h>
#include "utils/sockets/sock.c"
#include "utils/ctypes/string_to_else.c"

int main(int argc, char *argv) {
	//STAGE 1; setting argv values
	
	///argv[1]
	if (argc<1) {
		fprintf(stderr, "API REQUIRES PORT NUMBER IN ARGV[1].");
		exit(1);
	}
	uint64_t temp_int_output;
	temp_int_output=str_to_int(argv[1]);
	short unsigned int client_port=temp_int_output;
	if (client_port!=temp_int_output) {
		fprintf(stderr, "API CLIENT PORT NUMBER IS INVALID.");
		exit(1);
	}
	
	///argv[2]
	if (argc<2) {
		fprintf(stderr, "API REQUIRES IP IN ARGV[2].");
		exit(2);
	}
	temp_int_output=str_to_int(argv[2]);
	short unsigned int server_ip=temp_int_output;
	if (server_ip!=temp_int_output) {
		fprintf(stderr, "API IP IS INVALID.");
		exit(2);
	}
	
	///argv[3]
	if (argc<3) {
		fprintf(stderr, "API REQUIRES PORT NUMBER IN ARGV[3].");
		exit(3);
	}
	temp_int_output=str_to_int(argv[3]);
	short unsigned int server_port=temp_int_output;
	if (server_port!=temp_int_output) {
		fprintf(stderr, "API SERVER PORT NUMBER IS INVALID.");
		exit(3);
	}
	
	//STAGE 2; starting api loop
	
	///making sockets
	int client_fd=mktcpsocket();
	int server_fd=mktcpsocket();
	connectsocket(client_fd, client_port, "::1");
	connectsocket(server_fd, server_port, server_ip);
	char task[1024];
	char buf[1024];
	///loop
	while (1) {
		///What's your request?
		read(client_fd, task, 1024);
		if (stringcmp(task, 1024, "makeaccount", 8)) {
			while (1) {
				write(server_fd, "mkacc", 6);
				read(server_fd, buf, 1024)
				if (stringcmp(buf, 1024, "ack", 4)) {
					break;
				}
			}
				
		} else if (stringcmp(task, 1024, "close", 6)) {
			write(server_fd, "close", 6);
		} 
	}
	//peaceful exit
	return 0;
}
