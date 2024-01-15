// CPP program to generate prime numbers between 1 to n

#include <iostream>
using namespace std;

class Prime
{
    int n, num, i, count;

public:
    void input()
    {
        cout << "Enter the number  : ";
        cin >> n;
    }
    void primegenerator()
    {
        for (num = n; num >= 2; num--)
        {
            count = 0;

            for (i = 2; i <= num / 2; i++)
            {
                if (num % i == 0)
                {
                    count++;
                    break;
                }
            }

            if (count == 0 && num != 1)
            {
                cout << num << " ";
            }
        }
    }
};
int main()
{
    Prime a;
    a.input();
    a.primegenerator();
    return 0;
}