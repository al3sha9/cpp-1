#include <iostream>
using namespace std;

int main() {
    int n;
    int bt[20], wt[20], tat[20];
    float wtavg = 0, tatavg = 0;

    cout << "\nEnter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Burst Time for Process " << i << ": ";
        cin >> bt[i];
    }

    wt[0] = 0; // Waiting time for the first process is always 0
    tat[0] = bt[0];
    tatavg = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    cout << "\n\tPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for (int i = 0; i < n; i++) {
        cout << "\tP" << i << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << wtavg / n;
    cout << "\nAverage Turnaround Time: " << tatavg / n << "\n";

    return 0;
}
