#include <iostream>
using namespace std;

class Lib
{
private:
    string author;
    string name;

public:
    Lib(string n, string a)
    {
        author = a;
        name = n;
    };
    string getA()
    {
        return author;
    }
    string getN(){
        return name;
    }
    ~Lib()
    {
        cout << "BYE";
    }
};

class Ebook : public Lib
{
public:
    Ebook(string n, string a) : Lib(n, a) {}
};
class Book : public Lib
{
public:
    Book(string n, string a) : Lib(n, a) {}
};

int main()
{
    Ebook E1("7 effects", "ALI SHAN");
    Book E2("8 effects", "kjashd");

    cout << "EBOOK DETAILS: " << E1.getN() << E1.getA() << endl;
    cout << "Book DETAILS: " << E2.getN() << E2.getA() << endl;
}
