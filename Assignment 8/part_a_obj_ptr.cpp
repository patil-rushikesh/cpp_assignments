// Write a C++ Program to Access Members of a STUDENT Class Using Pointer to Object Members.

#include <iostream>
using namespace std;
class student
{
    int roll;
    string name;
    string gender;
    int choice;

public:
    void add_data()
    {
        cout << "Enter Name : ";
        cin >> name;
        cout << "Enter Gender : ";
        cin >> gender;
        cout << "Roll No. : ";
        cin >> roll;
    }
    void check_data()
    {
        cout << "Name : " << name << endl;
        cout << "Roll No. : " << roll << endl;
        cout << "Gender : " << gender<<endl;
    }
    void update()
    {
        cout << "what to update?" << endl;
        cout << "1. Name" << endl
             << "2. Roll No." << endl
             << "3. Gender" << endl;
        cout << "Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Name : ";
            cin >> name;
            break;
        case 2:
            cout << "Roll No. : ";
            cin >> roll;
            break;
        case 3:
            cout << "Enter Gender : ";
            cin >> gender;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
};
int main()
{
    student *p;
    student x;
    p = &x;
    int ch;
    while (1)
    {
        cout << "1. Add Data\n2. Check Data again\n3. Correction in data\n4. Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            p->add_data();
            break;
        case 2:
            p->check_data();
            break;
        case 3:
            p->update();
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "Invalid Choice Selected. Try again";
            break;
        }
    }
}