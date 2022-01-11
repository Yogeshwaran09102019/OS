#include<iostream>
using namespace std;
void lrupush(int rfs[],int queue[],int n,int m)
{
    int i,j,l=0,rear=0,pf=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(rfs[i]==queue[j])
                l+=1;
        }
        if(l==1)
        {
            l=10;
        }
        else if(l==0)
        {
            if(rear==n)
            {
                rear=0;
                queue[rear]=rfs[i];
                rear+=1;
                pf+=1;
            }
            else
            {
                queue[rear]=rfs[i];
                rear+=1;
                pf+=1;
            }
        }
        l=0;
	cout<<"\n"<<rfs[i]<<"-->  ";
    	for(j=0;j<n;j++)
        	cout<<queue[j]<<"\t";
     }
	cout<<"\nPage Fault :"<<pf;
}
int main()
{
    int n,m,i;
    cout<<"\nEnter The Frame Size : ";
    cin>>n;
    int queue[n];
    cout<<"\nEnter The Reference String Size : ";
    cin>>m;
    int rfs[m];
    cout<<"\nEnter The Reference String : ";
    for(i=0;i<m;i++)
    {
        cin>>rfs[i];
    }
    for(i=0;i<n;i++)
	queue[i]=-1;
    lrupush(rfs,queue,n,m);
}
