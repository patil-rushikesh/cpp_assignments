#include <iostream>
using namespace std;

double safeDivide(double numerator, double denominator)
{
    if (denominator == 0)
    {
        throw("Math error: Attempted to divide by Zero\n");
    }
    return numerator / denominator;
}

int main()
{
    double num, denom;
    cout << "Enter Numerator : ";
    cin >> num;
    cout << "Enter Denominator : ";
    cin >> denom;
    try
    {
        if (num != (int)num)
        {
            double result = safeDivide(num, denom);
            cout << "The result is: " << result << endl;
        }else{
            throw num;
        }
    }
    catch (const char* a)
    {
        cout << "Exception occurred: " << a;
    }
    catch(double a)
    {
        cout<<"Entered numerator is not double";
    }

    return 0;
}
