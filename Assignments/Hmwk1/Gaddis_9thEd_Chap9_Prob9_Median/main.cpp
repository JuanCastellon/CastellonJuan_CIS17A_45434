/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip>//round up
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
void bubSor(int *,int);
int finMedi(int *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Formatting
    cout<<showpoint<<setprecision(2)<<showpoint;
    
    //Declare Variables
    int size,median;//Size of the array and the mode
    
    cout<<"This program will the determine the mode of a dynamically allocated"
            " array."<<endl;
    
    cout<<"Enter size of the array"<<endl;
    cin>>size;
    int *array=nullptr;
    array=new int[size];
    
    //Initialize Variables
    for(int i=0;i<size;i++){
        cout<<"Input Value #"<<i+1<<" of the Array."<<endl;
        cin>>*(array+i);
    }
    
    //Process Input/Output
    bubSor(array,size);
    
    median=finMedi(array,size);
    
    //Display Results
    cout<<"Median of the Array = "<<median<<endl;
    
    delete [] array;
    array=nullptr;
    
    //Exit
    return 0;
}
void bubSor(int *a,int size){
    for (int i=0;i<size; i++){
        for (int j=i+1;j<size;j++){
            if (*(a+i)<*(a+j)){
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
}
int finMedi(int *a,int size){
    int even,odd;//variables for choosing the middle value of a variable
    int median;
    even=odd=median=0;
    //Test to see if even or odd
    if(size%2==0){//even
        even=(size/2);
        even+=(size/2)+1;
        median=(even/2);
    }
    else{//odd
        odd=(size-1)/2;
        median=*(a+odd);
    }
    return median;
}
