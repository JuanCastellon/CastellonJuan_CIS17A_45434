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
void inpDona(int *,int);
void bubSor(int *,int);
void shoArry(const int *,int);
void shArPtr(int *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int NUMDONA;
    int *dona=nullptr;
    cout<<"Input number of donations to be inputted."<<endl;
    cin>>NUMDONA;
    dona=new int[NUMDONA];
    
    //Input donation values
    inpDona(dona,NUMDONA);
    
    // An array of pointers to int.
    int *arrPtr=nullptr;
    arrPtr=new int[NUMDONA];
    
    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count <NUMDONA; count++){
    *(arrPtr+count) = *(dona+count); 
    }
    
    
    //Sort the elements of the array of pointers
    bubSor(arrPtr,NUMDONA);
    
    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in ascending order are: "<<endl;
    shArPtr(arrPtr,NUMDONA); 
    
    
    // Display the donations in their original order.
    cout << "The donations, in their original order are: "<<endl;
    shoArry(dona,NUMDONA); 
    
    
    
    //Exit
    return 0;
}
void inpDona(int *a,int size){
    for(int count=0;count<size;count++){
        cout<<"Input Donation #"<<count+1<<endl;
        cin>>*(a+count);
    }
}
void bubSor(int *a,int size){
    for (int i=0;i<size; i++){
        for (int j=i+1;j<size;j++){
            if (*(a+i)>*(a+j)){
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
}
void shoArry(const int a[],int size){
    for (int count=0;count<size; count++){
        cout << a[count] << " ";
        cout << endl; 
    }
}
void shArPtr(int *a,int size){
    for (int count=0;count<size;count++){
        cout<<*(a+count) << " ";
        cout<<endl;
    }
}
