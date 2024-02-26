#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *ptr = new int[size];
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        cin >> ptr[i];
    }

    cout << "You entered: ";
    for (int i = 0; i < size; ++i) {
        cout << ptr[i] << " ";
    }
    cout <<endl;

    delete ptr;

    //after delete it prints garbage values

    for (int i = 0; i < size; ++i) {
        cout << ptr[i] << " ";
    }

    return 0;
}
