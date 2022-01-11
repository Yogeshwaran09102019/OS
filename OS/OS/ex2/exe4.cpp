#include<iostream>
using namespace std;
int tl=0;
struct process{
    int pid;
    int burstTime;
};
void print(process *p, int n);
void scheduling(process *p,int n,int tq);
int schedule(process *p,int n,int tq);
void timeline(process *p,int n,int tq);
int calctl(process *p,int n,int tq);
void calcWait();
int main(){
    process *p;
    int n;
    cout<<"Enter the number of processes ";
    cin>>n;
    p=new process[n];
    cout<<"Enter the process Details\n";
    int i;
    for(i=0;i<n;i++){
        cout<<"Enter the process Id of "<<i+1<<" ";
        cin>>p[i].pid;
        cout<<"Enter the process Burst Time for PID ";
        cin>>p[i].burstTime;
    }
    int tq;
    cout<<"Enter the Time Quantum ";
    cin>>tq;
    cout<<"Processes \n";
    print(p,n);
    int *bs;
    bs= new int[n];
    for(i=0;i<n;i++){
        bs[i]=p[i].burstTime;
    }
    cout<<"\n";
    scheduling(p,n,tq);

    for(i=0;i<n;i++){
        p[i].burstTime=bs[i];
    }
    timeline(p,n,tq);
    cout<<"\n";
    return 0;
}
void print(process *p, int n){
    for(int j=0;j<n;j++){
        cout<<"\nProcess ID "<<p[j].pid;
        cout<<"\nBurst Time "<<p[j].burstTime<<"\n";
    }

}
void scheduling(process *p,int n ,int tq){
        int status;
        do{
                status=schedule(p,n,tq);
        }while(status==1);
        cout<<"\n";
        cout<<"0";
}
int schedule(process *p,int n,int tq){
        int i,c=0;
        for(i=0;i<n;i++){
                if(p[i].burstTime>0){
                        cout<<"|  "<<p[i].pid<<"  |";
                }
        }
        for(i=0;i<n;i++){
                p[i].burstTime=p[i].burstTime-tq;
                if(p[i].burstTime<=0){
                        c++;
                }
        }
        if(c>=n)
                return 0;
        else
                return 1;
}
void timeline(process *p,int n,int tq){
        int flag;
	do{
                flag=calctl(p,n,tq);
        }while(flag==1);
}
int calctl(process *p,int n,int tq){
        int i;
        int count=0;
        int f=0;
        for(i=0;i<n;i++){
                if(p[i].burstTime>=tq){
                        tl+=tq;
                        cout<<"      "<<tl;
			p[i].burstTime-=tq;
                }
                else if(p[i].burstTime<tq&&p[i].burstTime){
                        tl+=p[i].burstTime;
                        cout<<"      "<<tl;
			p[i].burstTime-=p[i].burstTime;
                }
                else if(p[i].burstTime==0){
                        f++;
                }
        }
        for(i=0;i<n;i++){
                if(p[i].burstTime<=0){
                        count++;
                }
        }
        if(count==n)
                return 0;
        else
                return 1;
}
