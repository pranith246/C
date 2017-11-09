	#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(){ 
 printf("Your process PID : %d\n",getpid());
 printf("Your process's parent (BASH, init()) PID = %d\n",getppid());
 printf("Forking...\n");
 int t = fork();
 if(t==-1){
   printf("Failed to create a child process! =(\n");
 }


 //wait();
 //wait();
 //sleep(4);

if(t==0){ 
  printf("[CHILD]\t");
}
else{
  printf("[PARENT]\t");
}
  printf("You are in PID =%d\n",getpid()); 

if(t==0){
  //sleep(5);
   
   printf("[CHILD]\tfork successful!\n");
   printf("[CHILD]\tChild PID = %d\n",getpid());
   printf("[CHILD]\tParent PID = %d\n",getppid());
 }
  else{
  printf("[PARENT]\tChild PID = %d\n",getpid());
  printf("[PARENT]\tParent PID = %d\n",getppid());
  //printf("Couldn't fork!\n");
  wait();
  }

 if(t==0){
  printf("[CHILD]\t");
}
else{
  printf("[PARENT]\t");
}
  printf("Returning from process with PID = %d\n",getpid());

 return 0;
}
