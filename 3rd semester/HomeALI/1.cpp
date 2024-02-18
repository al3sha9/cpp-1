#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    void setName(string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
};
int main()
{
    Person p1;
    p1.setName("ALI SHAN");
    p1.setAge(21);
    cout <<"MY NAME IS \t"<< p1.getName() << endl;
    cout << "MY AGE IS \t"<<p1.getAge() << endl;
    p1.getName();
    p1.getAge();
    return 0;
}
