#include<stdio.h>
#include<stdlib.h>


int diff(int a, int b){
	if(a<b){
		return b-a;
	}else if(a>b){
		return a-b;
	}else if(a==b){
		return 0;
	}
}

int check(int cur, int *req, int n){
	int i,j,k,h;
	int min=999;
	for(i=0;i<n;i++){
		int ret = diff(cur,req[i]);
		if(ret < min){
			min = ret;
			k=req[i];
			h=i;
		}
	}
	req[h] = 999;
	return k;
}
int main(){
	int i,n,min,max,cur;
	printf("Enter range : ");
	scanf("%d %d",&min,&max);
	printf("Enter current position : ");
	scanf("%d",&cur);
	printf("Enter number of request : ");
	scanf("%d",&n);
	int *req = (int*)malloc(n*sizeof(int));
	printf("Enter request queue : ");
	for(i=0;i<n;i++){
		scanf("%d",&req[i]);
	}
	int total_movement = 0;
	printf("Disk track : %d",cur);
	for(i=0;i<n;i++){
		int min = check(cur,req,n);
		total_movement = total_movement + diff(cur,min);
		cur = min;
		printf("->%d",cur);
	}
	printf("\nTotal disk movement : %d\n",total_movement);
}
