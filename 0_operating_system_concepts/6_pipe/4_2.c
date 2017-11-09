#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>	

#define size 5
#define max_size 100
#define FILENAME1 "temp2_1"
#define FILENAME2 "temp2_2"

int main(){
	int fd1,fd2;
	char buff1[max_size],buff2[max_size];
	int i = 0;
	int c1 = mkfifo(FILENAME1,0666);
	int c2 = mkfifo(FILENAME2,0666);
	if(c1<0 || c2<0){
		printf("\nCan't create FIFO special file");	
		exit(1);
	}


	int check = fork();
	if(check == 0){
		fd1 = open(FILENAME1, O_WRONLY);
		strcpy(buff1,"\nI am proud to be your child - says the child\0");
		write(fd1,buff1,strlen(buff1));
		close(fd1);
		
//		wait(getppid());

		fd2 = open(FILENAME2, O_RDONLY);
		read(fd2,buff2,sizeof(buff2));
		printf("%s",buff2);
		printf("\n\n");
		close(fd2);
		
	}
	else{
		fd2 = open(FILENAME2, O_WRONLY);
		strcpy(buff2,"\nI am proud to be your parent - says the parent\0");
		write(fd2,buff2,strlen(buff2));
		close(fd2);

//		sleep(1);

		fd1 = open(FILENAME1,O_RDONLY);
		read(fd1,buff1,sizeof(buff1));
		printf("%s",buff1);
		close(fd1);
	}

	printf("\n\n");

	return 0;
}


