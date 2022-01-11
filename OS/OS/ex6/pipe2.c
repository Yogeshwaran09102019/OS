#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int pipeEle[2];
	int returnStatus;
	int pid,i;
	char words[100];
	char readWord[100];
	int length,c=0;
	returnStatus=pipe(pipeEle);
	if(returnStatus==-1)
	{
		printf("Pipe not created");
		return 0;
	}
	else
	{
		pid=fork();
		if(pid==0){
			printf("\nReading characters from Child Process:");
			read(pipeEle[0],readWord,sizeof(readWord));
			length=strlen(readWord);
			printf("\nNumber of characters: %d",length);
			for(i=0;i<length;i++)
			{
				if(readWord[i]=='x'|| readWord[i]=='X')
				c++;
			}
			printf("\nNo of occurance of 'X' is: %d",c);
			printf("\n");
			}
			else{
				printf("\nEnter characters:");
				gets(words);
				printf("\nWriting into Pipe...");
				write(pipeEle[1],words,sizeof(words));
			}
	}
}
