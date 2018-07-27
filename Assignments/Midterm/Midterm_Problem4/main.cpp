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
void input999(int &,const int);
void input1(int &,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    
    
    //Exit
    return 0;
}


void input999(int &enter, const int max){
    int decrypt;//encrypts the data
    cout<<"Enter a 4 Digit Integer: ";
    cin>>enter;
    while(enter>9999||enter<1000){
        cout<<"The number must be 4 Digits long, try again: ";
        cin>>enter;
    }
    int n1=(enter/1000+3)%8;
    int n2=(enter%1000/100+3) %8;
    int n3=(enter%1000%100/10+3)%8;
    int n4=(enter%1000%100%10+3)%8;
    decrypt=(n3*1000)+(n4*100)+(n1*10)+(n2);
    cout << "Decrypted Number: " << decrypt;
    
}