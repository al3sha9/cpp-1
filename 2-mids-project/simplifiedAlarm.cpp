#include <iostream>
#include <string>

using namespace std;

class Alarm {
private:
    int alarmHour;
    int alarmMinute;
    int alarmSecond;
    int remainingSeconds;

public:
    Alarm() {
        alarmHour = 0;
        alarmMinute = 0;
        alarmSecond = 0;
        remainingSeconds = 0;
    }

    void setAlarmTime(int hour, int minute, int second) {
        alarmHour = hour;
        alarmMinute = minute;
        alarmSecond = second;
    }

    void getTime() {
        cout << "Enter Alarm Time in 24-hour format [HH:MM:SS]: ";
        cin >> alarmHour;
        cin.ignore(); // Ignore the ':' character
        cin >> alarmMinute;
        cin.ignore(); // Ignore the ':' character
        cin >> alarmSecond;
    }

    void timeDifference() {
        int currentHour, currentMinute, currentSecond;
        cout << "Enter Current Time in 24-hour format [HH:MM:SS]: ";
        cin >> currentHour;
        cin.ignore(); // Ignore the ':' character
        cin >> currentMinute;
        cin.ignore(); // Ignore the ':' character
        cin >> currentSecond;

        // Calculate the remaining time in seconds
        remainingSeconds = (alarmHour - currentHour) * 3600 +
                          (alarmMinute - currentMinute) * 60 +
                          (alarmSecond - currentSecond);

        if (remainingSeconds < 0) {
            remainingSeconds += 86400; // Add a day's worth of seconds (24 hours)
        }
    }

    void startAlarm() {
        while (remainingSeconds > 0) {
            int hours = remainingSeconds / 3600;
            int minutes = (remainingSeconds % 3600) / 60;
            int seconds = remainingSeconds % 60;

            cout << "TIME REMAINING: " << hours << ":" << minutes << ":" << seconds << endl;
            remainingSeconds--;
            // Simulate a one-second delay (not precise)
            for (int i = 0; i < 100000000; i++) {
                // Delay loop
            }
        }

        cout << "Time Ended" << endl << ">>> Press Ctrl+C to stop the alarm <<<" << endl;
        while (true) {
            cout << '\a'; // Produces a beep sound
            // Simulate a one-second delay (not precise)
            for (int i = 0; i < 100000000; i++) {
                // Delay loop
            }
        }
    }
};

int main() {
    Alarm myAlarm;
    myAlarm.getTime();
    myAlarm.timeDifference();
    myAlarm.startAlarm();
    return 0;
}
