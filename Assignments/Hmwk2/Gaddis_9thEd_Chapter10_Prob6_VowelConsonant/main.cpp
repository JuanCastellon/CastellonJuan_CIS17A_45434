/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
int findVow(char *);
int findCon(char *);

//Program Execution Begins Here
int main(int argc, char** argv) {
     //Intro to the program
    cout<<"This program will find the number of vowels and or "
            "consonants in a string."<<endl;
    
    //Declare Variables
    const int SIZE=150;//Size of char array
    int vowel,conson,choice;
    char *ptr=nullptr;
    char senten[SIZE];
    
    //Initialize Variables
    cout<<"Please type in the string."<<endl;
    cin.getline(senten,SIZE);
    
    //Process Input/Output
    ptr=senten;
    
    do{
    cout<<"This is a menu for choosing what you want to know about the "
            "string."<<endl;
    cout<<"Press 1 for counting vowels."<<endl;
    cout<<"Press 2 for counting consonants."<<endl;
    cout<<"Press 3 for counting both vowels and consonants."<<endl;
    cout<<"Press 4 for entering another string."<<endl;
    cout<<"Press any other key to exit the menu."<<endl;
    cout<<"---------------------------------------------------------"<<endl;
 
    cin>>choice;
    
    if (choice>=1 && choice<=4){
        switch(choice){
            case 1:{
                vowel=findVow(ptr);
                cout<<"Number of vowels = "<<vowel<<endl;
                break;
            }
            case 2:{
                conson=findCon(ptr);
                cout<<"Number of consonants = "<<conson<<endl;
                break;
            }
            case 3:{
                vowel=findVow(ptr);
                conson=findCon(ptr);
                cout<<"Number of vowels = "<<vowel<<endl;
                cout<<"Number of consonants = "<<conson<<endl;
                break;
            }
            case 4:{
                cout<<"Please type in the string."<<endl;
                cin.ignore();
                cin.getline(senten,SIZE);
                break;
            }
        }
    }else{
        cout<<"Exiting menu"<<endl;
    }
    cout<<"Press 0 to repeat menu or any other key to exit."<<endl;
    cin>>choice;
    }while(choice==0);
    
    //Exit
    return 0;
}
int findVow(char *senten){
    int vowNum,length;
    length=strlen(senten);
    
    for(int i=0;i<length;i++){
        if(*(senten+i)=='a'||*(senten+i)=='A'){
            vowNum++;
        }
        if(*(senten+i)=='e'||*(senten+i)=='E'){
            vowNum++;
        }
        if(*(senten+i)=='i'||*(senten+i)=='I'){
            vowNum++;
        }
        if(*(senten+i)=='o'||*(senten+i)=='O'){
            vowNum++;
        }
        if(*(senten+i)=='u'||*(senten+i)=='U'){
            vowNum++;
        }
    }
    
    return vowNum;
}

int findCon(char *senten){
    int conNum,length,totChar;
    length=strlen(senten);
    
    //Total length of the character array
    totChar=length;
    
    for(int i=0;i<length;i++){
        if(*(senten+i)=='a'||*(senten+i)=='A'||
           *(senten+i)=='e'||*(senten+i)=='E'||
           *(senten+i)=='i'||*(senten+i)=='I'||
           *(senten+i)=='o'||*(senten+i)=='O'||
           *(senten+i)=='u'||*(senten+i)=='U'||*(senten+i)==' '){
            
            //Subtracting total num of chars for every instance of these cases
            totChar--;
            
        }
    }
    
    return totChar;
}