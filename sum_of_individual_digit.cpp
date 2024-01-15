#include<iostream>
using namespace std;
class sumofdigi{
    int n, sum = 0;
    public:
        void input(){
            cout<<"Enter the value : ";
            cin>>n;
        }
        void sumfinder(){
            while(n != 0){
                sum = sum + (n % 10);
                n = n /10;
            }
        }
        void output(){
            cout<<"Sum of individual digit is : "<<sum;
        }
};
int main(){
    sumofdigi a;
    a.input();
    a.sumfinder();
    a.output();
    return 0;
}