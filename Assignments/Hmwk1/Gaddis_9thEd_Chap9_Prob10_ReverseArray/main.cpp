/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
void reverse(int *,int *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int *array=nullptr;
    int *newAry=nullptr;
    int size;
    
    cout<<"This array will take an array, reverse the order, and return a "
            "pointer."<<endl;
    cout<<"Input the size of the array."<<endl;
    cin>>size;
    
    
    //Initialize Variables
    array=new int[size];
    newAry=new int[size];
    for(int i=0;i<size;i++){
        cout<<"Input Element #"<<i+1<<" of the Array"<<endl;
        cin>>*(array+i);
    }
    
    //Process Input/Output
    reverse(array,newAry,size);
    
    
    //Display Results
    cout<<"Reversed Array:"<<endl;
    for(int i=0;i<size;i++){
        cout<<*(newAry+i)<<endl;
    }
    
    //Exit
    return 0;
}
void reverse(int *a,int *n,int size){
    for (int i=0;i<size;i++){
        *(n+i) = *(a+i); 
    }
    
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            int temp=*(n+i);
            *(n+i)=*(n+j);
            *(n+j)=temp;
        }
            
    }
}
