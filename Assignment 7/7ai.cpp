#include <iostream>
using namespace std;

class complex
{
    float real, imag;

public:
    complex(float x, float y)
    {
        real = x;
        imag = y;
    }

    complex operator+(complex c);

    complex operator-(complex c);

    complex operator*(complex c);

    complex operator/(complex c);

    void print();
};
complex complex::operator+(complex c)
{
    complex result(0,0);
    result.real = real + c.real;
    result.imag = imag + c.imag;
    return result;
}
complex complex::operator-(complex c)
{
    complex result(0,0);
    result.real = real - c.real;
    result.imag = imag - c.imag;
    return result;
}
complex complex::operator*(complex c)
{
    complex result(0,0);
    result.real = (real * c.real) - (imag * c.imag);
    result.imag = (real * c.imag) + (c.real * imag);
    return result;
}
complex complex::operator/(complex c)
{
    complex result(0,0);
    result.real = (real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag);
    result.imag = (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag);
    return result;
}
void complex::print(){
    cout<<real<<" + "<<imag<<"i"<<endl;
}

int main()
{
    complex a(10, 12);
    complex b(4, 5);
    complex c(0,0);
    c =a + b;
    c.print();
    c =a - b;
    c.print();
    c =a * b;
    c.print();
    c =a / b;
    c.print();
    return 0;
}
