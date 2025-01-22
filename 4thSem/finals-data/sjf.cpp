#include <iostream>
using namespace std;

int main()
{
  int p[20], bt[20], wt[20], tat[20];
  int i, k, n, temp;
  float wtavg = 0, tatavg = 0;

  cout << "\nEnter the number of processes: ";
  cin >> n;

  for (i = 0; i < n; i++)
  {
    p[i] = i;
    cout << "Enter Burst Time for Process " << i << ": ";
    cin >> bt[i];
  }

  // Sorting burst times in ascending order using Bubble Sort
  for (i = 0; i < n; i++)
  {
    for (k = i + 1; k < n; k++)
    {
      if (bt[i] > bt[k])
      {
        // Swap burst time
        temp = bt[i];
        bt[i] = bt[k];
        bt[k] = temp;

        // Swap process numbers
        temp = p[i];
        p[i] = p[k];
        p[k] = temp;
      }
    }
  }

  wt[0] = 0;      // Waiting time for the first process is 0
  tat[0] = bt[0]; // Turnaround time for the first process is its burst time
  tatavg = bt[0]; // Initialize total turnaround time

  for (i = 1; i < n; i++)
  {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = wt[i] + bt[i];
    wtavg += wt[i];
    tatavg += tat[i];
  }

  cout << "\n\tPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
  for (i = 0; i < n; i++)
  {
    cout << "\tP" << p[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
  }

  cout << "\nAverage Waiting Time: " << wtavg / n;
  cout << "\nAverage Turnaround Time: " << tatavg / n << "\n";

  return 0;
}
