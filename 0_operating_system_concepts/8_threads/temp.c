#include<stdio.h>

int main(){
	int arr[2][2][3] ={
			 {
			  {0,0,0},
			  {0,0,0},
			 },			 
			 {
			  {10,20,30},
			  {40,100,60}
			 }
			};

	int* m[3];
	m[0] = &arr;
	printf("%d",*(*(*(arr+1)+1)+1));
//	printf("%d",*(*(*m+1)+1));
}
