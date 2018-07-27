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

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int mon,year;//Inputted month and year
    bool leap;//Determine if the year is a leap year
    
    //Initialize Variables
    cout<<"This program will detect the number of days in a given month and "
            "year."<<endl;
    cout<<"Please input a number 1-12 for the month."<<endl;
    cin>>mon;
    cout<<"Please input a number for the year."<<endl;
    cin>>year;
    
    leap==false;
    
    //Process Input/Output
    if(year%100==0){
        if(year%400==0){
            leap=true;
        }
    }
    
    if(year%100==0){
        leap=true;
    }
    
    //Display Results
    switch(mon){
        case 1:
            cout<<"Days in month = 31"<<endl;
            break;
            
        case 2:
            if(leap==true){
                cout<<"Days in month = 29"<<endl;
                break;
            }
            else{
                cout<<"Days in month = 28"<<endl;
                break;
            }
            
        case 3:
            cout<<"Days in month = 31"<<endl;
            break;
            
        case 4:
            cout<<"Days in month = 30"<<endl;
            break;
            
        case 5:
            cout<<"Days in month = 31"<<endl;
            break;
            
        case 6:
            cout<<"Days in month = 30"<<endl;
            break;
            
        case 7:
            cout<<"Days in month = 31"<<endl;
            break;
            
        case 8:
            cout<<"Days in month = 31"<<endl;
            break;
            
        case 9:
            cout<<"Days in month = 30"<<endl;
            break;
            
        case 10:
            cout<<"Days in month = 31"<<endl;
            break;
            
        case 11:
            cout<<"Days in month = 30"<<endl;
            break;
            
        case 12:
            cout<<"Days in month = 31"<<endl;
            break;
            
            
    }
    //Exit
    return 0;
}

