//CPP program illustrating class declaraton, definition and accessing class members
#include<iostream>
using namespace std;
class student{
    int rollno, age;
    string name, branch, year;
    public:
        student();
        void read();
        void show();
};
student::student(){
    rollno = 0;
    age = 0;
    name = " ";
    branch = " ";
    year = " ";
}
void student::read(){
    cout<<"Enter roll Number : ";
    cin>>rollno;
    cout<<"Enter the name : ";
    cin>>name;
    cout<<"Enter age : ";
    cin>>age;
    cout<<"Enter year : ";
    cin>>year;
    cout<<"Enter branch : ";
    cin>>branch;
}
void student::show(){
    cout<<"Roll No : "<<rollno<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Age : "<<age<<endl;
    cout<<"Year : "<<year<<endl;
    cout<<"Branch : "<<branch<<endl;
}
int main(){
    int n;
    cout<<"Enter number of students : ";
    cin>>n;
    student A[n];
    for(int i = 0; i < n; i++){
        A[i].read();
        cout<<"____________________________________"<<endl;
    }
    cout<<"You entered :"<<endl;
    cout<<"____________________________________"<<endl;
    for(int i = 0; i < n; i++){
        A[i].show();
        cout<<"____________________________________"<<endl;
    }
    return 0;
};