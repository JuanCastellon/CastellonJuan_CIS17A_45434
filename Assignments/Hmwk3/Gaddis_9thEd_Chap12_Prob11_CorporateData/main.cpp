/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <fstream>
using namespace std;

//User Libraries Here
struct Company{
    string divis;
    int quarter;
    int sales;
};
//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Intro to program
    cout<<"This program will export the data of a company's North, South, "
            "East, and West divisions to a file."<<endl;
    
    //Declare Variables
    const int SIZE=4;//Divisions of the company
    Company a[SIZE];
    
    ofstream fileOut;
    fileOut.open("CompanyData.dat");
    
    //Initialize Variables
    for(int i=0;i<SIZE;i++){
        cout<<"Enter the name of Division "<<i+1<<endl;
        cin>>a[i].divis;
        cout<<"Please enter the quarter (1-4)."<<endl;
        cin>>a[i].quarter;
        cout<<"Please enter the Sales Figure."<<endl;
        do{
            if(a[i].sales<0){
                cout<<"Please input a non-negative sales figure."<<endl;
            }
            cin>>a[i].sales;
        }while(a[i].sales<0);
    }
    
    //Process Input/Output
    cout<<"Copying data to file..."<<endl;
    for(int i=0;i<SIZE;i++){
        fileOut<<a[i].divis;
        fileOut<<endl;
        fileOut<<a[i].quarter;
        fileOut<<endl;
        fileOut<<a[i].sales;
        fileOut<<endl;
        fileOut<<"============";
        fileOut<<endl;
    }
    
    //Display Results
    
    
    //Exit
    return 0;
}

