#include<unistd.h>
#include<stdio.h>

int main(){
	pid_t pid;

	pid = fork();
	if(pid==0){
		printf("\nChild process : %d ",getpid());
		printf("Replacing child process with ls");	
		//execl("/bin/ls","ls","-l",(char*)0);	
		
		execl("/bin/echo","echo","hi",(char*)0);	
	}

	return 0;
}
