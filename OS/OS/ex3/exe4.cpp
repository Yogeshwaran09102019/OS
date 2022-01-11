#include<iostream>
using namespace std;
int main()
{
	int n,m,i,j;
	cout<<"\nEnter The No of Process Want to Create : ";
	cin>>n;
	cout<<"\nEnter The No of Resource Want to Create : ";
	cin>>m;
	int all[n][m];
	int max[n][m];
	int need[n][m];
	int avai[m];
	int work[m];
	int finish[n];
	int ss[n];
	cout<<"\nEnter The Value for Allocation :";
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>all[i][j];
	cout<<"\nEnter The Value for Max :";
	for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                        cin>>max[i][j];
	cout<<"\nEnter The Available :";
	for(i=0;i<m;i++)
			cin>>avai[i];
	cout<<"\nAllocation :\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<all[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\nMax : \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<max[i][j]<<"\t";
		}
		cout<<"\n";
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-all[i][j];
		}
	}
	cout<<"\nNeed : \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<need[i][j]<<"\t";
		}
		cout<<"\n";
	}
	for(j=0;j<m;j++)
	{
		work[j]=avai[j];
	}
	cout<<"\nWork:\n";
        for(j=0;j<m;j++)
        {
                cout<<work[j]<<"\t";
        }
        cout<<"\n";
	for(i=0;i<n;i++)
		finish[i]=false;
	int cnt=0,k;
	int l=0;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(finish[i]==false && need[i][j]<=work[j])
				{
					cnt+=1;
				}
			}
			if(cnt==m)
			{
				finish[i]=true;
				ss[l]=i;
				l+=1;
				for(j=0;j<m;j++)
					work[j]+=all[i][j];
			}
			cnt=0;
		}
	}			
	for(i=0;i<n;i++)
		cout<<finish[i]<<"\t";
	for(i=0;i<n;i++)
		cout<<"P"<<ss[i]<<"\t";
	




	int req[m];
	int p,z=0;
	cout<<"\nEnter The Request :";
	for(i=0;i<m;i++)
		cin>>req[i];
	cout<<"\nEnter The Process which you are going to request :";
	cin>>p;
	for(i=0;i<m;i++)
	{
		if(need[p][i]>=req[i] && avai[i]>=req[i])
		{
			avai[i]-=req[i];
			all[p][i]+=req[i];
			need[p][i]-=req[i];
			z+=1;
		}
	}
	if(z==3)
	{
		cout<<"\nAllocation :\n";
       		for(i=0;i<n;i++)
        	{
                	for(j=0;j<m;j++)
                	{
                	        if(all[i][j]<0)
					cout<<all[i][j]*(-1)<<"\t";
				cout<<all[i][j]<<"\t";
                	}
                	cout<<"\n";
        	}
		cout<<"\nNeed : \n";
	        for(i=0;i<n;i++)
        	{
                	for(j=0;j<m;j++)
                	{
                        	if(need[i][j]<0)
					cout<<need[i][j]*(-1)<<"\t";
				cout<<need[i][j]<<"\t";
                	}
                	cout<<"\n";
        	}
		cout<<"\nAvailable:\n";
        	for(j=0;j<m;j++)
	        {
                	if(avai[j]<0)
				cout<<avai[j]<<"\t";
			cout<<avai[j]<<"\t";
        	}
	}
	for(j=0;j<m;j++)
	{
		work[j]=avai[j];
	}
	cout<<"\nWork:\n";
        for(j=0;j<m;j++)
        {
                cout<<work[j]<<"\t";
        }
        cout<<"\n";
	for(i=0;i<n;i++)
		finish[i]=false;
	cnt=0;
	l=0;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(finish[i]==false && need[i][j]<=work[j])
				{
					cnt+=1;
				}
			}
			if(cnt==m)
			{
				finish[i]=true;
				ss[l]=i;
				l+=1;
				for(j=0;j<m;j++)
					work[j]+=all[i][j];
			}
			cnt=0;
		}
	}
	int cn=0;			
	for(i=0;i<n;i++)
		cout<<finish[i]<<"\t";
	for(i=0;i<n;i++)
		cout<<"P"<<ss[i]<<"\t";
	for(i=0;i<n;i++)
	{
		if(finish[i]==true)
			cn+=1;
	}
	if(cn==n)
		cout<<"\nRequest Granted..";
	else
		cout<<"\nRequest Not granted..";		
	return 0;
}
