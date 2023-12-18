#include<iostream>
#include<string>
#include<fstream>
using namespace std;

fstream file5;
class StudentGrades{
    public:
    void add_new_grades(){
        int grades[3];
        file5.open("file.txt", ios::out);
        cout<<"Enter grades: "<<endl;
        cin>>grades[3];
        file5<<grades; 
        file5.close();  
    }
    void calculate_average_grades(){

    }
    void display_highest_lowest_grades(){

    }
};
int main(){
    StudentGrades object;
    int choice;
    cout<<"1. Add Grades 2. Calculate Average 3. Display Highest and Lowest Grade";
    cin>>choice;
    switch (choice)
    {
    case 1:
        object.add_new_grades();
        break;
    case 2:
        object.calculate_average_grades();
        break;
    case 3:
        object.display_highest_lowest_grades();
        break;    
    default:
        cout<<"Invalid choice!"<<endl;
        break;
    }
}