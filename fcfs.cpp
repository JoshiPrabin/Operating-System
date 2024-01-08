#include <iostream>

using namespace std;

int main()
{
    int n, at[10], bt[10], wt[10], tat[10], ct[10];
    float awt = 0, atat = 0;
    cout << "Enter the number of processes to be scheduled using FCFS: ";
    cin >> n;
    cout << endl;
    cout << "Enter the arrival time of processes in order: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> at[i];
    }
    cout << "Enter the burst time of processes in order: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> bt[i];
    }
    ct[0] = 0;
    cout << "process\t at\t bt\t ct\t tat\t wt" << endl;
    for (int i = 0; i < n; i++)
    {
        ct[i + 1] = ct[i] + bt[i];
        tat[i] = ct[i + 1] - at[i];
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        cout << i + 1 << "\t " << at[i] << "\t " << bt[i] << "\t " << ct[i] << "\t " << tat[i] << "\t " << wt[i] << endl;
    }
    awt = awt / n;
    atat = atat / n;
    cout << "average waiting time = " << awt << endl;
    cout << "average turn around time = " << atat << endl;
    return 0;
}