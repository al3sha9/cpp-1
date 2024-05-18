#include <iostream>
#include <ctime>

using namespace std;

class DateInfo
{
protected:
    tm currentDate;

public:
    DateInfo()
    {
        time_t now = time(0);
        currentDate = *localtime(&now);
    }

    int getYear() const
    {
        return 1900 + currentDate.tm_year;
    }

    int getMonth() const
    {
        return 1 + currentDate.tm_mon;
    }

    int getDay() const
    {
        return currentDate.tm_mday;
    }

    virtual int getDaysInMonth(int year, int month) const
    {
        const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = daysInMonth[month];
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            days = 29;
        }
        return days;
    }

    virtual int calculateFirstDay(int year, int month) const
    {
        tm firstDay = {0, 0, 0, 1, month - 1, year - 1900};
        mktime(&firstDay);
        return firstDay.tm_wday;
    }
};

class Calendar : public DateInfo
{
public:
    void displayCurrentMonthCalendar()
    {
        int year = getYear();
        int month = getMonth();
        int day = getDay();
        int daysInMonth = getDaysInMonth(year, month);
        int startingDay = calculateFirstDay(year, month);

        cout << "\t\t  " << year << " - " << month << "   \n";
        cout << " Su  Mo  Tu  We  Th  Fr  Sa\n";

        int daysArray[32]; // Store the days of the month for sorting
        for (int i = 0; i < startingDay; i++)
        {
            cout << "    ";
        }

        for (int i = 1; i <= daysInMonth; i++)
        {
            daysArray[i] = i; // Store the days in an array for sorting
            if (i < 10)
                cout << " ";
            if (i == day)
                cout << "[" << i << "]";
            else
                cout << " " << i << " ";
            if ((i + startingDay) % 7 == 0 || i == daysInMonth)
                cout << endl;
        }

        // Example of binary search
        int searchDay;
        cout << "\nEnter the day to search: ";
        cin >> searchDay;
        int binaryResult = binarySearch(daysArray, 1, daysInMonth, searchDay);
        if (binaryResult != -1)
            cout << "Binary Search (Found at index) " << binaryResult << endl;
        else
            cout << "Binary Search (Not found)" << endl;
    }

    // Binary Search implementation
    //allows the user to input a day to search for, and it uses the binarySearch function to find and print the result.
    int binarySearch(int arr[], int low, int high, int key)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key)
                return mid;
            if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

int main()
{
    Calendar calendar;
    calendar.displayCurrentMonthCalendar();
    return 0;
}
