#include <iostream>
using namespace std;

int main()
{
    int weather, humidity, wind;
    cout << "what is the Weather Today? \n 1.Sunny \n 2.Overcast \n 3.Rain" << endl;
    cin >> weather;

    if (weather == 1)
    {
        cout << "\n You choose Sunny!";
        cout << "\n What is the humidity? \n 1. High \n 2.Normal" << endl;
        cin >> humidity;
        if (humidity == 1)
        {
            cout << "Today is a High Humidity Day" << endl;
        }
        else
        {
            cout << "Today is a low humidity Day" << endl;
        }
    }
    else if (weather == 2)
    {
        cout << "Today is an Overcast Day" << endl;
    }
    else if (weather == 3)
    {
        cout << "\n You choose Rain!";
        cout << "\n What is the Wind Like? \n 1. Strong \n 2.Weak" << endl;
        cin >> wind;
        if (wind == 1)
        {
            cout << "Today is a Windy Day" << endl;
        }
        else
        {
            cout << "Today is not a windy Day" << endl;
        }
    }

    return 0;
}