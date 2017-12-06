#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY 2356891

int main(int argc, char** argv){
	if(argc > 0){

		if(!strcmp(argv[1], "-c")){
			int sd = semget(KEY, 1, IPC_CREAT | IPC_EXCL);
			if(sd >= 0){
				if(argc > 1){
					semctl(sd, 1, SETVAL, argv[2]);
					printf("Semaphore created with key [%d]\nInitial value set to [%s]\n", KEY, argv[2]);
				}
				else printf("Semaphore created with key [%d]\nInitial value set to [0]\n", KEY);				
			}
			else printf("Semaphore already exists\n");
		}	
		else if(!strcmp(argv[1], "-v")){

		}
		else if(!strcmp(argv[1], "-r")){
			int sd = semget(KEY, 1, 0);
			semctl(sd, 1, IPC_RMID);
			printf("Semaphore removed\n");
		}
		else printf("Not a recognized argument\n");
	}
	
	else printf("Argument required\n");
	
	return 0;
}
