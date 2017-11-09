#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>

#define   MAX_COUNT  200
#define   BUF_SIZE   65

void  main(void)
{
	pid_t  pid;
	int    i;
	char   buf[BUF_SIZE];

	char f_data[BUF_SIZE];

	FILE *ptr1;
	ptr1 = fopen("dummy1","r");
	fread(&f_data, BUF_SIZE, 1, ptr1); 
	//printf("Character in dummy1 file are : \n%s\n", f_data);
	FILE *ptr2;
	ptr2 = fopen("dummy2","w");

	pid = fork();

	write(ptr2,f_data,BUF_SIZE);
	fwrite(f_data,BUF_SIZE,1,ptr2); 

	fclose(ptr1); 
	fclose(ptr2);
}
