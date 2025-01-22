#include <iostream>
using namespace std;

int main()
{
  int p[20], bt[20], pri[20], tat[20], wt[20];
  float tatAvg = 0, wtAvg = 0;
  int temp, totalProcesses;
  cout << "enter total processes" << endl;
  cin >> totalProcesses;

      for (int i = 0; i < totalProcesses; i++)
  {
    p[i] = i + 1;
    cout << "enter the processes and their priorities" << endl;
    cin >> p[i] >> pri[i];
  }

  for (int i = 0; i < totalProcesses; i++)
  {
    for (int j = i + 1; j < totalProcesses; j++)
    {
      if (pri[i] > pri[j])
      {
        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;

        temp = p[i];
        p[i] = p[j];
        p[j] = temp;

        temp = pri[i];
        pri[i] = pri[j];
        pri[j] = temp;
      }
    }
  }

  wt[0] = 0;
  tat[0] = bt[0];
  tatAvg = bt[0];
  wtAvg = 0;

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