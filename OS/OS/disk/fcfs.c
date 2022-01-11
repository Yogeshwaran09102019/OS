#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int diff(int a, int b){
	if(a<b){
		return b-a;
	}else if(a>b){
		return a-b;
	}else if(a==b){
		return 0;
	}
}

int main(){
	int i,n,min,max,cur;
	printf("Enter track ramge seperated by space : ");
	scanf("%d %d",&min,&max);
	printf("Enter the current position of r/w head : ");
	scanf("%d",&cur);
	printf("Enter number of request : ");
	scanf("%d",&n);
	int req[n];
	printf("Enter the request queue : ");
	for(i=0;i<n;i++)
		scanf("%d",&req[i]);
	printf("\nEntered request queue : ");
	for(i=0;i<n;i++)
		printf("%d ",req[i]);
	int total_movement=0;
	printf("\nDisk track follow : %d",cur);
	
	for(i=0;i<n;i++){
		printf("->%d",req[i]);
		total_movement = total_movement + diff(req[i],cur);
		cur = req[i];
	}
	printf("\nTotal r/w movement : %d\n",total_movement);
}
