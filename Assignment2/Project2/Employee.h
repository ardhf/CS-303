#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class Employee {
   private:
    // Creates private variables that store the money, vacDays and health care cont
    double _money;
    double _vacationDays;
    double _healthCont;

   public:
    // Functions to calculate the money vacDays and health care cont based on the rules of each employee
    // @param is either monthsWorked or hoursWorked
    virtual void calcMoney(double);
    virtual void calcVacDays(double);
    virtual void calcHealthCont(double);

    // Getter functions that return each employee's info
    double getMoney() { return _money; }
    double getVacationDays() { return _vacationDays; }
    double getHealthCont() { return _healthCont; }
};

#endif  // EMPLOYEE_H_