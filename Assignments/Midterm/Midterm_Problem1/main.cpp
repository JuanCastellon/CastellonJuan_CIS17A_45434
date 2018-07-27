/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <cctype>  
#include <cstring>
#include <string>
using namespace std;

//User Libraries Here
struct Checking{
    string name;
    string addy;
    string accNum;
    float balance;
    float totChek;
    float totDepo;
};

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Introduction to the program
    cout<<"This program will track the checking account of a user."<<endl;
    
    //Declare Variables
    Checking *chekPtr=nullptr;
    chekPtr=new Checking;
    char decis;               //Decision for continuing loops
    float check;              //The amount of the check written inputted by user
    
    //Input Validation Variables
    const int SIZE=5;
    char c[SIZE];
    bool chekNum;  //For checking if the account number is a number
    int chekLen;         //For checking the length of the account number
    
    
    
    
    //Initialize Variables
    cout<<"Please enter the name of the account holder."<<endl;
    getline(cin,chekPtr->name);
    cout<<"Please enter the account holder's address."<<endl;
    getline(cin,chekPtr->addy);
    cout<<"Please enter the account number."<<endl;
    getline(cin,chekPtr->accNum);
    
    //Input Validation
    
    chekLen=(chekPtr->accNum).length();//Checking for length using length funct
    
    //Making a copy of the string to test for digits
    for(int i=0;i<SIZE;i++){
        c[i]=(chekPtr->accNum[i]);
    }
    //Checking for digits
    for(int i=0;i<SIZE;i++){
        if(isdigit(c[i])){
            chekNum=true;
        }
        else{
            chekNum=false;
            i=SIZE;       //Sorry if this looks like bad programming, could not
                          //get the loop to stop when chekNum is false so I just
                          //made 'i' determine when to stop the loop.
        }
    }
    
    if(chekLen!=5&&chekNum==false){
        do{
            cout<<"Invalid account number. Please reinput the number. Make sure"
                    " you are only inputting 5 digits."<<endl;
            getline(cin,chekPtr->accNum);

            //Checking for digits
            for(int i=0;i<SIZE;i++){
            if(isdigit(c[i])){
                chekNum=true;
            }
            else{
                chekNum=false;
                i=SIZE;
                }
            }
            //Checking for Length
            chekLen=(chekPtr->accNum).length();

        }while(chekLen!=5&&chekNum==false);
    }
    
    cout<<"Enter the balance at the beginning of this month."<<endl;
    cin>>chekPtr->balance;
    
    //Process Input/Output
    cout<<"Current Balance :"<<chekPtr->balance<<endl;
    cout<<"Would you like to list any checks you have written?"<<endl;
    cout<<"y/n"<<endl;
    cin>>decis;
    
    do{
        cout<<"Please input the total of the check now."<<endl;
        cin>>check;
        chekPtr->balance-=check;
        chekPtr->totChek+=check;
        cout<<"New Balance : "<<chekPtr->balance<<endl;
        cout<<"Would you like to list another check?"<<endl;
        cout<<"y/n"<<endl;
        cin>>decis;
    }while(decis=='y');
    
    //Display Results
    cout<<"Would you like to list any deposits you have made?"<<endl;
    cout<<"y/n"<<endl;
    cin>>decis;
    
    do{
        cout<<"Please input the total of the deposit now."<<endl;
        cin>>check;
        chekPtr->balance+=check;
        chekPtr->totDepo+=check;
        cout<<"New Balance : "<<chekPtr->balance<<endl;
        cout<<"Would you like to list another deposit?"<<endl;
        cout<<"y/n"<<endl;
        cin>>decis;
    }while(decis=='y');
    
    if(chekPtr->balance<0){
        cout<<"You have overdrawn. You will be charged an additional"
                " $15."<<endl;
        chekPtr->balance-=15;
    }
    
    cout<<"Name                    : "<<chekPtr->name<<endl;
    cout<<"Address                 : "<<chekPtr->addy<<endl;
    cout<<"Account Number          : "<<chekPtr->accNum<<endl;
    cout<<"Total of Checks Written :  $"<<chekPtr->totChek<<endl;
    cout<<"Total Deposits          :  $"<<chekPtr->totDepo<<endl;
    cout<<"Total Balance           :  $"<<chekPtr->balance<<endl;
    
    //Exit
    return 0;
}

