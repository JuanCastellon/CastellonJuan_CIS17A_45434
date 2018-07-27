/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here

//User Libraries Here
#include "Time.h"
#include "MilTime.h"

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int hour;
    int second;
    
    //Initialize Variables
    cout<<"Input the time in military time."<<endl;
    cin>>hour;
    //Input Validation
    while(hour>2359||hour<0){
        cout<<"Invalid Input. Make sure the number is not above 1259 or below "
                "0."<<endl;
    }
    cout<<"Input the seconds in standard time."<<endl;
    cin>>second;
    //Input Validation
    while(second>59||second<0){
        cout<<"Invalid input. Make sure the number is not above 59 or below "
                "0."<<endl;
    }
    
    //Declare Object
    MilTime time(hour,second);
    
    //Getting the standard time
    time.setTime(hour,second);
        
    
    //Display Results
    cout<<"Military Time : "<<time.getHour()<<endl;
    cout<<"Standard Time : ";
    time.getStHr();
    
    //Exit
    return 0;
}