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
	//setting argv values
	///argv[1]
	if (argc<1) {
		fprintf(stderr, "API REQUIRES PORT NUMBER IN ARGV[1].");
		exit(1);
	}
	uint64_t temp_int_output;
	temp_int_output=str_to_int(argv[1]);
	short unsigned int port=temp_int_output;
	if (port!=temp_int_output) {
		fprintf(stderr, "API PORT NUMBER IS INVALID.");
		exit(1);
	}
	///argv[2]
	if (argc<2) {
		fprintf(stderr, "API REQUIRES IP IN ARGV[2].");
		exit(2);
	}
	temp_int_output=str_to_int(argv[2]);
	short unsigned int server_ip=temp_int_output;
	if (port!=temp_int_output) {
		fprintf(stderr, "API IP IS INVALID.");
		exit(2);
	}
	///argv[3]
	if (argc<3) {
		fprintf(stderr, "API REQUIRES PORT NUMBER IN ARGV[3].");
		exit(3);
	}
	temp_int_output=str_to_int(argv[3]);
	short unsigned int port=temp_int_output;
	if (port!=temp_int_output) {
		fprintf(stderr, "API SERVER PORT NUMBER IS INVALID.");
		exit(3);
	}
	//starting api loop
	//peaceful exit
	return 0;
}