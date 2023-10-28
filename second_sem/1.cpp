#include <iostream>

class MyClass {
public:
    // Static variable shared by all objects of the class
    static int sharedVariable;

    MyClass() {
        // Every time an object is created, increment the shared variable
        sharedVariable++;
    }
};

// Initialize the static variable
int MyClass::sharedVariable = 0;

int main() {
    MyClass obj1;
    MyClass obj2;

    // Both objects have access to the same static variable
    std::cout << "obj1 sharedVariable: " << obj1.sharedVariable << std::endl;
    std::cout << "obj2 sharedVariable: " << obj2.sharedVariable << std::endl;

    // You can also access it using the class name
    std::cout << "Using class name: " << MyClass::sharedVariable << std::endl;

    return 0;
}


