/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on:
 * Purpose: Employee and Production Worker Class Programs (Problem 15.1)
*/

//System Libraries Here

//User Libraries Here
#include "Employee.h"
#include "SftSupr.h"

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string name;
    string date;
    float bonus;
    float salary;
    int id;
    
    //Initializing Variables
    cout<<"Input the Shift Supervisor's data..."<<endl;
    cout<<"Please input their name               : ";
    getline(cin,name);
    cout<<"Please input their ID                 : ";
    cin>>id;
    cin.ignore();
    cout<<"Please input their date of employment : ";
    getline(cin,date);
    cout<<"Please input their annual salary      : $";
    cin>>salary;
    cout<<"Please input their monthly bonus      : $";
    cin>>bonus;
    
    //Declare Object
    SftSupr sprvisr(salary,bonus);
    sprvisr.setName(name);
    sprvisr.setNumb(id);
    sprvisr.setDate(date);
    
        
    //Display Results
    cout<<"Name               : "<<sprvisr.getName()<<endl;
    cout<<"ID                 : "<<sprvisr.getNumb()<<endl;
    cout<<"Date of Employment : "<<sprvisr.getDate()<<endl;
    cout<<"Annual Salary      : "<<sprvisr.getSal()<<endl;
    cout<<"Monthly Bonus      : "<<sprvisr.getBon()<<endl;
    
    //Exit
    return 0;
}