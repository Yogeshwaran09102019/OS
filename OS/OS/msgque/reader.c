#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<unistd.h>
struct msg_buffer
{
	long msg_type;
	char msg[100];
}message;
int main()
{
	int msg_id;
	int id;
	id=fork();
	if(id>0)
	{
		printf("\nParent :");
		msg_id=msgget(160,0666 | IPC_CREAT);
		message.msg_type=1;
		printf("\nEnter The Message To Send :");
		scanf("%s",&message.msg);
		msgsnd(msg_id,&message,sizeof(message),0);
	}
	else
        {
                printf("\nChild :");
                msg_id=msgget(160,0666 | IPC_CREAT);
                message.msg_type=1;
                msgrcv(msg_id,&message,sizeof(message),1,0);
                printf("\nReceived Message : %s",message.msg);
        }
        msgctl(msg_id,IPC_RMID,NULL);
	return 0;
}	
