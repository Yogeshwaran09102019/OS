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
	semaphore = (struct pcsemaphore*)shmat(sid,0,0);
	//semaphore->mutex=1;
	//semaphore->full=0;
	//semaphore->empty=10;
	
	while(1){
		printf("\n1)Consume");
		printf("\n2)Display Data");
		printf("\n0)Exit");
		printf("\nEnter the Choice :");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				if(semaphore->full1<=0)
					printf("\nThe buffer is empty");
				//while(semaphore->full<=0);
				sem_wait(&semaphore->full);
				semaphore->full1-=1;
				//if(semaphore->mutex<=0)
				//	printf("\nProducer in critical section");

				///while(semaphore->mutex<=0);
				//semaphore->mutex=0;sem_wait(&semaphore->full);
				sem_wait(&semaphore->mutex);
				temp=semaphore->data[semaphore->full1];
				printf("\nThe data in square %d",temp*temp);
				sleep(5);
				semaphore->data[semaphore->full1]=0;
				sem_post(&semaphore->mutex);
				//semaphore->mutex=1;
				sem_post(&semaphore->empty);
				semaphore->empty1+=1;
				
				break;
			}
			case 2:{
				printf("\nThe buffer data is ");
				for(int j=0;j<semaphore->full1;j++)
					printf("%d ",semaphore->data[j]);
				break;
			}
			/*case 3:{
				printf("\nm = %d",semaphore->mutex);
				printf("\ne = %d",semaphore->empty);
				printf("\nf = %d",semaphore->full);
				break;
			}*/
			case 0:{
				return 1;
			}
			default:{
				printf("Invalid option");
			}
		}
	}
	shmdt(0);
	return 1;
}