#include <iostream>
#include <ctime>
#include <cstdlib> // For system("pause") on Windows

using namespace std;

int main()
{
    time_t startTime, stopTime;
    char action;

    do
    {
        cout << "Press 's' to start the stopwatch or 'q' to quit: ";
        cin >> action;

        if (action == 's')
        {
            startTime = time(nullptr);
            cout << "Stopwatch started. Press 's' to stop." << endl;
            while (cin >> action)
            {
                if (action == 's')
                {
                    stopTime = time(nullptr);
                    cout << "Stopwatch stopped." << endl;
                    break;
                }
            }

            double elapsedSeconds = difftime(stopTime, startTime);
            cout << "Elapsed time: " << elapsedSeconds << " seconds" << endl;
        }
    } while (action != 'q');

    cout << "Goodbye!" << endl;

    return 0;
}
