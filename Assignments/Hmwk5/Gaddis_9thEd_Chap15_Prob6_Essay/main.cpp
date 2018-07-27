/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on:
 * Purpose: Scoring an essay using the derived classed "Essay" from "GradAct"
*/

//System Libraries Here

//User Libraries Here
#include "Essay.h"
#include "GradAct.h"

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float gram=0;
    float spel=0;
    float leng=0;
    float cont=0;
    float score=0;
    char grade;
    
    //Initialize Variables
    cout<<"This program will grade an essay based on 5 criteria."<<endl;
    cout<<"Please enter the grammar score out of 30  : ";
    cin>>gram;
    cout<<"Please enter the spelling score out of 20 : ";
    cin>>spel;
    cout<<"Please enter the length score out of 20   : ";
    cin>>leng;
    cout<<"Please enter the content score out of 30  : ";
    cin>>cont;
    
    //Creating the object
    Essay essay(gram,spel,leng,cont);
    
    //Process Input/Output
    score=essay.crit();
    essay.setScre(score);
    grade=essay.getLtGr();
    
    //Display Results
    cout<<"Grade of Essay = "<<essay.getScre()<<endl;
    cout<<"Letter Grade   = "<<grade<<endl;
    
    //Exit
    return 0;
}