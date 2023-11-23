#include<iostream>
#include<string>
using namespace std;

const int MAX_BOOKS = 100;

struct library
{
    int accessionNumber;
    string name;
    string bookTitle;
    bool flag;
};

int count = 0;
library Book[MAX_BOOKS];

void addBook(){
    cout<<"Add a book!"<<endl;
    cout<<"Enter the name: ";
    cin>>Book[count].name;
    cout<<"Enter the accession number: ";
    cin>>Book[count].accessionNumber;
    cout<<"Enter the titile: ";
    getline(cin, Book[count].bookTitle);
    count++;
}
void displayBooks(){
    cout<<endl<<"Details of the books: "<<endl;
    for(int i = 0; i<count; i++){
        cout<<"Name "<<Book[count].name<<endl;
        cout<<"Title "<<Book[count].bookTitle<<endl;
        cout<<"Accession Number "<<Book[count].accessionNumber<<endl;
    }
}
void displayByTitle(){
    string name;
    int cnt;
    cout<<"Enter the name of the book: ";
    cin.ignore();
    getline(cin, name);

    cout<<"Book by title: "<<name<<":"<<endl;
    for (int i; i<count;i++){
        if(name == Book[i].bookTitle){
            cnt++;
            cout<<"Accession Number: "<<Book[i].accessionNumber<<endl;
            cout<<"Title: "<<Book[i].bookTitle<<endl;
            cout<<"Name: "<<Book[i].name<<endl;
        }
    }
    if (cnt == 0){
        cout<<"No BooK Found!"<<endl;
    }

}
void numOfBooks(){
    cout<<"Number of books: "<<count<<endl;
}
// void issueBook(int issue){
//     cout<<"Enter the book to issue: "<<endl;
//     cin>>issue;
//     for(int i = 0; i<count; i++){
//         if(Book[i] == count){
//             cout<<"You issued this book now!";
//         }
//     }
// }

int main(){
    int choice;
       while (true)
       {
         cout<<"1. Add Book"<<endl;
        cout<<"2. Display Books"<<endl;
        cout<<"3. Display by title"<<endl;
        cout<<"4. Number of Books"<<endl;
        cout<<"5. Book issue?"<<endl;
        cin>>choice;
 
     switch (choice)
    {
    case 1:
        addBook();
        break;
    case 2:
        displayBooks();
        break;
    case 3:
        displayByTitle();
        break;
    case 4:
        numOfBooks();
        break;
    // case 5:
    //     issueBook();
    //     break;                
    
    default:
        cout<<"invalid choice!"<<endl;
        break;
    
   }
   
       }
       
}