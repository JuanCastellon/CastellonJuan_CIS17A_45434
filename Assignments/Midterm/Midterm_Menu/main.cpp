/* 
 * File:   main.cpp
 * Author: Juan
 * Created on May 27th, 2018, 11:30 PM
 * Purpose: Assignment 6 Menu
 */

//System Libraries Here
#include <iostream>//I/O 
#include <iomanip> // Format
#include <cstdlib> // Random Library
#include <ctime>   // Time Library
#include <cmath>   // Power
#include <fstream> // Files
#include <string>  //Length Function
#include <cstring>
#include <cctype>
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
struct Pay{
    string name;
    int hours;
    float rate;
    float grsPay;
};
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void decrypt(int &);
void encrypt(int &);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int choice;
    do{
    cout<<"This is a menu for accessing all Homework 1 projects."<<endl;
    cout<<"Press 1 for Problem 1 "<<endl;
    cout<<"Press 2 for Problem 2 "<<endl;
    cout<<"Press 3 for Problem 4 : Encryption"<<endl;
    cout<<"Press 4 for Problem 4 : Decryption"<<endl;
    cout<<"Press 5 for Problem 5 "<<endl;
    cout<<"Press 6 for Problem 6 "<<endl;
    cout<<"Press any other key to exit the menu."<<endl;
    cout<<"---------------------------------------------------------"<<endl;
 
    cin>>choice;
    //Input or initialize values Here
    
    if (choice>=1 && choice<=6){
        switch(choice){
            case 1:{
                //Introduction to the program
                cout<<"This program will track the checking account of a user."<<endl;

                //Declare Variables
                Checking *chekPtr=nullptr;
                chekPtr=new Checking;
                char decis;   //Decision for continuing loops
                float check;  //The amount of the check written inputted by user

                //Input Validation Variables
                const int SIZE=5;
                char c[SIZE];
                bool chekNum;  //For checking if the account number is a number
                int chekLen;   //For checking the length of the account number




                //Initialize Variables
                cout<<"Please enter the name of the account holder."<<endl;
                getline(cin,chekPtr->name);
                cout<<"Please enter the account holder's address."<<endl;
                getline(cin,chekPtr->addy);
                cout<<"Please enter the account number."<<endl;
                getline(cin,chekPtr->accNum);

                //Input Validation

                chekLen=(chekPtr->accNum).length();//Checking for length

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
                        i=SIZE;       //Sorry if this looks like bad programming
                                      //could not get the loop to end
                                      //So I terminated it with 'i'
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
                break;
            }
            case 2:{
                //Intro to the program
                cout<<"This program will calculate the gross pay of any number"
                        " of employees."<<endl;
                //Declare Variables
                Pay *employ=nullptr;//Dynamic memory pointer
                int size,count;     //Size of array
                bool breaker;       //Will detect if hours or rate is negative to terminate
                                    //loop

                //Process Input/Output
                cout<<"How many employees are you calculating gross pays for?";
                cout<<endl;
                cin>>size;

                employ=new Pay[size];

                //Gathering Data
                for(int i=0;i<size;i++){
                    cout<<"Enter the employee's name   : ";
                    cin>>employ[i].name;
                    cout<<"Enter the pay rate per hour : ";
                    cin>>employ[i].rate;

                    //Input Validation
                    if(employ[i].rate<0){
                        cout<<"Invalid pay rate, terminating program..."<<endl;
                        exit(0);
                    }

                    cout<<"Enter the hours worked      : ";
                    cin>>employ[i].hours;

                    //Input Validation
                    if(employ[i].hours<0){
                        cout<<"Invalid amount of hours, terminating program...";
                        exit(0);
                    }

                    //Calculations
                    if(employ[i].hours<=30){
                        employ[i].grsPay=(employ[i].hours)*(employ[i].rate);
                    }
                    if(employ[i].hours<30&&employ[i].hours>=50){
                        employ[i].grsPay=(30)*(employ[i].rate);//Standard Pay
                        employ[i].grsPay+=(employ[i].hours-30)*(employ[i].rate)*(2);
                    }
                    if(employ[i].hours>50){
                        employ[i].grsPay=(30)*(employ[i].rate);//Standard Pay
                        employ[i].grsPay+=(20)*(employ[i].rate)*(2);//x2 Rate
                        employ[i].grsPay+=(employ[i].hours-50)*(employ[i].rate)*(3);
                    }

                    //Output Paycheck

                    cout<<"Pay Check"<<endl;
                    cout<<"========================================"<<endl;
                    cout<<"Name of Employee          : "<<employ[i].name<<endl;
                    cout<<"Pay Rate per Hour         : $"<<employ[i].rate<<endl;
                    cout<<"Hours Worked              : "<<employ[i].hours<<endl;
                    cout<<"Gross Pay                 : $"<<employ[i].grsPay<<endl;
                    cout<<"========================================"<<endl;

                }
                break;
            }
            case 3:{
                //Intro to Program
                cout<<"This program will encrypt a 4 digit number."<<endl;
                
                //Declare Variables
                int num;//User Inputted Number

                //Display output and inputs here
                encrypt(num);
                break;
            }
            case 4:{
                //Intro to Program
                cout<<"This program will decrypt a 4 digit number."<<endl;
                //Declare Variables
                int num;//User Inputted Number

                //Display inputs and outputs
                decrypt(num);
                break;
            }
            case 5:{
                cout<<"Maximum Factorials : "<<endl;
                cout<<"Short          : 7  !"<<endl;
                cout<<"Unsigned Short : 7  !"<<endl;
                cout<<"Int            : 12 !"<<endl;
                cout<<"Unsigned Int   : 12 !"<<endl;
                cout<<"Float          : 12 !"<<endl;
                cout<<"Double         : 18 !"<<endl;
                cout<<"Long           : 18 !"<<endl;
                cout<<"Bool           : 1  !"<<endl;
                cout<<"Char           : 1  !"<<endl;
                cout<<"Unsigned Char  : 1  !"<<endl;
                
                break;
            }
            case 6:{
                cout<<"Part A:"<<endl;
                cout<<"================"<<endl;
                cout<<"Decimal : 2.875 "<<endl;
                cout<<"Binary  : 10.111"<<endl;
                cout<<"Hex     : 2.E   "<<endl;
                cout<<"Octal   : 2.7   "<<endl;
                cout<<"================"<<endl;
                cout<<"Decimal : 0.1796875"<<endl;
                cout<<"Binary  : 0.0010111"<<endl;
                cout<<"Hex     : .2E      "<<endl;
                cout<<"Octal   : .134     "<<endl;
                cout<<"==================="<<endl;
                break;
            }
            
        }
    }else{
        cout<<"Exiting menu..."<<endl;
    }
    cout<<"Repeat menu? Press 0"<<endl;
    cin>>choice;
    }while(choice==0);
  
    //Exit
    return 0;
}
void decrypt(int &num){
    int decrypt;//Result of Decryption
    cout<<"Please input a 4 digit number : ";
    cin>>num;
    while(num>9999||num<1000){
        cout<<"The number must be 4 Digits long, try again: ";
        cin>>num;
    }
    
    //Decryption Process
    int n1=(num/1000+3)%8;
    int n2=(num%1000/100+3) %8;
    int n3=(num%1000%100/10+3)%8;
    int n4=(num%1000%100%10+3)%8;
    decrypt=(n3*1000)+(n4*100)+(n1*10)+(n2);
    cout << "Decrypted Number: "<<decrypt<<endl;;
}

void encrypt(int &num){
    //Declare Variables
    int encrypt;//Result of Encryption
    
    //Initialize Variables
    cout<<"Please input a 4 digit number :";
    cin>>num;
    
    //Input Validation
    while (num>9999||num<1000){
        cout<<"Invalid number. Please reinput a 4 digit number."<<endl;
        cin>>num;
    }
    
    //Encryption Process
    int n1=num/1000;
    int n2=(num-(n1*1000))/100;
    int n3=((num-(n1*1000)-(n2*100))/10);
    int n4=((num-(n1*1000)-(n2*100)))-(n3*10);
    
    //Test for #s 8 and 9
    if (n1==8||n1==9||n2==8||n2==9||n3==8||n3==9||n4==8||n4==9){
        cout<< "Error: Number contains 8s and 9s."<< endl;
    }
    else{
        int d1=(n1+5)%8;
        int d2=(n2+5)%8;
        int d3=(n3+5)%8;
        int d4=(n4+5)%8;
        encrypt=(d3*1000)+(d4*100)+(d1*10)+(d2);
        
        //Test of #s 8 and 9
        if(d1==8||d1==9||d2==8||d2==9||d3==8||d3==9||d4==8||d4==9){
            cout<<"Number: "<<encrypt<<" has been flagged."<<endl;
        }
        else{
            cout<<"Encrypted Number: "<<encrypt<<endl;
        }
    }
}