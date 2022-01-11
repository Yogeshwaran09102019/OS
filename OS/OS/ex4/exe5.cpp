#include<iostream>
using namespace std;
void sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void dsort(int a[],int n)
{
  int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }  
}
void firstfit(int temp1[],int a2[],int first[],int n,int m)
{
    int i,j,k=0,l=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(temp1[j]>a2[i])
            {
                first[k]=temp1[j];
                l+=1;
                temp1[j]=0;
                break;
            }
        }
        if(l==0)
            first[k]=0;
        l=0;
        k=k+1;
    }
}
void bestfit(int temp3[],int temp2[],int a2[],int best[],int n,int m)
{
    int i,j,l=0,p=0,z,w;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(temp3[j]>a2[i])
            {
                temp2[p]=temp3[j];
                p+=1;
                l+=1;
            }
        }
        if(l==0)
            best[i]=0;
        else
        {   sort(temp2,n);
            best[i]=temp2[0];
            for(z=0;z<n;z++)
            {
                if(temp2[0]==temp3[z])
                    temp3[z]=0;
            }
            for(w=0;w<n;w++)
                temp2[w]=9999;
        }
        l=0;
        p=0;
    }
}
void worstfit(int temp3[],int temp2[],int a2[],int best[],int n,int m)
{
    int i,j,l=0,p=0,z,w;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(temp3[j]>a2[i])
            {
                temp2[p]=temp3[j];
                p+=1;
                l+=1;
            }
        }
        if(l==0)
            best[i]=0;
        else
        {   dsort(temp2,n);
            best[i]=temp2[0];
            for(z=0;z<n;z++)
            {
                if(temp2[0]==temp3[z])
                    temp3[z]=0;
            }
            for(w=0;w<n;w++)
                temp2[w]=0;
        }
        l=0;
        p=0;
    }
}
int main()
{
    int n,i,j,m,k,l=0;
    cout<<"\nEnter The No of Block :";
    cin>>n;
    cout<<"\nEnter The No of Processes :";
    cin>>m;
    int a1[n];
    int a2[m];
    int first[m];
    int temp1[n];
    int temp2[n];
    int temp3[n];
    int temp4[n];
    int temp5[n];
    int best[m];
    int worst[m];
    int iff[m];
    int ifb[m];
    int ifw[m];
    int finaliff=0,finalifb=0,finalifw=0,eff=0,efb=0,efw=0;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter The Block "<<i+1<<" Size";
        cin>>a1[i];
    }
    for(i=0;i<m;i++)
    {
        cout<<"\nEnter The Size For Process "<<i+1<<": ";    
        cin>>a2[i];
    }
    for(i=0;i<n;i++)
        temp1[i]=a1[i];
    firstfit(temp1,a2,first,n,m);
    cout<<"\nFirst Fit :\n";
    for(i=0;i<m;i++)
    {
        if(first[i]==0)
            cout<<"\nNot Allocated";
        else
            cout<<"\n "<<a2[i]<<"kb\t"<<first[i]<<"\t";
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(first[i]==0)
                iff[i]=0;
            else
                iff[i]=first[i]-a2[i];
        }
    }
    for(i=0;i<m;i++)
        finaliff+=iff[i];
    for(i=0;i<n;i++)
        eff+=temp1[i];
    cout<<"\nInternal Fragmentation : "<<finaliff;
    cout<<"\nExternal Fragmentation : "<<eff;
    for(i=0;i<n;i++)
        temp2[i]=9999;
    for(i=0;i<n;i++)
        temp3[i]=a1[i];
    bestfit(temp3,temp2,a2,best,n,m);
    cout<<"\nBest Fit :\n";
    for(i=0;i<m;i++)
    {
        if(best[i]==0) 
            cout<<"\nNot Allocated";
        else
            cout<<"\n "<<a2[i]<<"kb\t"<<best[i]<<"\t";
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(best[i]==0)
                ifb[i]=0;
            else
                ifb[i]=best[i]-a2[i];
        }
    }
    for(i=0;i<m;i++)
        finalifb+=ifb[i];
    for(i=0;i<n;i++)
        efb+=temp3[i];
    cout<<"\nInternal Fragmentation : "<<finalifb;
    cout<<"\nExternal Fragmentation : "<<efb;
    for(i=0;i<n;i++)
        temp4[i]=0;
    for(i=0;i<n;i++)
        temp5[i]=a1[i];
    worstfit(temp5,temp4,a2,worst,n,m);
    cout<<"\nWorst Fit :\n";
    for(i=0;i<m;i++)
    {
        if(worst[i]==0)
            cout<<"\nNot Allocated";
        else
            cout<<"\n "<<a2[i]<<"kb\t"<<worst[i]<<"\t";
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(worst[i]==0)
                ifw[i]=0;
            else
                ifw[i]=worst[i]-a2[i];
        }
    }
    for(i=0;i<m;i++)
        finalifw+=ifw[i];
    for(i=0;i<n;i++)
        efw+=temp5[i];
    cout<<"\nInternal Fragmentation : "<<finalifw;
    cout<<"\nExternal Fragmentation : "<<efw;
    return 0;
}
