#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid1;
	pid1 = fork();
	
	if(pid1==-1){
		printf("\nChild process couldn't be created. :( ");	
	}	
	else if(pid1==0){
		printf("\n[CHILD]\tChild PID = %d",getpid());
		printf("\n[CHILD]\tParent PID = %d",getppid());	
	}

	if(pid1 == 0 ){
		printf("\nRunning in child process");	
	}
	else{
		printf("\nTerminating parent process");
		kill();
		return 0;	
	}

	if(pid1==0){
		printf("\nRunning child process after parent has been terminated.\nPID[parent]=%d\n",getppid());	
	}

	return 0;
}
