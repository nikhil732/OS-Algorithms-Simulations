#include<stdio.h>
int pgv[10],x=0,pvg1[10],y=0,pvg2[10],z=0;
void fifo()
{
    int i,j,n,a[50],frame[10],no,k,avail,count=0;
printf("\n ENTER THE NUMBER OF PAGES:\n");
scanf("%d",&n);
printf("\n ENTER THE PAGE NUMBER :\n");
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
printf("\n ENTER THE NUMBER OF FRAMES :");
scanf("%d",&no);
for(i=0;i<no;i++)
    frame[i]= -1;
j=0;
printf("ref string\t page frames\n");
for(i=1;i<=n;i++)
{
    printf("%d\t\t",a[i]);
    avail=0;
    for(k=0;k<no;k++)
    if(frame[k]==a[i])
    avail=1;
    if (avail==0)
    {
        frame[j]=a[i];
        j=(j+1)%no;
        count++;
        for(k=0;k<no;k++)
            printf("%d  ",frame[k]);
}
    printf("\n");
}
printf("Page Faults for FIFO are %d",count);
pgv[x++]=count;
printf("\n");
}
int findLRU(int time[], int n){
	int i, minimum = time[0], pos = 0;
    for(i = 1; i < n; ++i){
		if(time[i] < minimum){
			minimum = time[i];
			pos = i;
		}
	}
return pos;
}
void lru()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
	printf("Enter number of frames: ");
	scanf("%d", &no_of_frames);

	printf("Enter number of pages: ");
	scanf("%d", &no_of_pages);

	printf("Enter reference string: ");

    for(i = 0; i < no_of_pages; ++i){
    	scanf("%d", &pages[i]);
    }

	for(i = 0; i < no_of_frames; ++i){
    	frames[i] = -1;
    }
    printf(" Page Frames  \n");
    for(i = 0; i < no_of_pages; ++i){
    	flag1 = flag2 = 0;

    	for(j = 0; j < no_of_frames; ++j){
    		if(frames[j] == pages[i]){
	    		counter++;
	    		time[j] = counter;
	   			flag1 = flag2 = 1;
	   			break;
   			}
    	}

    	if(flag1 == 0){
			for(j = 0; j < no_of_frames; ++j){
	    		if(frames[j] == -1){
	    			counter++;
	    			faults++;
	    			frames[j] = pages[i];
	    			time[j] = counter;
	    			flag2 = 1;
	    			break;
	    		}
    		}
    	}

    	if(flag2 == 0){
    		pos = findLRU(time, no_of_frames);
    		counter++;
    		faults++;
    		frames[pos] = pages[i];
    		time[pos] = counter;
    	}

    	printf("\n");

    	for(j = 0; j < no_of_frames; ++j){
    		printf(" %d ", frames[j]);
    	}
	}
	printf("\n\nPage Faults for LRU are %d\n", faults);
	pvg1[y++]=faults;
}
void optimal()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");

    for(i = 0; i < no_of_pages; ++i){
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    printf(" Page Frames  \n");
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;

        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }

        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
        	flag3 =0;

            for(j = 0; j < no_of_frames; ++j){
            	temp[j] = -1;

            	for(k = i + 1; k < no_of_pages; ++k){
            		if(frames[j] == pages[k]){
            			temp[j] = k;
            			break;
            		}
            	}
            }

            for(j = 0; j < no_of_frames; ++j){
            	if(temp[j] == -1){
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }

            if(flag3 ==0){
            	max = temp[0];
            	pos = 0;

            	for(j = 1; j < no_of_frames; ++j){
            		if(temp[j] > max){
            			max = temp[j];
            			pos = j;
            		}
            	}
            }

			frames[pos] = pages[i];
			faults++;
        }

        printf("\n");

        for(j = 0; j < no_of_frames; ++j){
            printf("%d ", frames[j]);
        }
    }
    printf("\nPage Faults for Optimal are %d\n", faults);
    pvg2[z++]=faults;
    printf("\n");
}
int main()
{
    int t,k3=0,k2=0,k1=0;
    printf("Enter the value of Test Cases\n");
    scanf("%d",&t);
    while(t--)
    {

        printf("Enter the Choice\n");
        printf("[1] FIFO Page Replacement \n");
        printf("[2] LRU Page Replacement \n");
        printf("[3] Optimal Page Replacement \n");
        printf("[4] Exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
    case 1: k3++;
            fifo();
            break;
    case 2: k1++;
            lru();
            break;
    case 3: k2++;
            optimal();
            break;
    default : printf("Invalid Option\n");
                break;
        }
        int avg=0,avg1=0,avg2=0;
        if(k3>0){
        printf("Average Page Fault for FIFO is \n ");
        for(int i=0;i<k3;i++){

                avg+=pgv[i];}
        avg=avg/k3;
        printf("%d\n",avg);}
        if(k1>0){
        printf("Average Page Fault for LRU is \n ");
        for(int i=0;i<k1;i++)
            avg1+=pvg1[i];
        avg1=avg1/k1;
        printf("%d\n",avg1);}
        if(k2>0){
        printf("Average Page Fault for Optimal is \n ");
        for(int i=0;i<k2;i++){
            avg2+=pvg2[i];}
        avg2=avg2/k2;
        printf("%d\n",avg2);}
    }
return 0;
}
