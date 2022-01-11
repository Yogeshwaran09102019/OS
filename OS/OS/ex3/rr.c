#include<stdio.h>
int main()
{
  int n;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  int btime[n];
  int temp1[n];
  int quantum;
  printf("\nEnter time quantum: ");
  scanf("%d",&quantum);
  int i,total=0;
  for(i=0;i<n;i++)
  {
printf("\np%d.bursttime= ",i+1);
scanf("%d",&btime[i]);
total+=btime[i];
temp1[i]=btime[i];
  }
  int temp=0;
  int grant_up[50];
  int grant_down[50];
  grant_down[0]=0;
  int k=0,z=1;
  i=0;
  int turnaround[n];
  int wt[n];
  while(temp!=total)
  {
if(btime[i] && btime[i]<=quantum)
{
 temp+=btime[i];
 btime[i]=0;
 grant_up[k++]=i;
 grant_down[z++]=temp;
 turnaround[i]=temp;
}
else if(btime[i] && btime[i]>quantum)
{
  temp+=quantum;
  btime[i]-=quantum;
  grant_up[k++]=i;
  grant_down[z++]=temp;
}
i=(i+1)%n;
  }
  for(i=0;i<n;i++)
wt[i]=turnaround[i]-temp1[i];
  printf("\n");
  for(i=0;i<k;i++)
   printf(" %d",grant_up[i]);
  printf("\n");
  for(i=0;i<z;i++)
   printf("%d ",grant_down[i]);
  for(i=0;i<n;i++)
    printf("\np%d.turnaroundtime=%d",i+1,turnaround[i]);
  for(i=0;i<n;i++)
    printf("\np%d.Waiting time=%d",i+1,wt[i]);
  printf("\n");
}