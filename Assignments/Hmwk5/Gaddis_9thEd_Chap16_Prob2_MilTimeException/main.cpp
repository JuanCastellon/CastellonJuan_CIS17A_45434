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
    cout<<"Input the seconds in standard time."<<endl;
    cin>>second;
    
    //Declare Object
    MilTime time(hour,second);
    
    //Getting the standard time
    try{
    time.setTime(hour,second);
    }
    catch(MilTime::BadHour){
        cout<<"ERROR : Military Time inputted is either over 2359 or under 1";
        exit(0);
    }
    catch(MilTime::BadSecs){
        cout<<"ERROR : Seconds inputted is either over 59 or under 1";
        exit(0);
    }
        
    
    //Display Results
    cout<<"Military Time : "<<time.getHour()<<endl;
    cout<<"Standard Time : ";
    time.getStHr();
    
    //Exit
    return 0;
}