#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    // Declare variables
    string user;
    int password, choice, salary, finance_choice, add_finance, sub_finance, total, tax, amount_tax;
    int sec_choice;
    string note;
    string journal;
    string notes, feeling;
    int conversation;

    // Get the current time
    time_t now = time(0);
    char* dt = ctime(&now);

    // Print a welcome message
    cout << "<-------------------------------------------------------->\n";
    cout << "\n\n\nWhat's your name?" << endl;
    cin >> user;
    cout << "\n\n\n<-------------------------------------------------------->\n";
    cout << "\n\tWelcome to Your Personal Assistant (PERSONAL MANAGEMENT SYSTEM)" << endl;
    cout << "\tToday is " << dt << endl;

    // Ask for password
pass:
    cout << "Please Enter Your Password:" << endl;
    cin >> password;
    if (password == 123)
    {
        // Ask for user's choice
rep:
        cout << "What do you want to do? Press 1-4:" << endl;
        cout << " 1. Finance \n 2. Notes/Journal/Todos \n 3. Conversation \n 4. Calculator \n" << endl;
        cin >> choice;

        if (choice == 1) // User selected Finance
        {
            cout << "You choose Finance" << endl;
            cout << "What is your Salary?\n";
            cin >> salary;
            cout << "Do You want to: \n 1.Add Income + \n 2. Remove Expense - \n 3.Zakat \n 4 Taxes" << endl;
            cin >> finance_choice;
            if (finance_choice == 1) // User selected Add Income
            {
                cout << "How much more money you got this month?\n";
                cin >> add_finance;
                total = salary + add_finance;
                cout << "Your Total for this month is " << total << " Wohoo!\n" << endl;

                goto rep;
            }
            else if (finance_choice == 2) // User selected Remove Expense
            {
                cout << "How much more money you lost this month?\n";
                cin >> sub_finance;
                total = salary - sub_finance;
                cout << "Your Total for this month is " << total << " :(\n";
                goto rep;
            }
            else if (finance_choice == 3) // User selected Zakat
            {
                cout << "Amount of zakat you have to give from your salary is: " << 2.5 / 100 * salary << endl;
                goto rep;
            }
            else if (finance_choice == 4) // User selected Taxes
            {
                tax = salary * 12;
                if (tax <= 1200000)
                {
                    amount_tax = 2.5 / 100 * tax;
                    cout << "Your annual salary is less than 1.2 million" << endl;
                    cout << "You have to give " << amount_tax << " in taxes." << endl;
                    goto rep;
                }
                else
                {
                    amount_tax = 12.5 / 100 * tax;
                    cout << "your salary is more than 1.2 million" << endl;
                    cout << "You have to give " << amount_tax << " in taxes." << endl << endl;
                    goto rep;
                }
            }
       
        }
    }