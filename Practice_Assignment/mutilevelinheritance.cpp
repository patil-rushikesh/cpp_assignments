//Rushikesh Patil
//Division L
//Batch 3 
//123B1B222

#include <iostream>
using namespace std;

class Triangle
{
public:
    void printType()
    {
        cout << "I am a triangle\n";
    }
};

class Isosceles : public Triangle
{
public:
    void printType()
    {
        cout << "I am an isosceles triangle\n";
    }
};

class Equilateral : public Isosceles
{
public:
    void printType()
    {
        cout << "I am an equilateral triangle\n";
    }
};

int main()
{
    Equilateral eqTri;
    eqTri.printType();
    eqTri.Isosceles::printType();
    eqTri.Triangle::printType();

    return 0;
}
