// Employee database
#include <iostream>
using namespace std;

class employee
{
    int id;
    string name;
    string position;

public:
    employee();
    employee(int a, string b, string c);
    employee(employee &A);
    void read();
    void show();
};
employee::employee()
{
    id = 0;
    name = " ";
    position = " ";
}
employee::employee(int a, string b, string c)
{
    id = a;
    name = b;
    position = c;
}
employee::employee(employee &X)
{
    id = X.id;
    name = X.name;
    position = X.position;
}
void employee::read()
{
    cout << "Enter ID : ";
    cin >> id;
    cout << "Enter Name : ";
    cin >> name;
    cout << "Enter position : ";
    cin >> position;
}
void employee::show()
{
    cout << "ID : " << id << endl;
    cout << "Name : " << name << endl;
    cout << "Position : " << position << endl;
}
int main()
{
    employee A;
    A.show();

    int a;
    string b, c;
    cout << "Enter ID : ";
    cin >> a;
    cout << "Enter Name : ";
    cin >> b;
    cout << "Enter position : ";
    cin >> c;
    employee B(a, b, c);
    B.show();

    employee C(B);
    C.show();

    return 0;
}
