#include<stdio.h>
#include<string.h>
int main(){
char name;
printf("Enter direction of track head (Right Or Left): ");
     	scanf("%c",&name);
        if(name=='r')
        {
                /*from=min;
                to=max;*/
                printf("\nr");
        }
        else
        {
                //from=max;
                printf("\nl\n");
                //to=min;
        }
}
