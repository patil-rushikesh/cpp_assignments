// CPP program to generate prime numbers between 1 to n

#include <iostream>
using namespace std;
//int n = 50;
class SorL
{
    int n,small,large,array[50];
public:
    void input()
    {
        cout << "Enter the number  : ";
        cin >> n;
        cout<<"Elements of array : ";
        for(int i = 0; i<n; i++){
            cin>>array[i];
        }
    }
    void smallest(){
        small = array[0];
        for (int i = 0; i < n; i++){
            if(small > array[i]){
                small = array[i];
            }
        }
    }
    void largest(){
        large = array[0];
        for (int i = 0; i < n; i++){
            if(large < array[i]){
                large = array[i];
            }
        }
    }
    void ouput(){
        cout<<"Smallest : "<<small<<endl<<"Largest : "<<large;
    }
};
int main()
{

    SorL a;
    a.input();
    a.smallest();
    a.largest();
    a.ouput();
    return 0;
}
