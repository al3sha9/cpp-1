#include <iostream>
using namespace std;

int main()
{
  int p[20], bt[20], pri[20], wt[20], tat[20], n, temp;
  float wtavg = 0, tatavg = 0;

  cout << "Enter the number of processes: ";
  cin >> n;

  // Input burst time and priority
  for (int i = 0; i < n; i++)
  {
    p[i] = i + 1; // Assign process numbers
    cout << "Enter the Burst Time and Priority of Process " << i + 1 << ": ";
    cin >> bt[i] >> pri[i];
  }

  // Sort processes based on priority (ascending order)
  for (int i = 0; i < n; i++)
  {
    for (int k = i + 1; k < n; k++)
    {
      if (pri[i] > pri[k])
      {
        // Swap process numbers
        temp = p[i];
        p[i] = p[k];
        p[k] = temp;

        // Swap burst times
        temp = bt[i];
        bt[i] = bt[k];
        bt[k] = temp;

        // Swap priorities
        temp = pri[i];
        pri[i] = pri[k];
        pri[k] = temp;
      }
    }
  }

  // Calculate waiting time and turnaround time
  wt[0] = 0;      // First process has no waiting time
  tat[0] = bt[0]; // Turnaround time for the first process is its burst time
  wtavg = 0;
  tatavg = tat[0];

  for (int i = 1; i < n; i++)
  {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = tat[i - 1] + bt[i];
    wtavg += wt[i];
    tatavg += tat[i];
  }

  // Display results
  cout << "\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
  for (int i = 0; i < n; i++)
  {
    cout << p[i] << "\t" << pri[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
  }

  // Display averages
  cout << "\nAverage Waiting Time is: " << wtavg / n;
  cout << "\nAverage Turnaround Time is: " << tatavg / n;

  return 0;
}
