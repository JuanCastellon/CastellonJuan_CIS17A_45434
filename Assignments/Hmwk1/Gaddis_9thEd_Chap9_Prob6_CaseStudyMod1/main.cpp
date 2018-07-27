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
void inpDona1(int *,int);
void bubSor1(int *,int);
void shoArry1(const int *,int);
void shArPtr1(int *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int numDona;
    int *dona=nullptr;
    cout<<"This program organizes the donations inputted by the user in "
            "ascending order."<<endl;
    cout<<"Input number of donations to be inputted."<<endl;
    cin>>numDona;
    dona=new int[numDona];
    
    //Input donation values
    inpDona1(dona,numDona);
    
    // An array of pointers to int.
    int *arrPtr=nullptr;
    arrPtr=new int[numDona];
    
    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count <numDona; count++){
        *(arrPtr+count) = *(dona+count); 
    }
    
    
    //Sort the elements of the array of pointers
    bubSor1(arrPtr,numDona);
    
    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in ascending order are: "<<endl;
    shArPtr1(arrPtr,numDona); 
    
    
    // Display the donations in their original order.
    cout << "The donations, in their original order are: "<<endl;
    shoArry1(dona,numDona); 
    
    delete [] dona;
    delete [] arrPtr;
    dona=arrPtr=nullptr;
    
    //Exit
    return 0;
}
void inpDona1(int *a,int size){
    for(int count=0;count<size;count++){
        cout<<"Input Donation #"<<count+1<<endl;
        cin>>*(a+count);
    }
}
void bubSor1(int *a,int size){
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
void shoArry1(const int *a,int size){
    for (int count=0;count<size; count++){
        cout << *(a+count) << " ";
        cout << endl; 
    }
}
void shArPtr1(int *a,int size){
    for (int count=0;count<size;count++){
        cout<<*(a+count) << " ";
        cout<<endl;
    }
}
