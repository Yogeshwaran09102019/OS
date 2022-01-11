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
