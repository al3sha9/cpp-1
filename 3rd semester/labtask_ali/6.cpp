#include <iostream>

using namespace std;

const int months = 12;

class SalesTracker {
private:
    int monthlySales[months];

public:
    SalesTracker() {
        for (int i = 0; i < months; ++i) {
            monthlySales[i] = 0;
        }
    }

    void inputSalesData() {
        cout << "Enter monthly sales data for each month:\n";
        for (int i = 0; i < months; ++i) {
            cout << "Month " << i + 1 << ": ";
            cin >> monthlySales[i];
        }
    }

    int calculateTotalSales() {
        int totalSales = 0;
        for (int i = 0; i < months; ++i) {
            totalSales += monthlySales[i];
        }
        return totalSales;
    }

    double calculateAverageMonthlySales() {
        return double(calculateTotalSales()) / months;
    }
};

int main() {
    SalesTracker object;

    object.inputSalesData();

    int totalSales = object.calculateTotalSales();
    double averageMonthlySales = object.calculateAverageMonthlySales();

    cout << "Total sales: " << totalSales << endl;
    cout << "Average monthly sales: " << averageMonthlySales << endl;

    return 0;
}
