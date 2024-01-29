#include <iostream>
using namespace std;

class bank
{
    string name;
    int acc_no;
    string type;
    float bal;

public:
    bank();
    bank(string a, int b, string c, float d);
    void display();
    void deposit(float amt);
    void withdraw(float amt);
};

bank::bank()
{
    name = "NULL";
    acc_no = 0;
    type = "NULL";
    bal = 0;
}

bank::bank(string a, int b, string c, float d)
{
    name = a;
    acc_no = b;
    type = c;
    bal = d;
}

void bank::display()
{
    cout << "Name of Customer : " << name << endl
         << "Account Number : " << acc_no << endl
         << "Type of Account : " << type << endl
         << "Balance : " << bal << " Rs." << endl;
}

void bank::deposit(float amt)
{
    cout << "Added amount " << amt << " Rs to the account" << endl;
    bal = bal + amt;
    cout << "Total Account Balance is " << bal << " Rs." << endl;
}

void bank::withdraw(float amt)
{
    if (bal < amt)
    {
        cout << "Insufficient balance. Cannot withdraw." << endl;
    }
    else
    {
        cout << "Withdrawn amount " << amt << " Rs from the account" << endl;
        bal = bal - amt;
        cout << "Total Account Balance is " << bal << " Rs." << endl;
    }
}

int main()
{
    bank customer[100];
    int i = 0;
    int choice;
    string a;
    int b;
    string c;
    float d;

    while (1)
    {
        cout << "1. Register a customer\n2. Display Data of Customer\n3. Deposit money\n4. Withdraw money\n5. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Name : ";
            cin >> a;
            cout << "Enter type of account : ";
            cin >> c;
            cout << "Enter Initial Deposit : ";
            cin >> d;
            customer[i] = bank(a, i, c, d);
            cout<<"Account number assigned to customer is : "<<i<<endl;
            i++;
            break;

        case 2:
            cout << "Enter customer account number to display: ";
            cin >> b;
            if (b >= 0 && b < i)
            {
                customer[b].display();
            }
            else
            {
                cout << "Invalid Account Number." << endl;
            }
            break;

        case 3:
            cout << "Enter customer account number to deposit money: ";
            cin >> b;
            if (b >= 0 && b < i)
            {
                cout << "Enter amount to deposit: ";
                cin >> d;
                customer[b].deposit(d);
            }
            else
            {
                cout << "Invalid Account Number." << endl;
            }
            break;

        case 4:
            cout << "Enter customer Account number to withdraw money: ";
            cin >> b;
            if (b >= 0 && b < i)
            {
                cout << "Enter amount to withdraw: ";
                cin >> d;
                customer[b].withdraw(d);
            }
            else
            {
                cout << "Invalid Account Number." << endl;
            }
            break;

        case 5:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
