#include <iostream>
using namespace std;

class Test {
private:
    float m1, m2;

public:
    Test() : m1(0), m2(0) {
        cout << "Constructor of class Test is called\n";
    }
    ~Test() {
        cout << "Destructor of class Test is called\n";
    }
    void getData() {
        cout << "Enter marks of subject 1 : ";
        cin >> m1;
        cout << "Enter marks of subject 2 : ";
        cin >> m2;
    }
    void showData() const {
        cout << "Marks of sub 1: " << m1 << "\nMarks of sub 2: " << m2 << endl;
    }
    float getM1() const { return m1; }
    float getM2() const { return m2; }
};

class SPA {
private:
    float SPA_m1, SPA_m2;

public:
    SPA() : SPA_m1(0), SPA_m2(0) {
        cout << "Constructor of class SPA is called\n";
    }
    ~SPA() {
        cout << "Destructor of class SPA is called\n";
    }
    void read() {
        cout << "Enter marks of SPA subject 1: ";
        cin >> SPA_m1;
        cout << "Enter marks of SPA subject 2: ";
        cin >> SPA_m2;
    }
    void show() const {
        cout << "Marks of SPA sub 1: " << SPA_m1 << "\nMarks of SPA sub 2: " << SPA_m2 << endl;
    }
    float getSPA_M1() const { return SPA_m1; }
    float getSPA_M2() const { return SPA_m2; }
};

class Result : public Test, public SPA {
private:
    float final_result;
    char final_grade;

public:
    Result() : final_grade('x'), final_result(0) {
        cout << "Constructor of class Result is called\n";
    }
    ~Result() {
        cout << "Destructor of class Result is called\n";
    }
    void calculate() {
        final_result = (getM1() + getM2() + getSPA_M1() + getSPA_M2())/4;
        if (final_result > 90) {
            final_grade = 'O';
        } else if (final_result >= 80) {
            final_grade = 'A';
        } else if (final_result >= 60) {
            final_grade = 'B';
        } else if (final_result >= 50) {
            final_grade = 'C';
        } else if (final_result >= 35) {
            final_grade = 'D';
        } else {
            final_grade = 'F';
        }
        cout << "Final marks: " << final_result << endl
             << "Final Grade: " << final_grade << endl;
    }
};

int main() {
    Result R;
    while (true) {
        cout << "Choose from the given options:\n"
             << "1. Enter details of test\n"
             << "2. Enter details of SPA\n"
             << "3. Show Final Result\n"
             << "4. Exit\n"
             << "\tYour Option: ";
        int n;
        cin >> n;
        switch (n) {
            case 1:
                R.getData();
                break;
            case 2:
                R.read();
                break;
            case 3:
                R.calculate();
                break;
            case 4:
                cout << "Exiting the program.\n";
                return 0; 
            default:
                cout << "Invalid option, choose again\n";
                break;
        }
    }

}
