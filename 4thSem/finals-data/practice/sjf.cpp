#include <iostream>
using namespace std;

int main()
{
  int totalProcesses, temp;
  int bt[20], wt[20], tat[20], p[20];
  float tatAvg = 0, wtAvg = 0;

  cout << "Enter total processes" << endl;
  cin >> totalProcesses;

  for (int i = 0; i < totalProcesses; i++)
  {
    p[i] = i;
    cout << "Enter the burst time for processes" << endl;
    cin >> bt[i];
  }

  for (int i = 0; i < totalProcesses; i++)
  {
    for (int j = 0; j < totalProcesses; j++)
    {
      if (bt[i] > bt[j])
      {
        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;

        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }

  wt[0] = 0;
  tat[0] = bt[0];
  tatAvg = bt[0];

  for (int i = 1; i < totalProcesses; i++)
  {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = wt[i] + bt[i];
    wtAvg += wt[i];
    tatAvg += tat[i];
  }

  cout << "\n\tPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
  for (int i = 0; i < totalProcesses; i++)
  {
    cout << "\tP" << p[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
  }

  cout << "\nAverage Waiting Time: " << wtAvg / totalProcesses;
  cout << "\nAverage Turnaround Time: " << tatAvg / totalProcesses << "\n";

  return 0;
}