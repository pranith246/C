#include<signal.h>
#include<stdio.h>

#define true 1
#define false 0

void info();
void sigint_handler(int);
void sigquit_handler(int);

int main(){
//   signal(SIGINT,sigint_handler);
   int pid = fork();
   if(pid<0){
      printf("Failed to create child\n");
   }
   else if(pid == 0){
      //pause();
      //sleep(0);
      printf("Child executing ...\n");
      signal(SIGINT,sigint_handler);
      signal(SIGQUIT,sigquit_handler);
      //while(1);
   }
   else{
      sleep(1);
      printf("Executing parent...\n");
      kill(pid,SIGQUIT);	
      printf("after kill\n");
      //while(1);
	
   }

   while(1);
   return 0;

}



void sigint_handler(int sig){
   printf("Caught the Ctrl+C interrupt\n");
}


void sigquit_handler(int sig){
   printf("Caught the quit interrupt\n");
}

void info(){
   int p = getpid();
   int pp = getppid();
   printf("Process id\t\t:\t%d  \nParent Process id\t:\t%d\n",p,pp);
}


