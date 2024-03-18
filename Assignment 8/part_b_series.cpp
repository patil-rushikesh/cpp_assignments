#include<iostream>
using namespace std;
class fibonacci{
    int n;
    int a,b;
    public:
        fibonacci(){
            a = 0;
            b = 1;
        }
        void input(){
            cout<<"Enter the value : ";
            cin>>n;
        }
        void series(){
            int temp;
            cout<<"Fibonacci Series : "<<a<<","<<b;
            for(int i = 2; i<n ; i++){
                temp = a + b;
                cout<<","<<temp;
                a = b;
                b = temp;
            }
        }
};
int main(){
    fibonacci a;
    a.input();
    a.series();
    return 0;
}