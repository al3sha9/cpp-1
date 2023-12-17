#include<iostream>
#include<string>
#include<fstream>
using namespace std;
fstream file2;
//allow user to add new employee, update salary, display payroll details
class EmployeeDetails{
    protected:
    string name;
    int ID, salary;

    public:
    EmployeeDetails(){}
    EmployeeDetails(string name, int ID, int salary){
        this->name = name;
        this->ID = ID;
        this->salary = salary;
    } 

    void add_user(){
        file2.open("file2.txt", ios::out);
        if (!file2){
            cout<<"File2 doesn't exist!"<<endl;
        }
        else{
            cout<<"File has been created! You can add 3 users!"<<endl;
            for(int i = 0; i<3; i++){
            cout<<"**Add a new user**"<<endl;
            cout<<"Enter user name, salary, and ID"<<endl;
            cin>>name>>salary>>ID;
            file2<<name<<endl;
            file2<<salary<<endl;
            file2<<ID<<endl;
            cout<<"The record has been added! Check it in file2! "<<endl;
            }
        }
    }
    void update_salary() {
    ifstream inputFile("file2.txt");
    ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile) {
        cerr << "File error!" << endl;
        return;
    }

    int searchID;
    bool found = false;

    cout << "Enter the ID to update salary: ";
    cin >> searchID;

    while (inputFile >> name >> salary >> ID) {
        if (ID == searchID) {
            found = true;
            cout << "Enter the new salary for " << name << ": ";
            cin >> salary;
        }
        tempFile << name << endl << salary << endl << ID << endl;
    }

    inputFile.close();
    tempFile.close();

    if (found) {
        remove("file2.txt");
        rename("temp.txt", "file2.txt");
        cout << "Salary updated successfully!" << endl;
    }
    else {
        remove("temp.txt");
        cout << "Employee with ID " << searchID << " not found!" << endl;
    }
}

    void display_payroll_list(){
        file2.open("file2.txt", ios::in);
        cout<<"**Display the payroll**"<<endl;
        while (1){
            file2>>name>>salary>>ID;
            if(file2.eof())
                break;
            cout<<endl<<name<<endl<<salary<<endl<<ID<<endl;
        }
    }
};
int main(){
    EmployeeDetails object;
    int choose;
    cout<<"1. Add User 2. Update Salary 3. Display Payroll List "<<endl;
    cin>>choose;

    switch (choose)
    {
    case 1:
        object.add_user();
        break;
    case 2:
        object.update_salary();
        break;    
    case 3:
        object.display_payroll_list();
        break;
    default:
        cout<<"Invalid Choice!"<<endl;
        break;
    }
}