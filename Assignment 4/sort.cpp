#include<iostream>
using namespace std;
class workingwitharray{
    int arr[5];
    public:
        void read();
        void sortasc();
        void sortdes();
        void show();
};
void workingwitharray::read(){
    cout<<"Add elements to array : ";
    for(int i = 0; i < 5; i++){
        cin>>arr[i];
    }
}
void workingwitharray::show(){
    cout<<"Array : ";
    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
//sorting
void workingwitharray::sortasc(){
    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){
            if(arr[i] > arr[j]){
                int temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
void workingwitharray::sortdes(){
    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){
            if(arr[i] < arr[j]){
                int temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int main(){
    workingwitharray A;
    A.read();
    cout<<"Before Sorting"<<endl;
    A.show();
    cout<<"Ascending order : ";
    A.sortasc();
    cout<<"After Sorting"<<endl;
    A.show();
    cout<<"Descending order : ";
    A.sortasc();
    cout<<"After Sorting"<<endl;
    A.show();
    return 0;
}