#include <iostream>
#include "Employee.h"
using namespace std;

// Calculates the money the nonprofessional employee has made with x hours worked
void Employee::calcMoney(double hoursWorked) {
    _money += (hoursWorked * 40.0);
}

// Calculates the amount of vacation days the nonprofession employee has made with x hours worked
void Employee::calcVacDays(double hoursWorked) {
    _vacationDays += (hoursWorked / 40.0);
}

// Calculates how much the employee must pay in health care contributions with x hours worked
void Employee::calcHealthCont(double hoursWorked) {
    _healthCont += (hoursWorked * 4.0);
}

int main() {
    Employee np;         // Creates a nonprofessional employee
    double p1;           // Parameter to store user input
    double hoursWorked;  // Keeps track of total amount of hours worked.

    while (p1 != 0) {  // Prompts the user as long as the hours worked is not 0
        cout << "To exit the program, enter 0 for the amount of hours worked" << endl;
        cout << "For the nonprofessional employee, enter the amount of hours worked. (Integer or double): ";
        cin >> p1;

        // Makes sure the amount of hours worked is greater than 0
        if (p1 < 0) {
            cout << "\n\nAmount of hours worked must be greater than 0\n\n";
        } else {
            hoursWorked += p1;

            // Calculates the money, vacation days and health care contribution
            np.calcMoney(p1);
            np.calcVacDays(p1);
            np.calcHealthCont(p1);

            // Displays the data to the user
            cout << "\nTotal Hours Worked: " << hoursWorked << endl;
            cout << "Current money: $" << np.getMoney() << endl;
            cout << "Current Vacation Days: " << np.getVacationDays() << endl;
            cout << "Current Healthcare Cont.: $" << np.getHealthCont() << endl << endl;
        }
    }
    return 0;
}