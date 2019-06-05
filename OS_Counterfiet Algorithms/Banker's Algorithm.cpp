#include<iostream>
using namespace std;
int main()
{
    int P,R,processes[100],avail[100],maxm[100][100],allot[100][100],need[100][100];
    cout<<"enter no.of processes"<<endl;
    cin>>P;
    cout<<"enter no.of resources"<<endl;
    cin>>R;
	cout<<"enter the processes"<<endl;
	for(int i=0;i<P;i++)
        cin>>processes[i];
    cout<<"enter the available matrix"<<endl;
    for(int i=0;i<R;i++)
        cin>>avail[i];
    cout<<"enter the max matrix"<<endl;
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
                cin>>maxm[i][j];
        }
    }
    cout<<"enter the allocation matrix"<<endl;
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++)
        {
            cin>>allot[i][j];
            }
        }
        for (int i = 0 ; i < P ; i++)
		for (int j = 0 ; j < R ; j++)
			need[i][j] = maxm[i][j] - allot[i][j];

    bool finish[P] = {0};
    int safeSeq[P];
    int work[R];
    for (int i = 0; i < R ; i++)
        work[i] = avail[i];
    int count = 0;
    while (count < P)
    {
        bool found = false;
        for (int p = 0; p < P; p++)
        {
            if (finish[p] == 0)
            {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;
                if (j == R)
                {

                    for (int k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if (found == false)
        {
            cout << "System is not in safe state";
            return 0;
        }
    }
    cout << "System is in safe state.\nSafe sequence is: ";
    for (int i = 0; i < P ; i++)
        cout << safeSeq[i] << " ";

return 0;
}
