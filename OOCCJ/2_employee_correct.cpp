#include <iostream>
#include <string>

using namespace std;

class Employee {
  public:
    string Ename;
    int EmpID;

    Employee() {}

    Employee(string name, int id) {
      Ename = name;
      EmpID = id;
    }

    virtual void accept() {
      cout << "Enter Employee Name: ";
      cin >> Ename;
      cout << "Enter Employee ID: ";
      cin >> EmpID;
    }

    virtual void display() {
      cout << "Name: " << Ename << endl;
      cout << "ID: " << EmpID << endl;
    }

    virtual double earnings() = 0;
};

class SalariedEmployee: public Employee {
  public:
    double weeklysalary;

    SalariedEmployee() {}

    SalariedEmployee(string name, int id, double salary): Employee(name, id) {
      weeklysalary = salary;
    }

    double earnings() {
      return weeklysalary;
    }
       void accept()
    {
    	Employee::accept();
    	cout<<"Enter Weekly Salary : ";
    	cin>>weeklysalary;
    }
};

class HourlyEmployee: public Employee {
  public:
    double wage;
    double hours;
    double Hourlysalary;

    HourlyEmployee() {}

    HourlyEmployee(string name, int id, double hwage, double hhours): Employee(name, id) {
      wage = hwage;
      hours = hhours;
    }

    double earnings() {
      if (hours <= 40) {
        Hourlysalary = hours * wage;
      } else {
        Hourlysalary = 40 * wage + ((hours - 40) * wage) * 1.5;
      }
      return Hourlysalary;
    }
      void accept()
    {
    	Employee::accept();
    	cout<<"Enter Hourly Wage : ";
    	cin>>wage;
    	cout<<"Enter Hours : ";
    	cin>>hours;
    }
};

class CommissionEmployee: public Employee {
  public:
    double grossSales;
    double commissionRate;
    double Commisionsalary;

    CommissionEmployee() {}

    CommissionEmployee(string name, int id, double gs, double cr): Employee(name, id) {
      grossSales = gs;
      commissionRate = cr;
    }

    double earnings() {
      Commisionsalary = grossSales * commissionRate;
      return Commisionsalary;
    }
         void accept()
    {
    	Employee::accept();
    	cout<<"Enter Gross Sales : ";
    	cin>>grossSales;
    	cout<<"Enter Comission Rate : ";
    	cin>>commissionRate;
    }
};

int main() {
  SalariedEmployee sEmp;
  HourlyEmployee hEmp;
  CommissionEmployee cEmp;

  sEmp.accept();
  hEmp.accept();
  cEmp.accept();

  cout << "Salaried Employee Earnings: $" << sEmp.earnings() << endl;
  cout << "Hourly Employee Earnings: $" << hEmp.earnings() << endl;
  cout << "Commission Employee Earnings: $" << cEmp.earnings() << endl;

  return 0;
}

