/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <fstream>
#include <cstring>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Intro to program
    cout<<"This program will add line numbers to a file's contents on screen\n";
    cout<<"The file given is 'strings.txt'."<<endl;
    
    //Declare Variables
    string fileNam;//Name of the file
    string var;    //Placeholding variable for the contents of the file
    int count=1;   //A count for the the line numbers
    
    //Initialize Variables
    ifstream fileIn;
    cout<<"Input the name of the file."<<endl;
    cin>>fileNam;
    fileIn.open(fileNam);
    
    if(fileIn.fail()){
        cout<<"Error in opening file."<<endl;
        exit(0);
    }
    
    //Process Input/Output
    while(!fileIn.eof()){
        fileIn>>var;
        cout<<count<<":";
        cout<<var<<endl;
        count++;
    }
    
    
    
    //Exit
    return 0;
}

