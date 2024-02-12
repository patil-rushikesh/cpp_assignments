#include <iostream>
using namespace std;

class DtoB {
private:
    int decimal;
public:
    DtoB(int deci) {
        decimal = deci; 
    }
    friend void Binary(DtoB& obj); 
};

void Binary(DtoB& obj) {
    int bin[32];
    int i = 0;
    int tempDecimal = obj.decimal;
    while (tempDecimal > 0) {
        bin[i] = tempDecimal % 2;
        tempDecimal = tempDecimal / 2;
        i++;
    }
    cout << "Binary number is : ";
    if (i == 0) {
        cout << "0"; 
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << bin[j];
    }
    cout << endl;
}

int main() {
    int decimalInput;
    cout << "Enter a decimal number: ";
    cin >> decimalInput;
    DtoB obj(decimalInput);
    Binary(obj);
    return 0;
}
