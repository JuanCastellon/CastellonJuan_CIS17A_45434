/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <cctype>  //upper lower
#include <cstring> //Strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Introduction to Program
    cout<<"This program will verify if a password passes "
          "the minimum criteria to be an acceptable password"<<endl;
    
    //Declare Variables
    const int SIZE=24;           //Max length of password
    int upper,lower,length,digit;//Uppercase/Lowercase/Digit counter, pass lengt
    char pass[SIZE];             //Array to hold the password
    
    //Initialize Variables
    cout<<"Input password:";
    cin.getline(pass,SIZE);
    
    //Process Input/Output
    length=strlen(pass);
    for(int i=0;i<length;i++){
        if(isupper(pass[i])){
            upper++;
        }
        if(islower(pass[i])){
            lower++;
        }
        if(isdigit(pass[i])){
            digit++;
        }
    }
    
    if(length<6){
        cout<<"Password needs to be at least 6 character long."<<endl;
    }
    else if(upper<1){
        cout<<"Password requires at least 1 uppercase letter."<<endl;
    }
    else if(lower<1){
        cout<<"Password requires at least 1 lowercase letter."<<endl;
    }
    else if(digit<1){
        cout<<"Password requires as least 1 digit."<<endl;
    }
    else{
        cout<<"Password satisfies all criteria!"<<endl;
    }
    
    //Exit
    return 0;
}

