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
    cout<<"This program will search for a string you input from a file."<<endl;
    cout<<"The file given is 'strings.txt'."<<endl;
    
    //Declare Variables
    string stuff;  //The string being searched for
    string fileNam;//Name of the file
    string var;    //Placeholding variable
    int count=1;   //Which line said string is found on
    int occur=0;   //Total occurrences
    
    //Initialize Variables
    ifstream fileIn;
    cout<<"Input the name of the file."<<endl;
    cin>>fileNam;
    fileIn.open(fileNam);
    
    cout<<"Please input the word or phrase you would like to search for."<<endl;
    cin>>stuff;
    
    if(fileIn.fail()){
        cout<<"Error in opening file."<<endl;
        exit(0);
    }
    
    //Process Input/Output
    while(!fileIn.eof()){
        fileIn>>var;
        if(stuff==var){
            cout<<"Occurrence found on line "<<count<<endl;
            occur++;
        }
    }
    
    //Display Results
    cout<<"Occurrences :"<<occur<<endl;
    
    
    //Exit
    return 0;
}

