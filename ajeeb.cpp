// header files
#include <iostream>

// namespace standards
using namespace std;

// outbound class
class OutBoundException
{
private:
    const char *message;

public:
    OutBoundException(const char *msg) : message(msg) {}

    // message return funtion
    const char *what() const
    {
        return message;
    }
};

// Array class
class SecureArray
{
    // variable declaration
private:
    static const int MAX_SIZE = 10;
    int dataArray[MAX_SIZE];
    int arraySize;

public:
    SecureArray() : arraySize(0) {}

    void insert(int value)
    {
        if (arraySize == MAX_SIZE)
        {
            throw OutBoundException("Array Full!!!");
        }
        dataArray[arraySize++] = value;
    }

    void remove()
    {
        if (arraySize == 0)
        {
            throw OutBoundException("Array empty!!!");
        }
        arraySize--;
    }
};

int main()
{
    SecureArray secureArray;

    try
    {
        secureArray.insert(10);
        secureArray.remove();
        secureArray.remove();
    }
    catch (const OutBoundException &e)
    {
        cout << "Caught: " << e.what() << endl;
    }

    return 0;
}
