#include<iostream>
using namespace std;
void rpush(int rfs[],int queue[],int m,int n)
{
	int pf=0;
	int rear=0,i,j,k,l=0,found=0;
    int near[n];
    int max;
	for(i=0;i<m;i++)
	{
		for(k=0;k<n;k++)
		{
			if(rfs[i]==queue[k])
			{
				l+=1; 
			}
		}
		if(l==1)
		{
			l=0;
		}
		else
		{
            if(rear<n)
            {            
                queue[rear]=rfs[i];
                rear+=1;
                pf+=1;
            }
            else
            {
                for(j=0; j<n; j++)
                {
                    int pg=queue[j];
                    found=0;
                    for(k=i; k<m; k++)
                    {
                        if(pg==rfs[k])
                        {
                            near[j]=k;
                            found=1;
                            break;
                        }
                        else
                            found=0;
                    }
                    if(!found)
                        near[j]=9999;
                }
                max=-9999;
                int repindex;
                for(j=0; j<n; j++)
                {
                    if(near[j]>max)
                    {
                        max=near[j];
                        repindex=j;
                    }
                }
                queue[repindex]=rfs[i];
                pf+=1;
            }
        }
		cout<<"---\n"<<" "<<rfs[i]<<"\n---\n";
		for(j=0;j<n;j++)
			cout<<queue[j]<<"\n";
		cout<<"\n";
	}
	cout<<"\nPage Fault : "<<pf<<"\n";
}
int main()
{
	int n,m,i;
	cout<<"\nEnter The No of Frames : ";
	cin>>n;
	cout<<"\nEnter The Reference String Size :";
	cin>>m;
	int rfs[m];
	int queue[n];
	cout<<"\nEnter The Reference String :";
	for(i=0;i<m;i++)
		cin>>rfs[i];
	for(i=0;i<n;i++)
		queue[i]=9999;
	rpush(rfs,queue,m,n);
	return 0;
}
