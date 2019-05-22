/*
 ============================================================================
 Name        : pthread_signal.c
 Author      : YYC
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <sys/syscall.h>

pid_t gettid()
{
     return syscall(SYS_gettid);
}
void* signal_deal(int signum);
void* fun();
int main(void) {
	pthread_t pt;
	signal(SIGUSR1, signal_deal);
	int arg = gettid();
	printf("1continude %d  ss", arg);
	pthread_create(&pt, NULL, fun, &arg);
	pthread_join(pt, NULL);
	return 0;
}

void* signal_deal(int signum)
{
	switch(signum)
	{
		case SIGUSR1:
			printf("\n SIGUSR1");
		default:
			break;
	}
}

void* fun(void* arg)
{
	printf("start run\n");
	int* id = (int*)arg;
	printf("continude %d", *id);
	char str[20];
	snprintf(str, sizeof(str), "kill -s 10 %d", *id);
	system(str);
	return NULL;
}

