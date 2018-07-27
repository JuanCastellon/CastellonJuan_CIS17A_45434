/* 
 * File:   main.cpp
 * Author: Juan
 * Created on May 27th, 2018, 11:30 PM
 * Purpose: Assignment 6 Menu
 */

//System Libraries Here
#include <iostream>//I/O 
#include <iomanip>// Format
#include <cstdlib>// Random Library
#include <ctime>//   Time Library
#include <cmath>//   Power
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int choice;
    do{
    cout<<"This is a menu for accessing all Homework 1 projects."<<endl;
    cout<<"Press 1 for Gaddis  Problem "<<endl;
    cout<<"Press 2 for Gaddis  Problem "<<endl;
    cout<<"Press 3 for Gaddis  Problem 3"<<endl;
    cout<<"Press 4 for Gaddis  Problem 4"<<endl;
    cout<<"Press 5 for Gaddis  Problem 10"<<endl;
    cout<<"Press any other key to exit the menu."<<endl;
    cout<<"---------------------------------------------------------"<<endl;
 
    cin>>choice;
    //Input or initialize values Here
    
    if (choice>=1 && choice<=5){
        switch(choice){
            case 1:{
                
                break;
            }
            case 2:{
               
                break;
            }
            case 3:{
                
                break;
            }
            case 4:{
                
                break;
            }
            case 5:{
                
                break;
            }
            
        }
    }else{
        cout<<"Exiting menu"<<endl;
    }
    cout<<"Repeat menu? Press 0"<<endl;
    cin>>choice;
    }while(choice==0);
  
    //Exit
    return 0;
}
