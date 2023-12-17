#include<iostream>
#include<string>
#include<fstream>
using namespace std;

fstream file3;
class phoneBook{
    string name;
    int contact_number;

    public:
    phoneBook(){}
    phoneBook(string name, int contact_number){
        this->name = name;
        this->contact_number;
    }

    void add_new_contact(){
        file3.open("file3.txt", ios::out);
        cout<<"File created! Add 3 contacts.."<<endl;
        for(int i = 0; i<3; i++){
        cout<<"Enter your name and contact number: ";
        cin>>name>>contact_number;
        file3<<name<<" "<<contact_number<<endl;
        }
        file3.close();
    }
    
    void search_contact_byname(){
        string nameBySearch;
        bool found = false;

        file3.open("file3.txt", ios::in);
        cout<<"Enter contact name: ";
        cin>>nameBySearch;
        while(file3>>name>>contact_number){
            if(nameBySearch == name){
                found = true;
                cout<<"The contact number for "<<name<<" is "<<contact_number<<endl;
            }
        }
        file3.close();
    }

    void delete_contact(){
        fstream tempFile3;
        string deleteContact;
        bool found = false;

        file3.open("file3.txt", ios::out);
        tempFile3.open("temp.txt", ios::in);

        cout<<"Enter the contact name to delete: ";
        cin>>deleteContact;

        while(file3>>name>>contact_number){
            if(deleteContact == name ){
            found = true;
            cout<<"The contact with name "<<deleteContact<<" is deleted"<<endl;
            continue;
        }

        tempFile3<<name<<" "<<contact_number<<endl;
        }

        file3.close();
        tempFile3.close();

        if(found){
            remove("file3.txt");
            rename("file3.txt","tempFile3");
        }
    }
};
int main(){
    phoneBook object;
    int choose;
    cout<<"1. Add User 2. Search by name 3. Delete Contact "<<endl;
    cin>>choose;

    switch (choose)
    {
    case 1:
        object.add_new_contact();
        break;
    case 2:
        object.search_contact_byname();
        break;    
    case 3:
        object.delete_contact();
        break;
    default:
        cout<<"Invalid Choice!"<<endl;
        break;
    }
}