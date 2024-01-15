//array program in cpp

#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    int arr[5];
    //Accepting values from user in array
    cout<<"Enter the array"<<endl;
    for(int i=0; i<5; i++){
        cin>>arr[i];
    }
    //printing of array
    cout<<"You entered : ";
    for(int i=0; i<5; i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
    //to check whether number is present or not

    cout<<"enter number to find : ";
    int temp;
    cin>>temp;

    for(int i = 0 ; i<5; i++){
        if(temp == arr[i]){
            printf("Number found!");
            exit(0);
        }
    }
    printf("Number not found!");
    return 0;
}
