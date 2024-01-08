#include <iostream>
#include <algorithm>

using namespace std;

struct Process
{
    int id;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
};

bool comparebt(const Process &a, const Process &b)
{
    return a.bt < b.bt;
}

int main()
{
    int n;
    float awt = 0, atat = 0;
    cout << "Enter the number of processes to be scheduled using SJF: ";
    cin >> n;

    Process processes[n];

    cout << "Enter the arrival time of processes in order: " << endl;
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cin >> processes[i].at;
    }

    cout << "Enter the burst time of processes in order: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> processes[i].bt;
    }

    sort(processes, processes + n, comparebt);

    cout << "process\t at\t bt\t ct\t tat\t wt" << endl;

    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        ct = ct + processes[i].bt;
        processes[i].ct = ct;
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;

        awt += processes[i].wt;
        atat += processes[i].tat;

        cout << processes[i].id << "\t " << processes[i].at << "\t " << processes[i].bt
             << "\t " << ct << "\t " << processes[i].tat
             << "\t " << processes[i].wt << endl;
    }

    awt /= n;
    atat /= n;

    cout << "average waiting time = " << awt << endl;
    cout << "average turn around time = " << atat << endl;

    return 0;
}
