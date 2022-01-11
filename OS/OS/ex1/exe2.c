#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	int n,b[10],c,i,flag=0;
	int d=0;
	printf("\nEnter The No of Numbers :");
	scanf("%d",&n);
	printf("\nEnter the nos :");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	printf("\nEnter The Key To search:");
	scanf("%d",&c);
	int n1=fork();
	if(n1>1)
	{
		for(i=0;i<n;i++)
		{
			if(b[i]==c)
			{
				printf("\nParent : The Key found at %d",b[i]);
				flag=flag+1;
			}
		}
		if(flag==0)
			printf("\nParent : Not Found");
	}
	if(n1==0)
	{
		for(i=0;i<n;i++)
		{
			d=b[i]+d;
		}
		printf("\nChild : The sum : %d",d);
	}
}		
