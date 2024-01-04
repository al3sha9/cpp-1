#include <iostream>
#include <string>

using namespace std;

template <typename T>
void genericSort(T *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int intArray[] = {5, 2, 8, 1, 9};
    float floatArray[] = {4.5, 3.1, 1.7, 9.2, 2.4};
    string stringArray[] = {"apple", "banana", "cherry", "date"};

    int intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    int floatArraySize = sizeof(floatArray) / sizeof(floatArray[0]);
    int stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);

    genericSort(intArray, intArraySize);
    genericSort(floatArray, floatArraySize);
    genericSort(stringArray, stringArraySize);

    cout << "Sorted integer array: ";
    for (int i = 0; i < intArraySize; i++)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;

    cout << "Sorted float array: ";
    for (int i = 0; i < floatArraySize; i++)
    {
        cout << floatArray[i] << " ";
    }
    cout << endl;

    cout << "Sorted string array: ";
    for (int i = 0; i < stringArraySize; i++)
    {
        cout << stringArray[i] << " ";
    }
    cout << endl;

    return 0;
}
