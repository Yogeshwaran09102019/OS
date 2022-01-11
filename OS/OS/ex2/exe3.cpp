#include<iostream>
using namespace std;
struct sjf
{
	int id;
	int bt;
	int	wt;
	int tt;
};
int main()
{
	int n,i,j,temp,temp2;
	cout<<"\nEnter The No of Process to create :";
	cin>>n;
	struct sjf arr[n];
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter The "<<i<<" Process's Id :";
		cin>>arr[i].id;
		cout<<"\nEnter The "<<i<<" Process's Burst Time :";
		cin>>arr[i].bt;
	}
	for(i=0;i<n;i++)
	{
		cout<<"\nThe "<<i<<" Process's Id :"<<arr[i].id;
		cout<<"\tThe "<<i<<" Process's Burst Time :"<<arr[i].bt;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i].bt>arr[j].bt)
			{
				temp=arr[i].bt;
				temp2=arr[i].id;
				arr[i].bt=arr[j].bt;
				arr[i].id=arr[j].id;
				arr[j].bt=temp;
				arr[j].id=temp2;
			}
		}
	}
	cout<<"\nAfter ASCE";
	for(i=0;i<n;i++)
	{
		cout<<"\nThe "<<i<<" Process's Id :"<<arr[i].id;
		cout<<"\tThe "<<i<<" Process's Burst Time :"<<arr[i].bt;
	}
	arr[0].wt=0;
	for(i=1;i<n;i++)
	{
		arr[i].wt=arr[i-1].bt+arr[i-1].wt;
	}
	cout<<"\nGantt Chart:\n";
	for(i=0;i<n;i++)
		cout<<"\t"<<arr[i].id<<"\t";
	cout<<"\n";
	for(i=0;i<n;i++)
	{
		cout<<arr[i].wt<<"\t\t";
		if(i==n-1)
			cout<<arr[i].wt+arr[i].bt;
	}
	for(i=0;i<n;i++)
		arr[i].tt=arr[i].wt+arr[i].bt;
	for(i=0;i<n;i++)
	{
		cout<<"\nThe "<<i<<" Process's Id :"<<arr[i].id;
		cout<<"\tThe "<<i<<" Process's Burst Time :"<<arr[i].bt;
		cout<<"\n\tThe "<<i<<" Process's Waiting Time :"<<arr[i].wt;
		cout<<"\tThe "<<i<<" Process's Turnaround Time :"<<arr[i].tt;
	}
	cout<<"\n";
	int sum=0;
	int sum2=0;
	for(i=0;i<n;i++)
	{
		sum=sum+arr[i].tt;
		sum2=sum2+arr[i].wt;
	}
	cout<<"\nAverage Waiting Time : "<<sum2/4;
	cout<<"\nAverage Turnaround Time : "<<sum/4<<"\n";
	return 0;
}
