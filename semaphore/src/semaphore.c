/*
 ============================================================================
 Name        : semaphore.c
 Author      : YYC
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>

sem_t sem;

void* get_service(void* arg);
int main(void) {
	int i;
	sem_init(&sem, 0, 2);
	pthread_t customer[10];
	for(i = 0; i < 10; i++)
	{
		pthread_create(&customer[i], NULL, get_service, &i);
	}
	for(i = 0; i < 10; i++)
	{
		pthread_join(customer[i], NULL);
	}
	sem_destroy(&sem);
	return 0;
}

void* get_service(void* arg)
{
	int* id = (int*)arg;
	if(sem_wait(&sem) == 0)
	{
		sleep(1);
		printf("customer %d receive service...\n", *id);
		sem_post(&sem);
	}
}
