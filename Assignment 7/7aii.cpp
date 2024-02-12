#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
class xyz{
    private : 
        float result;
    public:
        xyz(){
            result = 0;       
        }
        //rectangle
        void area(float, float);
        //circle
        void area(float);
        //triangle
        void area(float, float, float);
};

void xyz::area(float a, float b){
    result = a * b;
    cout<<"Area of Rectangle is : "<<result<<" sq. unit"<<endl;
}
void xyz::area(float a, float b, float c){
    float p = (a+b+c)/2;
    result = sqrt(p * (p - a) * (p - b) * (p - c));
    cout<<"Area of Triangle is : "<<result<<" sq. unit"<<endl;
}
void xyz::area(float a){
    result = 3.14 * a * a;
    cout<<"Area of Circle is : "<<result<<" sq. unit"<<endl;
}
int main(){
    int choice;
    float l,b,h;
    xyz x;
    while(1){
        cout<<"Calculate area of : "<<endl<<"1. Rectangle"<<endl<<"2. Triangle"<<endl<<"3. Circle"<<endl<<"4. Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter length : ";
            cin>>l;
            cout<<"Enter Breadth : ";
            cin>>b;
            x.area(l , b);
            break;
        case 2:
            cout<<"Enter side 1 : ";
            cin>>l;
            cout<<"Enter side 2 : ";
            cin>>b;
            cout<<"Enter side 3 : ";
            cin>>h;
            x.area(l , b, h);
            break;
            
        case 3:
            cout<<"Enter Radius : ";
            cin>>l;
            x.area(l);
            break;
            
        case 4:
            exit(0);
            break;
        default:
            cout<<"Invalid choice !!";
            break;
        }
    }
    return 0;
}
