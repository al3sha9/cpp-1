#include<iostream>
#include<fstream>
#include<string>
using namespace std;

fstream file;
char x;

class GetDetails{
	public:
    char name[30];
    int rollNumber;

	void add_record(){
		file.open("file.txt", ios::out);
			if (!file){
				cout<<"File does not exist!";
			}

			else {
				cout<<"File created!"<<endl;
                cout<<"Enter your name and roll number: "<<endl;
                cin>>name>>rollNumber;
                cout<<"You name and roll number is stored in the file. check it!"<<endl;
				file<<name<<endl;
                file<<rollNumber<<endl;
			}
			
			file.close();
	}

    void display_record(){
		file.open("file.txt", ios::in);
			if (!file){
				cout<<"File does not exist!";
			}

			else {
                cout<<"Displaying records: ";
                while (1)
                {
                    file>>name>>rollNumber;
                    if(file.eof())
                        break;
                    cout<<endl<<name<<endl<<rollNumber<<endl;
                }
                
			}
			
			file.close();
	}

    void search_record(){
        file.open("file.txt", ios::in);
        if (!file) {
            cout << "File does not exist!";
        }
        else {
            int searchByRollNumber;
            bool found = false;

            cout << "Enter the roll number to search: ";
            cin >> searchByRollNumber;

            while (file >> name >> rollNumber) {
                if (rollNumber == searchByRollNumber) {
                    cout << "Record found: " << endl;
                    cout << "Name: " << name << endl;
                    cout << "Roll Number: " << rollNumber << endl;
                    found = true;
                    break;  
                }
            }

            if (!found) {
                cout << "Record not found!" << endl;
            }
        }
        file.close();
    }	
};
int main(){
    int choose;
	GetDetails object;
    cout<<"Choose one of the following: "<<endl;
	cout<<"1. add record 2. display 3. search by roll number "<<endl;
	cin>>choose;
    switch (choose){
		case 1:
			object.add_record();
			break;
		case 2: 	
			object.display_record();
			break;
		case 3:
			object.search_record();
			break;
		default:
			cout<<"Invalid choice!"<<endl;		
	}
}
		




