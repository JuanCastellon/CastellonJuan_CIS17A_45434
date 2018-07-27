/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on:
 * Purpose: Date Class Modifications with Exceptions
*/

//System Libraries Here

//User Libraries Here
#include "Date.h"

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int d;//Day
    int m;//Month
    int y;//Year
    
    Date date;
    
    //Initialize Variables
    cout<<"Enter the day (1-31)   : ";
    cin>>d;
    try{
    date.setDay(d);
    }
    catch(Date::BadDay){
        cout<<"ERROR : Day is either less than 1 or over 31."<<endl;
        exit(0);
    }
    cout<<"Enter the month (1-12) : ";
    cin>>m;
    try{
    date.setMont(m);
    }
    catch(Date::BadMon){
        cout<<"ERROR : Month is either less than 1 or over 12."<<endl;
        exit(0);
    }
    cout<<"Enter the year         : ";
    cin>>y;
    date.setYear(y);
    
    
    //Process Input/Output
    date.form1();
    date.form2();
    date.form3();
    
    //Display Results
    
    
    //Exit
    return 0;
}