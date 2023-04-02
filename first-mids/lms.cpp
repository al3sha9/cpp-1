#include <iostream>
#include <string>
#include <ctime>

using namespace std;
// FoP Project 1
int main()
{ /*Note:
	  if you enter incorrect data according to the data type, then it will repeat the process.
	  Otherwise if you type something different rather than the datatype it will cause a loop that will
	  run continously, until you close the program. Be careful!
  */
	string user;
	int password, choice, salary, finance_choice, add_finance, sub_finance, total, tax, amount_tax;
	int sec_choice;
	string note;
	string journal;
	string notes, feeling;
	char conversation;

	// Print a welcome message
	cout << "<-------------------------------------------------------->\n";
	cout << "\nWhat's your name?" << endl;
	cin >> user;

	cout << "\n<-------------------------------------------------------->\n";

	cout << "\n\tWelcome to Your Personal Assistant" << endl;

pass:
	cout << "Please Enter Your Password:" << endl;
	cin >> password;
	if (password == 123)
	{
	rep:
		cout << "What do you want to do? Press 1-6:" << endl;
		cout << " 1. Finance \n 2. Notes/Journal/Todos \n 3. Conversation \n 4. Calculator \n 5. Meeting Reminder \n 6. Weather" << endl;
		cin >> choice;

		if (choice == 1)
		{
			cout << "You choose Finance" << endl;
			cout << "What is your Salary?\n";
			cin >> salary;
			cout << "Do You want to: \n 1.Add Income + \n 2. Remove Expense - \n 3.Zakat \n 4 Taxes" << endl;
			cin >> finance_choice;
			if (finance_choice == 1)
			{
				cout << "How much more money you got this month?\n";
				cin >> add_finance;
				total = salary + add_finance;
				cout << "Your Total for this month is " << total << " Wohoo!\n"
					 << endl;

				goto rep;
			}
			else if (finance_choice == 2)
			{
				cout << "How much more money you lost this month?\n";
				cin >> sub_finance;
				total = salary - sub_finance;
				cout << "Your Total for this month is " << total << " :(\n";
				goto rep;
			}
			else if (finance_choice == 3)
			{
				cout << "\n\nAmount of zakat you have to give from your salary is: " << 2.5 / 100 * salary << "\n\n"
					 << endl;
				goto rep;
			}
			else if (finance_choice == 4)
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
					cout << "You have to give " << amount_tax << " in taxes." << endl
						 << endl;
					goto rep;
				}
			}
		}
		else if (choice == 2)
		{
			cout << "You Chose Notes/Journal Press 1-2" << endl;
			cout << "1.Notes \n2.Journal \n3.See Notes" << endl;
			cin >> sec_choice;
			if (sec_choice == 1)
			{
				cout << "Enter Your Note below: \n";
				cin >> note;
				goto rep;
			}
			else if (sec_choice == 2)
			{
				cout << "Enter your personal journal below: \n"
					 << endl;
				cin >> journal;
				goto rep;
			}
			else if (sec_choice == 3)
			{
				cout << "See your notes:" << notes << endl;
				notes = "Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, ";
				cout << notes << "\n"
					 << endl;
				cout << journal << "\n"
					 << endl;
				goto rep;
			}
			else
			{
				cout << "Invalid choice!";
			}
			goto rep;
		}
		else if (choice == 3)
		{
			cout << "Welcome " << user << endl;
			cout << "I am your assitant. Please let me know your thoughts." << endl;
			cout << "Please note that there are some limitaions according to this conversation." << endl;
			cout << "a. I will tell you about myself. b. I can convince you if you're emotions are down. " << endl;
			cin >> conversation;
			if (conversation == 'a')
			{
				cout << "Who am I?" << endl;
				cout << "I'm a language model here to assist you." << endl;
			}
			else if (conversation == 'b')
			{
				cout << "How are you feeling " << user << "?\n"
					 << "Type (sad/angry/happy) for further talk. ";
				cin >> feeling;
				if (feeling == "sad")
				{
					cout << "\nI'm sorry to hear that you're feeling sad. It's important to take care of your mental health, and I'm here to help in any way I can.\n\n";
					goto rep;
				}
				else if (feeling == "angry")
				{
					cout << "\nI'm sorry to hear that you're feeling angry. It's normal to experience a range of emotions, including anger, but it's important to manage our emotions in a healthy way.\n\n";
					goto rep;
				}
				else if (feeling == "happy")
				{
					string whyHappy, response, yourResponse;
					cout << "That's great to hear! What's making you feel happy today?" << endl;
					cin >> whyHappy;
					cout << "That's a great accomplishment! Would you like to hear my thoughts?" << endl;
					cin >> response;
					cout << "Feeling happy has many benefits, including better physical and mental health, improved relationships, increased productivity, and enjoyment of life." << endl;
					cout << "Do you think feeling happy is good?" << endl;
					cin >> yourResponse;
					cout << "Great!" << endl;
				}
				else
					cout << "Sorry this word doesn't exist in my program." << endl;
				goto rep;
			}
		}
		else if (choice == 4)
		{
			cout << "You've selected a simple calculator for two numbers." << endl;
			float num1, num2;
			float result;
			char op;
			string yes;
		cal:
			cout << "Enter two numbers: ";
			cin >> num1 >> num2;
			cout << "Choose one of these operators to perform calculations(+,-,*,/,%): " << endl;
			cin >> op;
			switch (op)
			{
			case '+':
				cout << "You have selected addition." << endl;
				cout << "The sum is: " << num1 + num2 << endl;
				break;

			case '-':
				cout << "You have selected subtraction." << endl;
				cout << "The difference is: " << num1 - num2 << endl;
				break;

			case '*':
				cout << "You have selected multiplication." << endl;
				cout << "The product is: " << num1 * num2 << endl;
				break;

			case '/':
				cout << "You have selected division." << endl;
				cout << "The quotient is: " << num1 / num2 << endl;
				break;
			default:
				cout << "Invalid operator!";
			}
			cout << endl;
			cout << "Do you want to continue? Type(yes) if you want to: ";
			cin >> yes;
			cout << endl;
			if (yes == "yes")
			{
				goto cal;
			}
			else
				goto rep;
		}

		else if (choice == 5)
		{
		meetingReminder:
			string meetingWeekDay;
			int meetingHour;
			cout << "\n\n=> Do you forget or miss you meeting on time?" << endl;
			cout << "Don't Worry! I am here to remind you. \n"
				 << endl;
			cout << "Just enter your meeting week day and hour below:\n"
				 << endl;
			cout << "Week Day: ";
			cin >> meetingWeekDay;
			cout << "Week hour: ";
			cin >> meetingHour; // write hours in 24 hours format
			// meeting on weekend
			if (meetingWeekDay == "sunday" || meetingWeekDay == "saturday")
			{

				cout << "\nYou don't have a meeting today, rest!\n\n"
					 << endl;
			}
			// meeting on week day
			else if (meetingWeekDay == "monday" || meetingWeekDay == "tuesday" || meetingWeekDay == "wednesday" || meetingWeekDay == "thursday")
			{
				if (meetingHour >= 9 && meetingHour < 16)
				{
					cout << "YOU HAVE A MEETING TODAY!" << endl;
				}
				else
				{
					cout << "\nNo meeting. \n\n"
						 << endl;
				}
			}
			else if (meetingWeekDay == "friday")
			{
				if (meetingHour >= 9 && meetingHour < 13)
				{
					cout << "\nYOU HAVE A MEETING TODAY!\n\n"
						 << endl;
				}
				else
				{
					cout << "\nNo meeting. \n\n"
						 << endl;
				}
			}
			else
			{
				cout << "\nSir/Ma'am " << user << " Invalid input, please try again." << endl;
				cout << "Check the spellings or the data you have entered." << endl;
				cout << endl;
				goto meetingReminder;
			}
			goto rep;
		}

		else if (choice == 6)
		{
			int temperature;
			cout << "\n\nWant to know what's the weather today? \n" << endl;
			cout << "Just type in the temperature: \n";
			cin >> temperature;
			if (temperature >= 30)
			{
				cout << "\nIt is going to be hot today!\n" << endl;
				goto rep;
			}
			else if (temperature >= 20 && temperature <= 29)
			{
				cout << "\nIt is going to be warm today! Enjoy.\n" << endl;
				goto rep;
			}
			else if (temperature >= 10 && temperature <= 18)
			{
				cout << "\nIt is going to be cold today! Stay warm.\n" << endl;
				goto rep;
			}
			else if (temperature < 10)
			{
				cout << "\nIt is going to be freezing. Chance of snowfall.\n" << endl;
				goto rep;
			}
			else
			{
				cout << "\nPlease enter the correct temperature.\n" << endl;
				goto rep;
			}
		}
	}
	else
	{
		cout << "please Try Again\n";
		goto pass;
	}

	return 0;
}
