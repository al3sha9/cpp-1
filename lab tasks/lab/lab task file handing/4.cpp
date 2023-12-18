#include<iostream>
#include<string>
#include<fstream>
using namespace std;

fstream file4;
class ProductDetails{
    string name;
    int quantity, price;

    public:
    ProductDetails(){}
    ProductDetails(string n, int q, int p):name(n), quantity(q), price(p){}

    void add_new_product(){
        file4.open("file4.txt", ios::out);
        if(!file4){
            cout<<"File does not exist!"<<endl;
        }
        else{
            cout<<"Enter the name of the products along with the quantities and price:"<<endl;
            cout<<endl;
            cout<<"Product: ";
            cin>>name;
            file4<<name<<endl;
            cout<<"Quantity: ";
            cin>>quantity;
            file4<<quantity<<endl;
            cout<<"Price ";
            cin>>price;
            file4<<price<<endl;

            cout<<"The products are successfully stored in the file4. Check it out!"<<endl;
        }
        file4.close();
    }
    void update_quantities() {
    char yn;
    cout << "Do you have more quantities available? (y/n)";
    cin >> yn;

    if (yn == 'n') {
        cout << "OK quit!" << endl;
    } else {
        int quantity = 0;

        cout << "Enter the quantity: ";
        cin >> quantity;

        fstream file4("file4.txt", ios::in | ios::out);

        if (!file4) {
            cout << "Error opening file!" << endl;
            return;
        }

        file4 << quantity;

        cout << "Updated successfully!" << endl;
        cout<<quantity<<endl;

        file4.close();
    }
}
    void display_inventory(){
        cout<<"The products: "<<endl;
        file4.open("file4.txt", ios::in);
        file4>>name>>quantity>>price;
        cout<<name<<endl;
        cout<<quantity<<endl;
        cout<<price<<endl;
        file4.close();
    }
};
int main(){
    ProductDetails detailsObject;
    int choice;
    cout<<"1. Add new products. 2. Update 3. Display Inventory (1-3) ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        detailsObject.add_new_product();
        break;
    case 2:
        detailsObject.update_quantities();
        break;    
    case 3:
        detailsObject.display_inventory();
        break;
    default:
        cout<<"INVALID CHOICE!!"<<endl;
        break;
    }
}