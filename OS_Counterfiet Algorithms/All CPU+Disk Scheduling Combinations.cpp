#include<bits/stdc++.h>
using namespace std;
#define LOW 0
#define HIGH 199
struct di
{
int num;
int flag;
};
int sjffcfs(int n,int m,int tr[])
{
 int i,j,sum=0,k=0,q=0,nb,pos,temp;
 int ar[200],tm[200],bt[200],p[200],dt[200];
 int disk;
 printf("enter position of head  :");
 scanf("%d",&disk);
 cout<<"enter no.of IO bursts :"<<endl;
 cin>>nb;
 printf("enter arrival times of processes\n");
 for(i=0;i<m;i++)
 {
 scanf("%d",&ar[i]);
 tm[i]=disk-ar[i];
 if(tm[i]<0)
 {
 tm[i]=ar[i]-disk;
 }
 disk=ar[i];
 sum=sum+tm[i];
 }
 printf("enter size of data to be transfered for each request : \n");
 for(i=0;i<m;i++)
 {
     scanf("%d",&dt[i]);
 }
cout<<"enter burst times :"<<endl;
    for(i=0;i<m;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
for(i=0;i<m;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    cout<<"sequence of execution of processes in CPU :"<<endl;
        for(i=0;i<m;i++)
    {
        printf("\np%d\t %d",p[i],bt[i]);
    }

 printf("\nsequence of execution of processes in disk drive : \n");
 for(i=0;i<m;i++)
 {
     printf("%d\n",i);
 }
 for(i=0;i<m;i++)
 {
    k+=tr[i]/dt[i];
 }
 k=k/m;
 printf("turn around time for each request  :\n");
 for(int i=0;i<m;i++)
 {
     printf("%d\n",bt[i]+(tr[i]/dt[i]));
     q+=bt[i];
 }
 printf("Average turn around time   :\n");
 q=(q/m)+k;
 printf("%d",q);
 printf("\nmovement of total cylinders %d",sum);
}
int sjfsstf(int n,int m,int tr [])
{
 int i,j,sum=0,min,loc,x,y,k=0,q=0,p,pos,temp,nb,po[200];
 int ds[200];
 struct di d[200];
 int disk;
 int ar[200],a[200],dt[200],dif[200],bt[200];
 printf("enter position of head\t");
 scanf("%d",&disk);
 cout<<"enter no.of IO bursts :"<<endl;
 cin>>nb;
 printf("enter elements of arrival times of processes :\n");
 for(i=0;i<m;i++)
 {
 scanf("%d",&ds[i]);
d[i].num=ds[i];   d[i]. flag=0;
 }
 printf("enter size of data to be transfered for each request : \n");
 for(i=0;i<m;i++)
 {
     scanf("%d",&dt[i]);
 }
 cout<<"enter burst times :"<<endl;
    for(i=0;i<m;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        po[i]=i+1;           //contains process number
    }
for(i=0;i<m;i++)
    {
        pos=i;
        for(j=i+1;j<m;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=po[i];
        po[i]=po[pos];
        po[pos]=temp;
    }
    cout<<"sequence of execution of processes in CPU :"<<endl;
        for(i=0;i<m;i++)
    {
        printf("\np%d\t %d",po[i],bt[i]);
    }

  for(i=0;i<m;i++)
    {
        pos=i;
        for(j=i+1;j<m;j++)
        {
            if(ds[j]<ds[pos])
                pos=j;
        }

        temp=ds[i];
        ds[i]=ds[pos];
        ds[pos]=temp;

        temp=po[i];
        po[i]=po[pos];
        po[pos]=temp;
    }
    cout<<endl;
    cout<<"sequence of execution of processes in disk drive :"<<endl;
        for(i=0;i<m;i++)
    {
        printf("\np%d",po[i]);
    }
 for(i=0;i<m;i++)
 {                 x=0; min=0;loc=0;
  for(j=0;j<m;j++)
  {
   if(d[j].flag==0)
   {
   if(x==0)
   {
   ar[j]=disk-d[j].num;
   if(ar[j]<0){ ar[j]=d[j].num-disk;}
   min=ar[j];loc=j;x++; }
   else
   {
   ar[j]=disk-d[j].num;
   if(ar[j]<0){ ar[j]=d[j].num-disk;}
    }
    if(min>ar[j]){ min=ar[j]; loc=j;}
   }
  }
     d[loc].flag=1;
     a[i]=d[loc].num-disk;
     if(a[i]<0){a[i]=disk-d[loc].num;}

     disk=d[loc].num;
 }
 for(i=0;i<m;i++)
 {
    k+=tr[i]/dt[i];
 }
 k=k/m;
 printf("turn around time for each request  :\n");
 for(int i=0;i<m;i++)
 {
     printf("%d\n",bt[i]+(tr[i]/dt[i]));
     q+=bt[i];
 }
 printf("Average turn around time   :\n");
 q=(q/m)+k;
 printf("%d",q);

 for(i=0;i<m;i++)
 {
 sum=sum+a[i];
 }
    printf("\nmovement of total cylinders %d",sum);
}
int sjfscan(int n,int m,int tr[])
{
int i,j,sum=0,dt[200],k=0,q=0;
 int d[200],bt[m],pos,temp,po[m];
 int disk;
 int max;
 int dloc,nb;
 printf("enter position of head\t");
 scanf("%d",&disk);
 cout<<"enter no.of IO bursts :"<<endl;
 cin>>nb;
 printf("enter elements of arrival times :\n");
 for(i=0;i<m;i++)
 {
 scanf("%d",&d[i]);
 }
 printf("enter size of data to be transfered for each request : \n");
 for(i=0;i<m;i++)
 {
     scanf("%d",&dt[i]);
 }
 d[m]=disk;
 m=m+1;
sort(d,d+m+1);
 max=d[m-1];
  cout<<"enter burst times :"<<endl;
    for(i=0;i<m;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        po[i]=i+1;           //contains process number
    }
for(i=0;i<m;i++)
    {
        pos=i;
        for(j=i+1;j<m;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=po[i];
        po[i]=po[pos];
        po[pos]=temp;
    }
    cout<<"\nsequence of execution of processes in CPU :"<<endl;
        for(i=0;i<m;i++)
    {
        printf("\np%d\t %d",po[i],bt[i]);
    }
 printf("\nsequence of execution of processes in disk drive\n");
 for(i=0;i<m;i++)
 {
 if(disk==d[i]) { dloc=i; break;  }
 }
 for(i=dloc;i>=0;i--)
 {
 printf("%d\n ",i);
 }
 for(i=dloc+1;i<m;i++)
 {
 printf("%d\n ",i);
 }
 sum=disk+max;
 for(i=0;i<m;i++)
 {
    k+=tr[i]/dt[i];
 }
 k=k/m;
 printf("turn around time for each request  :\n");
 for(int i=0;i<m;i++)
 {
     printf("%d\n",bt[i]+(tr[i]/dt[i]));
     q+=bt[i]+(tr[i]/dt[i]);
 }
 printf("Average turn around time for SCAN  :\n");
 q=(q/m);
 printf("%d",q);
printf("\nmovement of total cylinders %d",sum);
}
int sjfclook(int q_size,int m,int tr[])
{
    int queue[20], head,i,j, seek=0, diff, max, min, range, temp, queue1[20], queue2[20], temp1=0, temp2=0,dt[200],d[200],p=0,q=0,nb,bt[200],tempx,po[200],pos;
  printf("%s\t", "Enter initial head position");
  scanf("%d", &head);
cout<<"enter no.of IO bursts :"<<endl;
 cin>>nb;
  printf("%s\n", "Enter arrival times of processes :");

  for(i=0; i<m; i++){
    scanf("%d", &temp);
    d[i]=temp;
    //queue1 - elems greater than head
    if(temp >= head){
      queue1[temp1] = temp;
      temp1++;
    } else {
      queue2[temp2] = temp;
      temp2++;
    }
  }
   printf("enter size of data to be transfered for each request : \n");
 for(i=0;i<m;i++)
 {
     scanf("%d",&dt[i]);
 }
 for(i=0; i<temp1-1; i++){
    for(j=i+1; j<temp1; j++){
      if(queue1[i] > queue1[j]){
        temp = queue1[i];
        queue1[i] = queue1[j];
        queue1[j] = temp;
      }
    }
  for(i=0; i<temp2-1; i++){
    for(j=i+1; j<temp2; j++){
      if(queue2[i] > queue2[j]){
        temp = queue2[i];
        queue2[i] = queue2[j];
        queue2[j] = temp;
      }
    }
  }

  if(abs(head-LOW) <= abs(head-HIGH)){

    for(i=1,j=temp2-1; j>=0; i++,j--){
        queue[i] = queue2[j];
    }

    queue[i] = LOW;
    queue[i+1] = HIGH;

    for(i=temp2+3,j=temp1-1; j>=0; i++,j--){
        queue[i] = queue1[j];
    }

  } else {

    for(i=1,j=0; j<temp1; i++,j++){
        queue[i] = queue1[j];
    }

    queue[i] = HIGH;
    queue[i+1] = LOW;

    for(i=temp1+3,j=0; j<temp2; i++,j++){
        queue[i] = queue2[j];
    }


  }
  queue[0] = head;
 cout<<"enter burst times :"<<endl;
    for(i=0;i<m;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        po[i]=i+1;           //contains process number
    }
for(i=0;i<m;i++)
    {
        pos=i;
        for(j=i+1;j<m;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        tempx=bt[i];
        bt[i]=bt[pos];
        bt[pos]=tempx;

        tempx=po[i];
        po[i]=po[pos];
        po[pos]=tempx;
    }
    cout<<"\nsequence of execution of processes in CPU :"<<endl;
        for(i=0;i<m;i++)
    {
        printf("\np%d\t %d",po[i],bt[i]);
    }
  for(j=0; j<m; j++){
    diff=abs(queue[j+1] - queue[j]);
    seek += diff;

    printf("\nsequence of execution of processes %d\n",queue[j+1]+1);
  }
 for(i=0;i<m;i++)
 {
    p+=tr[i]/dt[i];
 }
 p=p/m;
 printf("turn around time for each request  :\n");
 for(int i=0;i<m;i++)
 {
     printf("%d\n",bt[i]+(tr[i]/dt[i]));
     q+=bt[i];
 }
 printf("Average turn around time for CLOOK  :\n");
 q=(q/m)+p;
 printf("%d",q+1);
 cout<<endl;
  printf("Total movements are %d\n", seek);
}}
int main()
{
    int n,m;
    cout<<"enter no.of cylinders :"<<endl;
    cin>>n;
    cout<<"enter no.of processes :"<<endl;
    cin>>m;
    int tr[m];
    cout<<"enter data transfer rate :"<<endl;
    for(int i=0;i<m;i++)
        cin>>tr[i];

    cout<<"1.SJF-FCFS"<<endl;
    cout<<"2.SJF-SSTF"<<endl;
    cout<<"3.SJF-SCAN"<<endl;
    cout<<"4.SJF-CLOOK"<<endl;
    cout<<"enter your choice :"<<endl;
    int ch;
    cin>>ch;
   switch(ch){
    case 1: sjffcfs(n,m,tr);
        break;
    case 2: sjfsstf(n,m,tr);
        break;
    case 3: sjfscan(n,m,tr);
        break;
    case 4: sjfclook(n,m,tr);
        break;
    default: printf("Invalid option");
         break;
}

}
