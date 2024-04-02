#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    int age;
    double basicSalary;
    double da;
    double hra;
    string department;
    string phNo;

public:
    Employee() {}

    Employee(int emp_id, string emp_name, int emp_age, double emp_basicSalary, double emp_da, double emp_hra, string emp_department, long long int emp_phNo) {
        id = emp_id;
        name = emp_name;
        age = emp_age;
        basicSalary = emp_basicSalary;
        da = emp_da;
        hra = emp_hra;
        department = emp_department;
        phNo = emp_phNo;
    }

    long long calculateSalary() {
        return da + hra + basicSalary;
    }

    void getData() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin>>name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        cout << "Enter DA: ";
        cin >> da;
        cout << "Enter HRA: ";
        cin >> hra;
        cout << "Enter Department: ";
        cin>>department;
        cout << "Enter Phone Number: ";
        cin >> phNo;
        if (phNo.size() > 10) {
            throw ("Phone number must be 10 digits long.");
        }
        if (age < 18) {
            throw ("Employee must be at least 18 years old.");
        }
    }

    void putData() {
        cout << "Employee ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "DA: " << da << endl;
        cout << "HRA: " << hra << endl;
        cout << "Department: " << department << endl;
        cout << "Phone Number: " << phNo << endl;
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};

int main() {
    Employee emp;
    int choice;
    while(1){
        cout << "1. Enter Employee Data" << endl;
        cout << "2. Display Employee Data" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                try {
                    emp.getData();
                } catch(const char* a) {
                    cerr << "Error: " << a << endl;
                }
                break;
            case 2:
                emp.putData();
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } 

    return 0;
}
