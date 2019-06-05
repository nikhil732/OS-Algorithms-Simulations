#include<bits/stdc++.h>
using namespace std;
void rr()
{
 int i,j,sum=0,n,k=0,q=0,c=0;
 int ar[200],tm[200],dt[200],tr[200],t,rm[200],b[1000];
 int disk;
 printf("enter no.of cylinders : ");
 scanf("%d",&n);
 printf("enter position of head  :");
 scanf("%d",&disk);
 cout<<"enter time quantum  :"<<endl;
 cin>>t;
 printf("enter elements of disk queue\n");
 for(i=0;i<n;i++)
 {
 scanf("%d",&ar[i]);
 rm[i]=ar[i];
 tm[i]=disk-ar[i];
 if(tm[i]<0)
 {
 tm[i]=ar[i]-disk;
 }
 disk=ar[i];
 sum=sum+tm[i];
 }
 printf("enter size of data to be transfered for each request : \n");
 for(i=0;i<n;i++)
 {
     scanf("%d",&dt[i]);
 }
 printf("enter transfer rate for each request : \n");
 for(i=0;i<n;i++)
 {
     scanf("%d",&tr[i]);
 }
 int x=0;
 printf("waiting times of each request\n");
 for(i=0;i<n;i++)
 {
printf("%d\n",tr[i]/dt[i]);
    k+=tr[i]/dt[i];
 }
 printf("Average waiting time : \n");
 k=k/n;
 printf("%d\n",k);
 printf("turn around time for each request  :\n");
 for(int i=0;i<n;i++)
 {
     printf("%d\n",tm[i]+(tr[i]/dt[i]));
     q+=tm[i];
 }
 printf("Average turn around time  :\n");
 q=(q/n)+k;
 printf("%d",q);
 printf("\nmovement of total cylinders %d",sum);
 cout<<endl;
 printf("sequence of execution of processes in RR : \n");
 while(c!=n){

     for(int j=0;j<n;j++)
     {if(rm[j]>=0)
     {
         cout<<j<<" ";
         b[x++]=j;
         if(rm[i]>t)
            {rm[j]=rm[j]-t;}
        else
            rm[i]=0;
     }}
     for(int i=0;i<n;i++)
     {
         if(rm[i]==0)
                c++;
     }
 }
}
int main()
{
    rr();
    return 0;
}
