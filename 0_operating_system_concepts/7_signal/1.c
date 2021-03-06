#include<signal.h>
#include<stdio.h>

#define true 1
#define false 0

void info();

int main(){
   void sigint_handler(int);
 
   signal(SIGINT,sigint_handler);
   info();

   while(true);

   return 0;	
}

void sigint_handler(int sig){
   printf("\nCaught the Ctrl+C interrupt\n");
   if(fork()==0){
      printf("Inside child process ...\n");
      info();
   }
}

void info(){
   int p = getpid();
   int pp = getppid();
   printf("Process id\t\t:\t%d  \nParent Process id\t:\t%d\n",p,pp);
}


