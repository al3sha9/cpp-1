#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <unistd.h>

using namespace std;

class Alarm
{
public:
    tm alarmTime, presentTime, differenceInTime;

    Alarm()
    {
        time_t now = time(0);
        presentTime = *localtime(&now);
        alarmTime = presentTime;
        alarmTime.tm_sec = 0;
    }

    void getTime()
    {
        string time;
        cout << "Enter Alarm Time in 24-hour format [HH:MM]: ";
        cin >> time;

        int pos = 0, h;
        while ((pos = time.find(':')) != string::npos)
        {
            string token = time.substr(0, pos);
            stringstream convert(token);
            convert >> alarmTime.tm_hour;
            time.erase(0, pos + 1);
        }

        stringstream convert(time);
        convert >> alarmTime.tm_min;
    }

    void timeDifference()
    {
        time_t now = time(0);
        int sec = difftime(mktime(&alarmTime), now);
        differenceInTime.tm_min = sec / 60;
        differenceInTime.tm_hour = differenceInTime.tm_min / 60;
        differenceInTime.tm_min = differenceInTime.tm_min % 60;
        differenceInTime.tm_sec = sec % 60;

        if (sec < 0)
        {
            differenceInTime.tm_hour = 24 + differenceInTime.tm_hour - 1;
            differenceInTime.tm_min = 0 - differenceInTime.tm_min;
            differenceInTime.tm_sec = 0 - differenceInTime.tm_sec;
        }
    }

    void startAlarm()
    {
        while (true)
        {
            system("clear"); // Clear the console on Linux
            time_t now = time(0);
            presentTime = *localtime(&now);
            timeDifference();
            cout << "TIME REMAINING: " << differenceInTime.tm_hour << ":" << differenceInTime.tm_min << ":" << differenceInTime.tm_sec << endl;

            if (differenceInTime.tm_hour == 0 && differenceInTime.tm_min == 0 && differenceInTime.tm_sec == 0)
            {
                cout << "Time Ended" << endl
                     << ">>> Press Ctrl+C to stop the alarm <<<" << endl;
                while (true)
                {
                    cout << '\a';
                    sleep(1);
                }
            }

            sleep(1);
        }
    }
};

int main()
{
    Alarm a;
    a.getTime();
    a.startAlarm();
    return 0;
}
