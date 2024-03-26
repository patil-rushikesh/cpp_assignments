#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    virtual void getData() = 0;
    virtual void showData() = 0; // Marked as const because it doesn't modify the object

    virtual ~Person() {}
};

class Professor : public Person
{
private:
    int publications;
    int cur_id;
    static int id;

public:
    Professor() : cur_id(id++) {}

    void getData()
    {
        cout << "Enter Details of Professor:\n";
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Publications: ";
        cin >> publications;
    }

    void showData()
    {
        cout << "Name: " << name << "\nAge: " << age
             << "\nPublications: " << publications << "\ncur_id: " << cur_id << endl;
    }
};
int Professor::id = 0;

class Student : public Person
{
private:
    int marks[6];
    int cur_id;
    static int id;

public:
    Student() : cur_id(id++) {}

    void getData() override
    {
        cout << "Enter Details of Student:\n";
        cout << "Name: ";
        cin>>name;
        cout << "Age: ";
        cin >> age;
        for (int i = 0; i < 6; i++)
        {
            cout << "Enter marks of sub " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void showData()
    {
        int sum = 0;
        cout << "Name: " << name << "\nAge: " << age << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << "Marks of sub " << i + 1 << ": " << marks[i] << endl;
            sum += marks[i];
        }
        cout << "Total Marks: " << sum << endl;
    }
};
int Student::id = 0;

int main()
{
    Professor P[10];
    Student S[10];
    int p = 0, s = 0;
    while (true)
    {
        cout << "Choose from the given options:\n"
             << "1. Create Student Database\n"
             << "2. Create Professor Database\n"
             << "3. View Student Data\n"
             << "4. View Professor Data\n"
             << "5. Exit\n"
             << "\tYour Option: ";
        int n, id;
        cin >> n;
        switch (n)
        {
        case 1:
            if (s < 10)
            {
                S[s++].getData();
            }
            else
            {
                cout << "Student database full.\n";
            }
            break;
        case 2:
            if (p < 10)
            {
                P[p++].getData();
            }
            else
            {
                cout << "Professor database full.\n";
            }
            break;
        case 3:
            cout << "Enter ID : ";
            cin >> id;
            if (id >= 0 && id < s)
            {
                S[id].showData();
            }
            else
            {
                cout << "Invalid ID.\n";
            }
            break;
        case 4:
            cout << "Enter ID : ";
            cin >> id;
            if (id >= 0 && id < p)
            {
                P[id].showData();
            }
            else
            {
                cout << "Invalid ID.\n";
            }
            break;
        case 5:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid option, choose again.\n";
            break;
        }
    }

    return 0;
}
