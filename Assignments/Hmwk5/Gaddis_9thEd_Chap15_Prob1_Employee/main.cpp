/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on:
 * Purpose: Employee and Production Worker Class Programs (Problem 15.1)
*/

//System Libraries Here

//User Libraries Here
#include "Employee.h"
#include "ProdWrk.h"

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string name;
    string date;
    float rate;
    int id;
    int shift;
    
    //Declaring the objects
    Employee employ;//Just the standard employee
    ProdWrk worker; //Production worker, using the specialized ProdWrk Class
    
    cout<<"Input the employee's data..."<<endl;
    //Initializing data for standard employee
    cout<<"Please input the employee's name : ";
    cin>>name;
    employ.setName(name);
    cout<<"Please input the employee's ID number : ";
    cin>>id;
    employ.setNumb(id);
    cin.ignore();
    cout<<"Please input the employee's employment date : ";
    getline(cin,date);
    employ.setDate(date);
    
    cout<<"Input the production worker's data..."<<endl;
    //Initializing data for the production worker
    cout<<"Please input the production worker's name : ";
    cin>>name;
    worker.setName(name);
    cout<<"Please input the production worker's ID number : ";
    cin>>id;
    worker.setNumb(id);
    cout<<"Please input the production worker's employment date : ";
    cin>>date;
    worker.setDate(date);
    cin.ignore();
    cout<<"Please input the shift time."<<endl;
    cout<<"A '1' indicates the day shift and a '0' indicates the night shift : ";
    cin>>shift;
    worker.setShif(shift);
    cout<<"Please input the production worker's pay rate : ";
    cin>>rate;
    worker.setRate(rate);
    
    //Display Results
    
    
    //Exit
    return 0;
}