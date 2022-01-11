#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
        int pipeEle[2];
        int returnStatus;
        int pid,i,n;
        int words[20];
        int readWord[20];
        int length,sum=0;
printf("\nEnter the no of elements:");
scanf("%d",&n);
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
                        for(i=0;i<n;i++)
                        {
                                if(readWord[i]%2!=0)
                                        sum++;
                        }
                        printf("\nCount of odd Numbers: %d\n",sum);
                }
                else{
                        printf("\nEnter Numbers:");
                        for(i=0;i<n;i++)
				scanf("%d",&words[i]);
                        printf("\nWriting into Pipe from Parent process\n");
                        write(pipeEle[1],words,sizeof(words));
}
}
}
