/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here
struct Bureau{
    string name; //Name of the speaker
    string phoneNum;//Speaker's phone number
    string topic;//Speaker's topic
    float fee;   //Fee for the speech
};

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Introduction to the program
    cout<<"This program can collect, modify, and display the contents of "
            "an array of structures that holds the information of a speakers' "
            "bureau."<<endl;
    
    //Declare Variables
    const int SIZE=10;   //Minimum size for array
    int choice,deci,info;//Choice for the menu,decision for which speaker's 
                         //Info to change,which part of the info to change
    Bureau array[SIZE];  //Declaring the array of structures
    
    //Initialize Variables
    for(int i=0;i<SIZE;i++){
        cout<<"Enter speaker #"<<i+1<<"'s:"<<endl;
        cout<<"Name : ";
        cin>>array[i].name;
        cout<<"Phone Number : ";
        cin>>array[i].phoneNum;
        cout<<"Topic : ";
        cin>>array[i].topic;
        cout<<"Fee : ";
        //Input validation
        do{
            if(array[i].fee<0){
                cout<<"Please input a non-negative fee."<<endl;
            }
            cin>>array[i].fee;
        }while(array[i].fee<0);
    }
    
    //Process Input/Output
    do{
    cout<<"What would you like to do with the information?"<<endl;
    cout<<"Press 1 to view the data."<<endl;
    cout<<"Press 2 to change the data."<<endl;
    cout<<"Press any other key to exit the menu."<<endl;
    cout<<"---------------------------------------------------------"<<endl;
 
    cin>>choice;
    
    if (choice>=1 && choice<=2){
        switch(choice){
            case 1:{
                for(int i=0;i<SIZE;i++){
                    cout<<"Speaker "<<i+1<<"'s information :"<<endl;
                    cout<<"Name         : "<<array[i].name<<endl;
                    cout<<"Phone Number : "<<array[i].phoneNum<<endl;
                    cout<<"Topic        : "<<array[i].topic<<endl;
                    cout<<"Fee          : $"<<array[i].fee<<endl;
                }
                break;
            }
            case 2:{
                cout<<"Which speaker's information would you like to"
                        " change?"<<endl;
                do{
                    if(deci<1 && deci>10){
                        cout<<"Please choose a speaker between 1 and 10"<<endl;
                    }
                    cin>>deci;
                }while(deci>=1 && deci<=10);
                do{
                    cout<<"What would you like to change about Speaker "<<deci<<
                            "'s information?"<<endl;
                    cout<<"Press 1 for their name."<<endl;
                    cout<<"Press 2 for their phone number."<<endl;
                    cout<<"Press 3 for their topic."<<endl;
                    cout<<"Press 4 for their fee."<<endl;
                    cin>>info;
                    
                    if(info==1){
                        cout<<"Change the speaker's name:";
                        cin>>array[deci].name;
                    }
                    if(info==2){
                        cout<<"Change the speaker's phone number:";
                        cin>>array[deci].phoneNum;
                    }
                    if(info==3){
                        cout<<"Change the speaker's phone number:";
                        cin>>array[deci].topic;
                    }
                    if(info==4){
                        cout<<"Change the speaker's phone number:";
                        do{
                            if(array[deci].fee<0){
                                cout<<"Please input a non-negative fee."<<endl;
                            }
                            cin>>array[deci].fee;
                        }while(array[deci].fee<0);
                        
                    }
                    cout<<"Press 0 to change another piece of information, "
                            "or any other key to exit."<<endl;
                    
                }while(info==0);
                
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

