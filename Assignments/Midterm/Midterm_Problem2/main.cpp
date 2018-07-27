/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <cctype>  //
#include <cstring> 
#include <string>
using namespace std;

//User Libraries Here
struct Pay{
    string name;
    int hours;
    float rate;
    float grsPay;
};

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Intro to the program
    cout<<"This program will calculate the gross pay of any number of "
            "employees."<<endl;
    //Declare Variables
    Pay *employ=nullptr;//Dynamic memory pointer
    int size,count;     //Size of array
    bool breaker;       //Will detect if hours or rate is negative to terminate
                        //loop
    
    //Process Input/Output
    cout<<"How many employees are you calculating gross pays for?"<<endl;
    cin>>size;
    
    employ=new Pay[size];
    
    //Gathering Data
    for(int i=0;i<size;i++){
        cout<<"Enter the employee's name   : ";
        cin>>employ[i].name;
        cout<<"Enter the pay rate per hour : ";
        cin>>employ[i].rate;
        
        //Input Validation
        if(employ[i].rate<0){
            cout<<"Invalid pay rate, terminating program..."<<endl;
            exit(0);
        }
        
        cout<<"Enter the hours worked      : ";
        cin>>employ[i].hours;
        
        //Input Validation
        if(employ[i].hours<0){
            cout<<"Invalid amount of hours, terminating program..."<<endl;
            exit(0);
        }
        
        //Calculations
        if(employ[i].hours<=30){
            employ[i].grsPay=(employ[i].hours)*(employ[i].rate);
        }
        if(employ[i].hours<30&&employ[i].hours>=50){
            employ[i].grsPay=(30)*(employ[i].rate);
            employ[i].grsPay+=(employ[i].hours-30)*(employ[i].rate)*(2);
        }
        if(employ[i].hours>50){
            employ[i].grsPay=(30)*(employ[i].rate);    //Standard Pay Rate
            employ[i].grsPay+=(20)*(employ[i].rate)*(2);//Double Pay Rate
            employ[i].grsPay+=(employ[i].hours-50)*(employ[i].rate)*(3);
        }
        
        //Output Paycheck
        
        cout<<"Pay Check"<<endl;
        cout<<"========================================"<<endl;
        cout<<"Name of Employee          : "<<employ[i].name<<endl;
        cout<<"Pay Rate per Hour         : $"<<employ[i].rate<<endl;
        cout<<"Hours Worked              : "<<employ[i].hours<<endl;
        cout<<"Gross Pay                 : $"<<employ[i].grsPay<<endl;
        cout<<"========================================"<<endl;
        
    }
    
    
    //Exit
    return 0;
}

