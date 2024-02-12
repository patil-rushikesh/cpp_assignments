#include<iostream>
using namespace std;
class student{
    string name;
    int marks[50];
    string sub[50];
    int n,total;
    float avg;
    public:
    void assign();
    void compute();
    void display();
};
void student :: assign(){
    cout<<"Enter name of student : "<<endl;
    cin>>name;
    cout<<"Enter the no of subjects : "<<endl;
    cin>>n;
    marks[n];
    sub[n];
    cout<<"Enter each subject details : "<<endl;
    for(int i=0;i<n;i++){
        cout<<"subject"<<i+1<<"name :";
        cin>>sub[i];
        cout<<"Marks for :"<<sub[i]<<"=";
        cin>>marks[i];
    }
}
void student :: compute(){
    total=0;
    for(int i=0;i<n;i++){
        total=total+marks[i];
    }
    avg=total/n;
}
void student :: display(){
    cout<<"Name of student is : "<<name<<endl;
    cout<<"Total marks obtained : "<<total<<endl;
    cout<<"Average is : "<< avg<<endl;
}
int main(){
    student s;
    s.assign();
    s.compute();
    s.display();
    return 0;
}