#include<stdio.h>
#include<unistd.h>
#include<string.h>

main(){
	//char *o;

	char buf[100];

	printf("\nBefore Exec()\n\n");
	
	execl("/bin/ls","ls","-l",(char*)0);

	execl("usr/bin/wc","wc","hi",(char*)0);
	//execl("/home/student/Documents/YogeshSingla_115cs0243/4_C_process_programming/dummy","wc","dummy",(char*)0);

	//printf("Dummy\n\n");
	
		
	sprintf(buf,"\n\nAfter\n\n");
	write(1,buf,strlen(buf));
}
