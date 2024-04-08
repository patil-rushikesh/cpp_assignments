#include <iostream>
using namespace std;
template <class T>
class StudentMarks
{
public:
    T mark1;
    T mark2;

    StudentMarks(T m1, T m2)
    {
        this->mark1 = m1;
        this->mark2 = m2;
    }

    T calculateTotal()
    {
        return mark1 + mark2;
    }
};

int main()
{

    StudentMarks<int> student1(85, 75);
    cout << "Total marks of student 1 (integer marks): " << student1.calculateTotal() << endl;

    StudentMarks<float> student2(88.5, 91.2);
    cout << "Total marks of student 2 (floating point marks): " << student2.calculateTotal() << endl;

    return 0;
}
