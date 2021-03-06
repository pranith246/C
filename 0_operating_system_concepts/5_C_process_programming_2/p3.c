#include<stdio.h>
#include<unistd.h>


int main(){

char *args[] = {"./dummy",NULL};
char *env[] = {"LOGNAME=student",(char *)0};

printf("\n family of exec: ");
printf("\n1. int execl(const char *path,const char*arg, ... (char *) NULL)"); 
printf("\n2. int execlp(const char *file,const char*arg, ... (char *) NULL)");
printf("\n3. int execle(const char *path,const char*arg, ... (char *) NULL,char * const envp[])");
printf("\n4. int execv(const char *path,const char*argv[])");
printf("\n5. int execvp(const char *file,const char*argv[])");
printf("\n6. int execvpe(const char *file,const char*argv[],char *const envp[])");
int choice;
scanf("%d",&choice);
switch(choice){
	case 1 : printf("\n executing execl ... \n");
		 execl(args[0],NULL);
		 break;

	case 2 : printf("\n executing execlp ... \n");
		 execlp(args[0],NULL);
		 break;

	case 3 : printf("\n executing execle ... \n");
		 execle(args[0],NULL,env);
		 break;

	case 4 : printf("\n executing execv ... \n");
		 execv(args[0],args);
		 break;

	case 5 : printf("\n executing execvp ... \n");
		 execvp(args[0],args);
		 break;

	case 6 : printf("\n executing execvpe ... \n");
		 execvpe(args[0],args,env);
		 break;
}

return 0;
}
