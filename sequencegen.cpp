#include<iostream>
using namespace std;
class Seqgen{
    int n;
    int a = 0, b = 1;
    public:
        void input(){
            cout<<"Enter the value : ";
            cin>>n;
        }
        void fibonacci(){
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
    Seqgen a;
    a.input();
    a.fibonacci();
    return 0;
}