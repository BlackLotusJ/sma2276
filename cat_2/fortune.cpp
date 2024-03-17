#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string empID;
    string firstName;
    string secondName;
    string surname;
    string gender;
    string dob; // Assuming dob is a string in dd-mm-yyyy format
    double basicSalary;

public:
    // Constructor to capture employee details
    Employee(const string& id, const string& first, const string& second, const string& last,
              const string& gen, const string& dateOfBirth, double salary)
        : empID(id), firstName(first), secondName(second), surname(last), gender(gen), dob(dateOfBirth), basicSalary(salary) {}

    // Function to display employee information
    void showEmployee() const {
        cout << "ID NUMBER\t:" << empID << endl;
        cout << "FIRST NAME\t:"cout<< firstName << endl;
	cout<<"SECOND NAME\t:"<<secondName<<endl;
	cout<<"SURNAME\t:"<<surname<<endl;
        cout << "GENDER\t:" << gender << endl;
        cout << "DATE OF BIRTH: " << dob << endl;
        cout << "BASIC SALARY: Ksh." << fixed << setprecision(2) << basicSalary << endl;
    }
};

// Friend function to calculate pension contribution (assuming 5% of basic salary)
friend double compute_pension(const Employee& emp) {
    return emp.basicSalary * 0.05;
}

int main() {
    string id, firstName, secondName, surname, gender, dob;
    double salary;

    cout << "\tADD EMPLOYEE DETAILS:\n";
    cout << "ENTER ID NUMBER\t:";
    getline(cin, id);
    cout << "ENTER FIRST NAME\t:";
    getline(cin, firstName);
    cout << "ENTER SECOND NAME\t:";
    getline(cin, secondName);
    cout << "ENTER SURNAME\t: ";
    getline(cin, surname);
    cout << "ENTER GENDER <M or F>\t:";
    getline(cin, gender);
    cout << "DATE OF BIRTH <DD-MM-YYYY>:";
    getline(cin, dob);
    cout << "ENTER BASIC SALARY IN KSH: ";
    cin >> salary;

    Employee emp_obj(id, firstName, secondName, surname, gender, dob, salary);

    cout << "\nEMPLOYEE DETAILS:\n";
    emp_obj.showEmployee();

    double pension = compute_pension(emp_obj);
    cout << "\nEstimated Monthly Pension Contribution: Ksh." << fixed << setprecision(2) << pension << endl;

    return (0);
}

