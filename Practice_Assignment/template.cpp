#include <iostream>

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
    std::cout << "Total marks of student 1 (integer marks): " << student1.calculateTotal() << std::endl;

    StudentMarks<float> student2(88.5, 91.2);
    std::cout << "Total marks of student 2 (floating point marks): " << student2.calculateTotal() << std::endl;

    return 0;
}
