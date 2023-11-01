#include <iostream>
#include <ctime>
#include <cstdlib> // For system("pause") on Windows

using namespace std;

class Stopwatch
{
private:
    time_t startTime;
    time_t stopTime;

public:
    void start()
    {
        startTime = time(nullptr);
        cout << "Stopwatch started. Press 's' to stop." << endl;
    }

    void stop()
    {
        stopTime = time(nullptr);
        cout<<"\a";
        cout << "Stopwatch stopped." << endl;
    }

    double getElapsedSeconds()
    {
        return difftime(stopTime, startTime);
    }
};

int main()
{
    char action;

    do
    {
        cout << "Press 's' to start the stopwatch or 'q' to quit: ";
        cin >> action;

        if (action == 's')
        {
            Stopwatch stopwatch;
            stopwatch.start();

            while (cin >> action)
            {
                if (action == 's')
                {
                    stopwatch.stop();
                    break;
                }
            }

            cout << "Elapsed time: " << stopwatch.getElapsedSeconds() << " seconds" << endl;
        }
    } while (action != 'q');

    cout << "Goodbye!" << endl;

    return 0;
}
