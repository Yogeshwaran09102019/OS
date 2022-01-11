#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	int n1=fork();
	if(n1==0)
	{
		printf("\nChild : %d \t %d\n",getpid(),getppid());
		int n2=fork();
		if(n2==0)
			
}
