#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>
struct pcsemaphore
{
	sem_t mutex;
	sem_t full;
	sem_t empty;
	int empty1,full1;
	int data[10];
};
int main()
{
	int n=10,sid,temp,i,ch;
	struct pcsemaphore *semaphore;
	sid = shmget(1234,(20*sizeof(int)),IPC_CREAT|0666);
	if(sid==-1){
		perror("error");
		exit(1);
	}
	semaphore = (struct pcsemaphore*)shmat(sid,0,0);
	//semaphore->mutex=1;
	sem_init(&semaphore->mutex,1,1);
	sem_init(&semaphore->full,1,0);
	sem_init(&semaphore->empty,1,10);
	//semaphore->full=0;
	//semaphore->empty=10;
	for(i=0;i<10;i++)
		semaphore->data[i]=0;
	while(1){
		printf("\n1)Produce");
		printf("\n2)Display Data");
		printf("\n0)Exit");
		printf("\nEnter the Choice :");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				printf("\nEnter data :");
				scanf("%d",&temp);
				if(semaphore->empty1<=0)
					printf("\nThe buffer is full");
				//while(semaphore->empty<=0);
				//semaphore->empty-=1;
				sem_wait(&semaphore->empty);
				semaphore->empty1-=1;
				//if(semaphore->mutex<=0)
					//printf("\nConsumer in critical section");
				//while(semaphore->mutex<=0);
				//semaphore->mutex=0;
				sem_wait(&semaphore->mutex);
				semaphore->data[semaphore->full1]=temp;
				printf("\nThe data is produced %d\n",semaphore->data[semaphore->full1]);
				sleep(5);
				sem_post(&semaphore->mutex);
				sem_post(&semaphore->full);
				//if(semaphore->data[semaphore->full]!=0){
				//semaphore->mutex=1;
				semaphore->full1+=1;
				//}
				break;
			}
			case 2:{
				printf("\nThe buffer data is ");
				for(int j=0;j<semaphore->full1;j++)
					printf("%d ",semaphore->data[j]);
				break;
			}
			case 0:{
				shmdt(0);
				shmctl(sid,IPC_RMID,NULL);
				return 1;
			}
		}
	}
	return 1;
}