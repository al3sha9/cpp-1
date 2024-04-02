#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Supermarket
{
private:
    queue<string> checkoutQueue;

public:
    void addCustomer(const string &customerName)
    {
        checkoutQueue.push(customerName);
        cout << "Customer " << customerName << " joined the queue." << endl;
    }

    void processCheckout()
    {
        if (!checkoutQueue.empty())
        {
            string nextCustomer = checkoutQueue.front();
            checkoutQueue.pop();
            cout << "Checkout for customer " << nextCustomer << " completed." << endl;
        }
        else
        {
            cout << "No customers in the queue." << endl;
        }
    }

    void displayQueue()
    {
        cout << "Current Queue: ";
        queue<string> tempQueue = checkoutQueue;
        while (!tempQueue.empty())
        {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
};

int main()
{
    Supermarket supermarket;

    // Adding customers to the queue
    supermarket.addCustomer("Alice");
    supermarket.addCustomer("Bob");
    supermarket.addCustomer("Charlie");

    // Displaying the current queue
    supermarket.displayQueue();

    // Processing checkout
    supermarket.processCheckout();

    // Displaying the updated queue
    supermarket.displayQueue();

    return 0;
}
