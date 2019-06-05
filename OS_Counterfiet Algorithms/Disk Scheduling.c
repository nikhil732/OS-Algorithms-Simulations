#include<conio.h>
#include<stdio.h>
#define LOW 0
#define HIGH 199
struct di
{
int num;
int flag;
};
void fcfs()
{
 int i,j,sum=0,n,k=0,q=0;
 int ar[200],tm[200],dt[200],tr[200];
 int disk;
 printf("enter no.of cylinders : ");
 scanf("%d",&n);
 printf("enter position of head  :");
 scanf("%d",&disk);
 printf("enter arrival times of disk queue\n");
 for(i=0;i<n;i++)
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
 for(i=0;i<n;i++)
 {
     scanf("%d",&dt[i]);
 }
 printf("enter transfer rate for each request : \n");
 for(i=0;i<n;i++)
 {
     scanf("%d",&tr[i]);
 }
 printf("sequence of execution of processes in FCFS : \n");
 for(i=0;i<n;i++)
 {
     printf("%d\n",i);
 }
 printf("waiting times of each request\n");
 for(i=0;i<n;i++)
 {
    printf("%d\n",tr[i]/dt[i]);
    k+=tr[i]/dt[i];
 }
 printf("Average waiting time of FCFS : \n");
 k=k/n;
 printf("%d\n",k);
 printf("turn around time for each request  :\n");
 for(int i=0;i<n;i++)
 {
     printf("%d\n",ar[i]+(tr[i]/dt[i]));
     q+=ar[i];
 }
 printf("Average turn around time for FCFS  :\n");
 q=(q/n)+k;
 printf("%d",q);
 printf("\nmovement of total cylinders %d",sum);
}
void sstf()
{
 int i,j,sum=0,n,min,loc,x,y,k=0,q=0,p;
 struct di d[200];
 int disk;
 int ar[200],a[200],dt[200],tr[200],dif[200];
 printf("enter number of location\t");
 scanf("%d",&n);
 printf("enter position of head\t");
 scanf("%d",&disk);
 printf("enter elements of disk queue\n");
 for(i=0;i<n;i++)
 {
 scanf("%d",&d[i].num);   d[i]. flag=0;
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
  printf("sequence of execution of execution of processes in SSTF  : \n");
  int z=100000;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {

            if(d[i].num-d[j].num>0)
                {
                    p=d[i].num-d[j].num;
                    }
            else
                p=d[j].num-d[i].num;
            if(z>p)
            {
                z=p;
            dif[i]=j;
            }
        }

  }
  printf("0\n");
  for(i=1;i<n;i++)
  {
      printf("%d\n",dif[i]);
  }
 for(i=0;i<n;i++)
 {                 x=0; min=0;loc=0;
  for(j=0;j<n;j++)
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
 printf("waiting times of each request\n");
 for(i=0;i<n;i++)
 {
    printf("%d\n",tr[i]/dt[i]);
    k+=tr[i]/dt[i];
 }
 printf("Average waiting time of SSTF : \n");
 k=k/n;
 printf("%d\n",k);
 printf("turn around time for each request  :\n");
 for(int i=0;i<n;i++)
 {
     printf("%d\n",ar[i]+(tr[i]/dt[i]));
     q+=ar[i];
 }
 printf("Average turn around time for SSTF  :\n");
 q=(q/n)+k;
 printf("%d",q);

 for(i=0;i<n;i++)
 {
 sum=sum+a[i];
 }
    printf("\nmovement of total cylinders %d",sum);
}
void scan()
{
int i,j,sum=0,n,dt[200],tr[200],k=0,q=0;
 int d[20];
 int disk;
 int temp,max;
 int dloc;

 printf("enter number of location\t");
 scanf("%d",&n);
 printf("enter position of head\t");
 scanf("%d",&disk);
 printf("enter elements of disk queue\n");
 for(i=0;i<n;i++)
 {
 scanf("%d",&d[i]);
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
 d[n]=disk;
 n=n+1;
 for(i=0;i<n;i++)
 {
  for(j=i;j<n;j++)
  {
    if(d[i]>d[j])
    {
    temp=d[i];
    d[i]=d[j];
    d[j]=temp;
    }
  }
 }
 max=d[n];
 printf("sequence of execution of processes \n");
 for(i=0;i<n;i++)
 {
 if(disk==d[i]) { dloc=i; break;  }
 }
 for(i=dloc;i>=0;i--)
 {
 printf("%d ",d[i]);
 }
 printf("0 ");
 for(i=dloc+1;i<n;i++)
 {
 printf("%d  ",d[i]);
 }
 sum=disk+max;
printf("waiting times of each request\n");
 for(i=0;i<n;i++)
 {
    printf("%d\n",tr[i]/dt[i]);
    k+=tr[i]/dt[i];
 }
 printf("Average waiting time of SCAN : \n");
 k=k/n;
 printf("%d\n",k);
 printf("turn around time for each request  :\n");
 for(int i=0;i<n;i++)
 {
     printf("%d\n",ar[i]+(tr[i]/dt[i]));
     q+=ar[i];
 }
 printf("Average turn around time for SCAN  :\n");
 q=(q/n)+k;
 printf("%d",q);
printf("\nmovement of total cylinders %d",sum);
}
void cscan()
{
     int queue[20],n,head,i,j,k,seek=0,max,diff,temp,p=0,q=0;
     int queue1[200],queue2[200],temp1=0,temp2=0,dt[200],tr[200],d[200];
            printf("Enter the no.of cylinders\n");
            scanf("%d",&max);
            printf("Enter the initial head position\n");
            scanf("%d",&head);
            n=max;
            printf("Enter the elements of disk queue\n");
            for(i=1;i<=n;i++)
            {
                        scanf("%d",&temp);
                        d[i]=temp;
                        if(temp>=head)
                        {
                                    queue1[temp1]=temp;
                                    temp1++;
                        }
                        else
                        {
                                    queue2[temp2]=temp;
                                    temp2++;
                        }
            }
            for(i=0;i<temp1-1;i++)
            {
                        for(j=i+1;j<temp1;j++)
                        {
                                    if(queue1[i]>queue1[j])
                                    {
                                                temp=queue1[i];
                                                queue1[i]=queue1[j];
                                                queue1[j]=temp;
                                    }
                        }
            }
            for(i=0;i<temp2-1;i++)
            {
                        for(j=i+1;j<temp2;j++)
                        {
                                    if(queue2[i]>queue2[j])
                                    {
                                                temp=queue2[i];
                                                queue2[i]=queue2[j];
                                                queue2[j]=temp;
                                    }
                        }
            }
            for(i=1,j=0;j<temp1;i++,j++)
            queue[i]=queue1[j];
            queue[i]=max;
            queue[i+1]=0;
            for(i=temp1+3,j=0;j<temp2;i++,j++)
            queue[i]=queue2[j];
            queue[0]=head;
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
            printf("sequence of execution of processes in CSCAN \n");
            for(j=0;j<=n+1;j++)
            {
                if(queue[j+1]-queue[j]>0)
                {
                    diff=queue[j+1]-queue[j];
                }
                else
                {diff=queue[j]-queue[j+1];}

                        seek+=diff;
                        printf("%d\n",queue[j+1]);
            }
            printf("waiting times of each request\n");
 for(i=0;i<n;i++)
 {
    printf("%d\n",tr[i]/dt[i]);
    p+=tr[i]/dt[i];
 }
 printf("Average waiting time of CSCAN : \n");
 p=p/n;
 printf("%d\n",p);
 printf("turn around time for each request  :\n");
 for(int i=0;i<n;i++)
 {
     printf("%d\n",bt[i]+(tr[i]/dt[i]));
     q+=bt[i];
 }
 printf("Average turn around time for CSCAN  :\n");
 q=(q/n)+p;
 printf("%d",q);
printf("Total no.of cylinders moved %d\n",seek);
}
void look(){
  int queue[200];
  int head, max, q_size, temp, sum,dt[200],tr[200],p=0,q=0;
  int dloc;
printf("%s\t", "Input no of disk locations");
  scanf("%d", &q_size);
  printf("%s\t", "Enter head position");
  scanf("%d", &head);
printf("%s\n", "Input elements into disk queue");
  for(int i=0; i<q_size; i++){
    scanf("%d", &queue[i]);
  }
  printf("enter size of data to be transfered for each request : \n");
 for(int i=0;i<q_size;i++)
 {
     scanf("%d",&dt[i]);
 }
 printf("enter transfer rate for each request : \n");
 for(int i=0;i<q_size;i++)
 {
     scanf("%d",&tr[i]);
 }
  queue[q_size] = head;
  q_size++;

for(int i=0; i<q_size;i++){
    for(int j=i; j<q_size; j++){
      if(queue[i]>queue[j]){
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }
max = queue[q_size-1];
    for(int i=0; i<q_size; i++){
    if(head == queue[i]){
      dloc = i;
      break;
    }
  }
if(abs(head-LOW) <= abs(head-HIGH)){
      for(int j=dloc; j>=0; j--){
        printf("%d  ",queue[j]);
      }
      for(int j=dloc+1; j<q_size; j++){
        printf("%d  ",queue[j]);
      }
      } else {
      for(int j=dloc+1; j<q_size; j++){
          printf("%d  ",queue[j]);
      }
      for(int j=dloc; j>=0; j--){
          printf("%d  ",queue[j]);
      }
  }
printf("waiting times of each request\n");
 for(int i=0;i<q_size;i++)
 {
    printf("%d\n",tr[i]/dt[i]);
    p+=tr[i]/dt[i];
 }
 printf("Average waiting time of LOOK : \n");
 p=p/q_size;
 printf("%d\n",p);
 printf("turn around time for each request  :\n");
 for(int i=0;i<q_size;i++)
 {
     printf("%d\n",bt[i]+(tr[i]/dt[i]));
     q+=bt[i];
 }
 printf("Average turn around time for LOOK  :\n");
 q=(q/q_size)+p;
 printf("%d",q);
sum  = head + max;
  printf("\nmovement of total cylinders %d", sum);
}
void clook()
{
    int queue[20], head, q_size, i,j, seek=0, diff, max, min, range, temp, queue1[20], queue2[20], temp1=0, temp2=0,dt[200],tr[200],d[200],p=0,q=0;
  printf("%s\t", "Input the number of disk locations");
  scanf("%d", &q_size);

  printf("%s\t", "Enter initial head position");
  scanf("%d", &head);

  printf("%s\n", "Enter disk positions to read");

  for(i=0; i<q_size; i++){
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
 for(i=0;i<q_size;i++)
 {
     scanf("%d",&dt[i]);
 }
 printf("enter transfer rate for each request : \n");
 for(i=0;i<q_size;i++)
 {
     scanf("%d",&tr[i]);
 }
 for(i=0; i<temp1-1; i++){
    for(j=i+1; j<temp1; j++){
      if(queue1[i] > queue1[j]){
        temp = queue1[i];
        queue1[i] = queue1[j];
        queue1[j] = temp;
      }
    }}
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

  for(j=0; j<q_size; j++){
    diff=abs(queue[j+1] - queue[j]);
    seek += diff;
    printf("sequence of execution of processes %d\n",queue[j+1]);
  }
  printf("waiting times of each request\n");
 for(i=0;i<q_size;i++)
 {
    printf("%d\n",tr[i]/dt[i]);
    p+=tr[i]/dt[i];
 }
 printf("Average waiting time of CLOOK : \n");
 p=p/q_size;
 printf("%d\n",p);
 printf("turn around time for each request  :\n");
 for(int i=0;i<q_size;i++)
 {
     printf("%d\n",bt[i]+(tr[i]/dt[i]));
     q+=bt[i];
 }
 printf("Average turn around time for CLOOK  :\n");
 q=(q/q_size)+p;
 printf("%d",q);
  printf("Total movements are %d\n", seek);
}
int main()
{
printf("1. FCFS\n");
printf("2. SSTF\n");
printf("3. SCAN\n");
printf("4. CSCAN\n");
printf("5. LOOK\n");
printf("6. CLOOK\n");
int n;
printf("enter choice\n");
scanf("%d",&n);
switch(n){
case 1: fcfs();
        break;
case 2: sstf();
        break;
case 3: scan();
        break;
case 4: cscan();
        break;
case 5: look();
        break;
case 6: clook();
        break;
default: printf("Invalid option");
         break;
}
 return 0;
}
