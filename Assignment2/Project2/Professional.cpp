#include <iostream>
#include "Employee.h"
using namespace std;

// This function calculates the money that the professional employee gets after x months worked
void Employee::calcMoney(double monthsWorked) {
    _money += monthsWorked * 12000;
}

// This function calculates the amount of vacation days acrewed by the employee with x months worked
void Employee::calcVacDays(double monthsWorked) {
    _vacationDays += monthsWorked * 3;
}

// This function calculates the amount of money the employee pays toward their health care with x months worked
void Employee::calcHealthCont(double monthsWorked) {
    _healthCont += monthsWorked * 12000 * 0.1;
}

int main() {
    Employee p;           // Creates a new employee
    double p1;            // Parameter to store the number of months worked as input by the user
    double monthsWorked;  // Stores the total number of months worked over the employee's lifetime

    while (p1 != 0) {  // Will execute the program as long as the amount of months worked is not 0
        // Prompts the user and takes the input
        cout << "To exit the program, enter 0 for the amount of months worked" << endl;
        cout << "For the professional employee, enter the amount of months worked. (Integer or double): ";
        cin >> p1;

        // Makes sure the amount of months worked is greater than 0
        if (p1 < 0) {
            cout << "\n\nAmount of months worked must be greater than 0\n\n";
        } else {
            monthsWorked += p1;

            // Uses the professional employee functions to calculate the money, vacation days and health care contribution
            p.calcMoney(p1);
            p.calcVacDays(p1);
            p.calcHealthCont(p1);

            // Displays the employee's data to the user
            cout << "\nTotal Months Worked: " << monthsWorked << endl;
            cout << "Current money: $" << p.getMoney() << endl;
            cout << "Current Vacation Days: " << p.getVacationDays() << endl;
            cout << "Current Healthcare Cont.: $" << p.getHealthCont() << endl << endl;
        }
    }
    return 0;
}