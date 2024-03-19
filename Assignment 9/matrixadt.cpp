#include <iostream>
using namespace std;

struct matrix {
    int a[2][2];
};

class calc {
    matrix m; 

public:
    friend ostream &operator<<(ostream &out, const calc &x) {
        out << "Matrix : " << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                out << x.m.a[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    friend istream &operator>>(istream &in, calc &x) {
        cout << "Enter Matrix : " << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                in >> x.m.a[i][j];
            }
        }
        return in;
    }

    calc& operator=(const calc &x) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    m.a[i][j] = x.m.a[i][j];
                }
            }
        return *this;
    }

    calc operator+(const calc &x){
        calc result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.m.a[i][j] = m.a[i][j] + x.m.a[i][j];
            }
        }
        return result;
    }

    calc operator-(calc &x){
        calc result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.m.a[i][j] = m.a[i][j] - x.m.a[i][j];
            }
        }
        return result;
    }

    calc operator*(const calc &x){
        calc result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.m.a[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result.m.a[i][j] += m.a[i][k] * x.m.a[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    calc a, b, c;
    cout << "Input for matrix a:" << endl;
    cin >> a;
    cout << "Input for matrix b:" << endl;
    cin >> b;
    cout << "Matrix a:" << endl << a;
    cout << "Matrix b:" << endl << b;
    c = a + b;
    cout << "Matrix a + b:" << endl << c;
    c = a - b;
    cout << "Matrix a - b:" << endl << c;
    c = a * b;
    cout << "Matrix a * b:" << endl << c;
}
