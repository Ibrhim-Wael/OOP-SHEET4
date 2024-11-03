#include <iostream>
#include <string>
using namespace std;

class ElectricityBill {
private:
    string customerName;
    int customerNumber;
    int electricityUnits;

public:
    ElectricityBill() : customerName(" "), customerNumber(0), electricityUnits(0) {}

    ElectricityBill(string name, int number, int units) : customerName(name), customerNumber(number), electricityUnits(units) {}

    ~ElectricityBill() {
        cout << "ElectricityBill object for " << customerName << " is destroyed." << endl;
    }

    void insert() {
        cout << "Enter customer name (single word): ";
        cin >> customerName;  
        cout << "Enter customer number: ";
        cin >> customerNumber;
        cout << "Enter electricity units consumed: ";
        cin >> electricityUnits;
    }

    float calculateBill() const {
        float billAmount = 0.0;
        if (electricityUnits <= 100) {
            billAmount = electricityUnits * 1.20;
        } else if (electricityUnits <= 200) {
            billAmount = (100 * 1.20) + ((electricityUnits - 100) * 2.00);
        } else {
            billAmount = (100 * 1.20) + (100 * 2.00) + ((electricityUnits - 200) * 3.00);
        }
        return billAmount;
    }

    void display() const {
        cout << "Customer Name: " << customerName << endl;
        cout << "Customer Number: " << customerNumber << endl;
        cout << "Electricity Units Consumed: " << electricityUnits << endl;
        cout << "Total Bill Amount: " << calculateBill() << " pounds" << endl;
    }
};

int main() {
    ElectricityBill customer1;
    ElectricityBill customer2("Osama", 12345, 150);
    ElectricityBill customer3("Mai", 67890, 250);

    cout << "Enter details for customer 1:" << endl;
    customer1.insert();

    cout << "\nCustomer 1 Details:" << endl;
    customer1.display();
    cout << "\nCustomer 2 Details:" << endl;
    customer2.display();
    cout << "\nCustomer 3 Details:" << endl;
    customer3.display();

    return 0;
}
