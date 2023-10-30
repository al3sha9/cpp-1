#include <iostream>
#include <ctime>

using namespace std; // Using the std namespace

class Calendar
{
public:
    Calendar()
    {
        time_t now = time(0);
        currentDate = *localtime(&now);
        year = 1900 + currentDate.tm_year;
        month = 1 + currentDate.tm_mon;
        day = currentDate.tm_mday;
    }

    void displayCurrentMonthCalendar()
    {
        daysInMonth = getDaysInMonth(year, month);
        calculateFirstDay();

        cout << "\t\t  " << year << " - " << month << "   \n";
        cout << " Su  Mo  Tu  We  Th  Fr  Sa\n";

        for (int i = 0; i < startingDay; i++)
        {
            cout << "   ";
        }

        for (int i = 1; i <= daysInMonth; i++)
        {
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
    tm currentDate;
    int year;
    int month;
    int day;
    int daysInMonth;
    int startingDay;

    int getDaysInMonth(int year, int month)
    {
        const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = daysInMonth[month];
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            days = 29;
        }
        return days;
    }

    void calculateFirstDay()
    {
        tm firstDay = {0, 0, 0, 1, month - 1, year - 1900};
        mktime(&firstDay);
        startingDay = firstDay.tm_wday;
    }
};

int main()
{
    Calendar calendar;
    calendar.displayCurrentMonthCalendar();
    return 0;
}
