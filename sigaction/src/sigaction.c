/*
 ============================================================================
 Name        : sigaction.c
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
	printf("catch and handle %d signal\n", signum);
}
int main(void) {
	struct sigaction act;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, 0);
	struct sigaction act2;
	act2.sa_handler = handler;
	sigemptyset(&act2.sa_mask);
	act2.sa_flags = 0;
	sigaction(SIGALRM, &act, 0);
	alarm(5);
	while(1)
	{
		sleep(1);
	}
	return 0;
}
