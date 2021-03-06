//write a c program to set a semaphore with positive alue and seubsequenty create a child process. the child process uses the atomic operation semop to set the semaphore value zero and goes to sleep mode for a while.on the other hand parent process continousley pronts the semaphore value.

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int main(){
	int i,n,val=1;
	key_t key=2;
	int semid=semget(key,1,0666|IPC_CREAT);
	int flag=semctl(semid,0,SETVAL,1);
	if(flag == -1){
		printf("Semaphore control failed");
		return 1;
	}
	pid_t pid=fork();

	if(pid==-1)
		printf("child process creation failed");

	if(pid==0){
		int op;
		sleep(1);
		struct sembuf *mysem=(struct sembuf *) malloc(1*sizeof(struct sembuf));

		/*
		structure of sembuf defined in  :
       		unsigned short sem_num;  // semaphore number 
           	short          sem_op;   // semaphore operation 
          	short          sem_flg;  // operation flags =
		*/
		printf("\ninside child process. setting semaphore to 0");
		mysem[0].sem_num=0;		//operate on semaphore 0
		mysem[0].sem_op=-1;		//wait for value to be -1
//function definition : int semop(int semid, struct sembuf *sops, unsigned nsops);
		op = semop(semid,mysem,1);
	}
	else{
		printf("\ninside parent process. continuosly printing value of semaphore");
		while(val==1){
//			sleep(1);
			val=semctl(semid,0,GETVAL);
			if(val == -1){
				printf("Semaphore control failed");
				return 1;
			}
			printf("semaphore val = %d\n",val);
		}
		semctl(semid,0,IPC_RMID);
		
	}

	return 0;
}
