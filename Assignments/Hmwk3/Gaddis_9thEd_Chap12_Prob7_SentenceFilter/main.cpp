/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//Input/Output functions
#include <fstream> //Input/Output Files
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Introduction to Program
    cout<<"This program will filter sentences and correct them to have "
            "proper grammer."<<endl;
    cout<<"The files names are in the project folder. The input file is "
            "'incorrect.txt and the output file is 'correct.txt'"<<endl;
    
    //Declare Variables
    string name1,name2;//Names provided by the user
    char ch;           //Variable for checking
    
    //Initialize Variables
    cout<<"Please input the first file name."<<endl;
    cin>>name1;//Name of the files are in the project folder
    cout<<"Please input the second file name."<<endl;
    cin>>name2;//Name of the files are in the project folder
    
    //Opening the file for input
    fstream inFile;
    inFile.open(name1,ios::in);
    
    //Opening the file for output
    fstream outFile;
    outFile.open(name2,ios::out | ios::app);
    
    
    //Checking to see if the file exists
    if(inFile&&outFile){
        while(!inFile.eof()){
            inFile.get(ch);
            outFile.put(toupper(ch));
            while(ch!='.'){
                inFile.get(ch);
                outFile.put(tolower(ch));
            }
        }
    }
    else{
        cout<<"Error: File name inputted does not exist."<<endl;
    }
   
    
    //Closing files
    inFile.close();
    outFile.close();
    
    //Exit
    return 0;
}