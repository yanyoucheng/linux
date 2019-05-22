/*
 ============================================================================
 Name        : signal.c
 Author      : YYC
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void* handler(int signum)
{
	printf("catch and handle alarm signal, %d\n", signum);
}

int main(void) {
	signal(SIGALRM, (void*)handler);
	alarm(5);
	sleep(6);
	return 0;
}
