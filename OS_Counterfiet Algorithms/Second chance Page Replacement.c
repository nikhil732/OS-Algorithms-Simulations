#include<stdio.h>
int n,nf;
int in[100];
int p[50];
int hit=0;
int i,j,k;
int pgfaultcnt=0;
void getData()
{
    printf("\nEnter length of page reference sequence:");
    scanf("%d",&n);
    printf("\nEnter the page reference sequence:");
    for(i=0; i<n; i++)
        scanf("%d",&in[i]);
    printf("\nEnter no of frames:");
    scanf("%d",&nf);
}
int isHit(int data)
{
    hit=0;
    for(j=0; j<nf; j++)
    {
        if(p[j]==data)
        {
            hit=1;
            break;
        }

    }
return hit;
}
int getHitIndex(int data)
{
    int hitind;
    for(k=0; k<nf; k++)
    {
        if(p[k]==data)
        {
            hitind=k;
            break;
        }
    }
    return hitind;
}
void secondchance()
{
    int usedbit[50];
    int victimptr=0;
     pgfaultcnt=0;
    for(i=0; i<nf; i++)
        p[i]=9999;
    for(i=0; i<nf; i++)
        usedbit[i]=0;
    for(i=0; i<n; i++)
    {
        printf("\nFor %d:",in[i]);
        if(isHit(in[i]))
        {
            printf("No page fault!");
            int hitindex=getHitIndex(in[i]);
            if(usedbit[hitindex]==0)
                usedbit[hitindex]=1;
        }
        else
        {
            pgfaultcnt++;
            if(usedbit[victimptr]==1)
            {
                 while(usedbit[victimptr]!=0)

                {
                    usedbit[victimptr]=0;
                    victimptr++;
                    if(victimptr==nf)
                        victimptr=0;
                }

            }
            if(usedbit[victimptr]==0)
            {
                p[victimptr]=in[i];
                usedbit[victimptr]=1;
                victimptr++;
            }
            for (k=0; k<nf; k++)
            {
            if(p[k]!=9999)
            printf(" %d",p[k]);
            }
        }
        if(victimptr==nf)
            victimptr=0;
    }
    printf("\nTotal no of page faults:%d",pgfaultcnt);
}
int main()
{
    int t;
    printf("\nEnter the value of Test Cases : \n");
    scanf("%d",&t);
    while(t--)
    {
    getData();
    secondchance();
    }
    return 0;
}
