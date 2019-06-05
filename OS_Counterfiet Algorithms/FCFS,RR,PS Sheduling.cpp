#include<bits/stdc++.h>
using namespace std;
void findWaitingTime_fcfs(int processes[], int n,int bt[], int wt[])
{
	wt[0] = 0;
	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}
void findTurnAroundTime_fcfs( int processes[], int n,int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}
void fcfs( int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	findWaitingTime_fcfs(processes, n, bt, wt);
	findTurnAroundTime_fcfs(processes, n, bt, wt, tat);
	cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n";
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time for FCFS process= "<< (float)total_wt / (float)n<<endl;
	cout << "Average turn around time for FCFS process= "<< (float)total_tat / (float)n<<endl;
	cout<<endl;
}
void findWaitingTime_rr(int processes[], int n,int bt[], int wt[], int quantum)
{
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];

    int t = 0;
    while (1)
    {
        bool done = true;
        for (int i = 0 ; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;
                if (rem_bt[i] > quantum)
                {
                    t += quantum;

                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
          break;
    }
}
void findTurnAroundTime_rr(int processes[], int n,int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
void rr(int processes[], int n, int bt[],int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime_rr(processes, n, bt, wt, quantum);
   findTurnAroundTime_rr(processes, n, bt, wt, tat);
    cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n";
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
    }

    cout << "Average waiting time for ROUND ROBIN= "<< (float)total_wt / (float)n<<endl;
    cout << "\nAverage turn around time for ROUND ROBIN= "<< (float)total_tat / (float)n<<endl;
    cout<<endl;
}
struct Process
{
    int pid;
    int bt;
    int priority;
};
bool comparison(Process a, Process b)
{
    return (a.priority > b.priority);
}
void findWaitingTime_ps(Process proc[], int n,int wt[])
{
    wt[0] = 0;
    for (int  i = 1; i < n ; i++ )
        wt[i] =  proc[i-1].bt + wt[i-1] ;
}
void findTurnAroundTime_ps( Process proc[], int n,int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findavgTime_ps(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime_ps(proc, n, wt);
    findTurnAroundTime_ps(proc, n, wt, tat);
    cout << "\nProcesses  "<< " Burst time"<< " Waiting time  " << " Turn around time\n";
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].pid << "\t\t"<< proc[i].bt << "\t    " << wt[i]<< "\t\t  " << tat[i] <<endl;
    }

    cout << "Average waiting time for PRIORITY SHEDULING= "<< (float)total_wt / (float)n<<endl;
    cout << "Average turn around time for PRIORITY SHEDULING= "<< (float)total_tat / (float)n<<endl;
}

void priorityScheduling(Process proc[], int n)
{

    sort(proc, proc + n, comparison);

    cout<< "Order in which processes gets executed \n";
    for (int  i = 0 ; i <  n; i++)
        cout << proc[i].pid <<" " ;

    findavgTime_ps(proc, n);
}
void waiting_time(struct process a[] , int n) ;

int main()
{

	cout<<"Enter the no.of processes"<<endl;
	int n;
	cin>>n;
	int processes[n];
	for(int i=0;i<n;i++)
        processes[i]=i+1;
    cout<<"Enter their burst times "<<endl;
	int burst_time[n];
	for(int i=0;i<n;i++)
        cin>>burst_time[i];
    int quantum;
    cout<<"Enter the time quantum "<<endl;
    cin>>quantum;
    Process proc[n];
    cout<<"Enter the burst time and priorities of the processes that are to be in priority scheduling "<<endl;
    for(int i=0;i<n;i++)
    {
        proc[i].pid=i+1;
        cout<<"enter burst time"<<endl;
        cin>>proc[i].bt;
        cout<<"enter the priority of the process "<<endl;
        cin>>proc[i].priority;
    }
    int x=sizeof proc/sizeof proc[0];
    cout<<"executing FCFS algorithm"<<endl;
	fcfs(processes, n, burst_time);
	cout<<"executing ROUND ROBIN algorithm"<<endl;
	rr(processes,n,burst_time,quantum);
	cout<<"executing PRIORITY SHEDULING algorithm"<<endl;
    priorityScheduling(proc,x);
}

