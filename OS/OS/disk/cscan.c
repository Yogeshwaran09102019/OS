#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void dsort(int *req, int n , int cur, int *ne){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(req[i] < req[j]){
				int temp = req[i];
				req[i] = req[j];
				req[j] = temp;
			}
		}
	}
	j=0;
	for(i=0;i<n;i++){
		if(req[i] < cur){
			ne[j++] = req[i];
		}
	}
	for(i=0;i<n;i++){
		if(req[i] > cur){
			ne[j++] = req[i];
		}
	}
}

void sort(int *req, int n , int cur, int *ne){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(req[i] > req[j]){
				int temp = req[i];
				req[i] = req[j];
				req[j] = temp;
			}
		}
	}
	j=0;
	for(i=0;i<n;i++){
		if(req[i] > cur){
			ne[j++] = req[i];
		}
	}
	for(i=0;i<n;i++){
		if(req[i] < cur){
			ne[j++] = req[i];
		}
	}
}

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
	int i,n,min,max,cur,from,to;
	char name;
	printf("Enter track range seperated by space : ");
	scanf("%d %d",&min,&max);
	printf("Enter the current position of r/w head : ");
	scanf("%d",&cur);
	printf("Enter direction of track head (Right Or Left): ");
	scanf("%d %d",&from,&to);		
	printf("Enter number of request : ");
	scanf("%d",&n);
	int *req = (int*)malloc((n+1)*sizeof(int));
	printf("Enter the request queue : ");
	for(i=0;i<n;i++)
		scanf("%d",&req[i]);
	req[i++]=max;
	req[i] = min;
	int *ne = (int*)malloc((n+1)*sizeof(int));
	if(from == min && to == max){
		sort(req,n+2,cur,ne);
	}else if(from == max && to == min){
		dsort(req,n+2,cur,ne);
	}
	int total_movement = 0;
	printf("\nDisk track follow : %d",cur);
	for(i=0;i<n+2;i++){
		printf("->%d",ne[i]);
		total_movement = total_movement + diff(cur,ne[i]);
		cur = ne[i];
		if(cur == to){
			total_movement = total_movement + diff(cur,from);
			cur = from;
		}
	}
	printf("\n\ntotal track head movement : %d\n",total_movement);
}
