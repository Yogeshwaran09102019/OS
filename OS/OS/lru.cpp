#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void optimal(int rfs[],int queue[],int n,int m)
{   
    int i,j,rear=0,cnt=0,k,l=0;
    int a[n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(rfs[i]==queue[j])
                l+=1;
        }
        if(l==1)
            break;
        if(rear<n)
        {
            queue[rear]=rfs[i];
            rear+=1;
            cnt+=1;
        }
        else
        {
            for(j=m-1;j>=cnt;j--)
            {
           // cout<<rfs[j];
             for(k=0;k<n;k++)
                {
                    if(queue[k]==rfs[j])
                    {
                        a[k]+=1;
                    }
                }
                int z=*min_element(a,a+n);
                for(k=0;k<n;k++)
                {
                    if(a[k]==z)
                        queue[k]=rfs[j];
                }
            }
        } 
        cout<<"\n";
        for(j=0;j<n;j++)
            cout<<queue[j]<<"\t";
    } 
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
    optimal(rfs,queue,n,m);
}
