/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring>  //String class
using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary


//Function Prototypes Here
int numWrd(char *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Intro to the program
    cout<<"This program will find the number of words in a string."<<endl;
    
    //Declare Variables
    const int SIZE=150;//Size of char array
    int letters,words;
    char *ptr=nullptr;
    char senten[SIZE];
    
    //Initialize Variables
    cout<<"Please type in the string."<<endl;
    cin.getline(senten,SIZE);
    
    ptr=senten;
    
    //Process Input/Output
    words=numWrd(ptr);
    
    //Display Results
    cout<<"Number of Words = "<<words<<endl;
    
    //Exit
    return 0;
}
int numWrd(char *ptr){
    int letters,words;
    float avg;
    words=0;
    letters=strlen(ptr);
    
    //Letters + 1 because we need to account for the null terminator
    for(int i=0;i<letters+1;i++){
        if(*(ptr+i)==' '||*(ptr+i)=='\0'){
            words++;
        }
    }
    avg=static_cast<float>(words)/letters;
    cout<<"Average amount of letters per word "<<avg<<endl;
    return words;
}