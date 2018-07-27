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

float const YPD=98.93f;//Yen Per Dollar
float const EUPD=.74f;     //Euros Per Dollar

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float dol;//Dollar amount input
    float yen,euro;//Yen and Euro amounts converted from dollars
    
    //Initialize Variables
    cout<<"This program converts dollars to yen and euros."<<endl;
    cout<<"Please input the dollar amount you would like to convert."<<endl;
    cin>>dol;
    
    //Process Input/Output
    yen=YPD*dol;
    euro=EUPD*dol;
    
    //Display Results
    cout<<"Dollars : "<<dol<<" ----> Yen : "<<yen<<endl;
    cout<<"Dollars : "<<dol<<" ----> Euro : "<<euro<<endl;
    
    //Exit
    return 0;
}

