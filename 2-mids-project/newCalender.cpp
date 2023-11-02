#include <iostream>
using namespace std;

class SimpleCalendar {
private:
    int year;
    int month;
    int day;
    int startingDay; // 0 for Sunday, 1 for Monday, and so on
    int daysInMonth;

public:
    SimpleCalendar(int y, int m, int d) : year(y), month(m), day(d) {
        daysInMonth = getDaysInMonth(year, month);
        calculateFirstDay();
    }

    void displayCurrentMonthCalendar() {
        cout << "\t\t  " << year << " - " << month << "   \n";
        cout << " Su  Mo  Tu  We  Th  Fr  Sa\n";

        for (int i = 0; i < startingDay; i++) {
            cout << "    ";
        }

        for (int i = 1; i <= daysInMonth; i++) {
            if (i < 10)
                cout << " ";
            if (i == day)
                cout << "[" << i << "]";
            else
                cout << " " << i << " ";
            if ((i + startingDay) % 7 == 0 || i == daysInMonth)
                cout << endl;
        }
    }

private:
    int getDaysInMonth(int year, int month) {
        const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = daysInMonth[month];
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            days = 29;
        }
        return days;
    }

    void calculateFirstDay() {
        // In reality, you'd need a complex algorithm to calculate the first day of the month.
        // This simple example just assumes the first day is Sunday.
        startingDay = 0;
    }
};

int main() {
    SimpleCalendar calendar(2023, 10, 31);
    calendar.displayCurrentMonthCalendar();
    return 0;
}
