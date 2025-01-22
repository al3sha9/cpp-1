#include <iostream>
using namespace std;

int main()
{
  int n, t, max;
  int bu[10], wa[10], tat[10], ct[10]; // Burst time, waiting time, turnaround time, copy of burst times
  float awt = 0, att = 0, temp = 0;

  cout << "Enter the number of processes: ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cout << "\nEnter Burst Time for process " << i + 1 << ": ";
    cin >> bu[i];
    ct[i] = bu[i]; // Copy burst time into ct
  }

  cout << "\nEnter the size of time slice: ";
  cin >> t;

  // Find the maximum burst time
  max = bu[0];
  for (int i = 1; i < n; i++)
  {
    if (max < bu[i])
    {
      max = bu[i];
    }
  }

  // Round Robin Scheduling
  for (int j = 0; j < (max / t) + 1; j++)
  {
    for (int i = 0; i < n; i++)
    {
      if (bu[i] != 0)
      {
        if (bu[i] <= t)
        {
          tat[i] = temp + bu[i];
          temp += bu[i];
          bu[i] = 0;
        }
        else
        {
          bu[i] -= t;
          temp += t;
        }
      }
    }
  }

  // Calculate waiting time and turnaround time
  for (int i = 0; i < n; i++)
  {
    wa[i] = tat[i] - ct[i];
    att += tat[i];
    awt += wa[i];
  }

  // Output results
  cout << "\nThe Average Turnaround time is: " << att / n;
  cout << "\nThe Average Waiting time is: " << awt / n;

  cout << "\n\tPROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n";
  for (int i = 0; i < n; i++)
  {
    cout << "\t" << i + 1 << "\t " << ct[i] << "\t\t " << wa[i] << "\t\t " << tat[i] << "\n";
  }

  return 0;
}
