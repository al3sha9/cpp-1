#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int dt, int mn, int yr) : day(dt), month(mn), year(yr) {}

    void putDate(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    int fetchDay()
    {
        return day;
    }
    int fetchMonth()
    {
        return month;
    }
    int fetchYear()
    {
        return year;
    }

    bool checkValid()
    {
        if (year < 0 || month < 1 || month > 12 || day < 1)
        {
            return false;
        }
        if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                return day <= 29;
            }
            else
            {
                return day <= 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            return day <= 30;
        }
        else
        {
            return day <= 31;
        }
    }
};

int main()
{
    int day, month, year;

    cout << "Please Enter Date: " << endl;
    cin >> day;
    cout << "Please Enter Month: " << endl;
    cin >> month;
    cout << "Please Enter Year: " << endl;
    cin >> year;

    Date date(day, month, year);

    cout << "Date: " << date.fetchDay() << "-" << date.fetchMonth() << "-" << date.fetchYear() << endl;

    if (date.checkValid())
    {
        cout << "The Date is valid" << endl;
    }
    else
    {
        cout << "The date is invalid" << endl;
    }

    return 0;
}