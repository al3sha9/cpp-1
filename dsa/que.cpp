
#include <iostream>
using namespace std;
#define n 20
class queue
{
    int *arr;
    int back;
    int front;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void Enqueue(int x)
    {
        if (back == n - 1)
        {
            cout << "stack over flowed" << endl;
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }
    void Dequeue()
    {
        if (front == -1 || front > back)
        {
            cout << "queue is empty";
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "queue is empty";
        }
        return arr[front];
    }
    bool empty()
    {
        if (front == -1 || front > back)
        {

            return true;
        }
        return false;
    }
};
int main()
{
    queue q;
    q.Enqueue(5);
    q.Enqueue(8);
    q.Enqueue(9);
    cout << q.peek() << endl;
    q.Dequeue();
    cout << q.peek() << endl;
    return 0;
}