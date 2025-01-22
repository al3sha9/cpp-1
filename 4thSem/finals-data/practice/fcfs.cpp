#include <iostream>
using namespace std;

int main()
{
  int bt[20], wt[20], tat[20];
  int totalProcesses;
  float wAvg = 0, tAvg = 0;

  cout << "enter the number of processes" << endl;
  cin >> totalProcesses;

  for (int i = 0; i < totalProcesses; i++)
  {
    cout << "enter burst time for processes" << endl;
    cin >> bt[i];
  }

  wt[0] = 0;
  tat[0] = bt[0];
  tAvg = tat[0];

  for (int i = 1; i < totalProcesses; i++)
  {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = wt[i] + bt[i];
    wAvg += wt[i];
    tAvg += tat[i];
  }

  cout << "\nPROCESS\t\tBURST TIME\t\tWAITING TIME\t\tTURNAROUND TIME\n";

  for (int i = 0; i < totalProcesses; i++)
  {
    cout << i << "\t\t" << bt[i] << "\t\t"<< wt[i] << "\t\t"<< tat[i] << "\n";
  }

  cout << "Average waiting time is" << wAvg / totalProcesses;
  cout << "Average Turn around time is " << tAvg / totalProcesses;

  return 0;
}