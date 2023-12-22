#include <iostream>
#include <stdexcept>
using namespace std;
class OutBoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Out of bounds exception.";
    }
};

class SecureArray {
private:
    static const int maxSize = 5;
    int array[maxSize];
    int size;

public:
    SecureArray() : size(0) {}

    void insert(int value) {
        if (size >= maxSize) {
            throw OutBoundException();
        }
        array[size++] = value;
    }

    void remove() {
        if (size <= 0) {
            throw OutBoundException();
        }
        --size;
    }

    void display() const {
        std::cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        cout << std::endl;
    }
};

int main() {
    try {
        SecureArray secureObject;

        secureObject.insert(42);
        secureObject.display();

        secureObject.remove();
        secureObject.display();

        secureObject.remove(); 
        secureObject.display(); 
    } catch (const OutBoundException& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    return 0;
}
