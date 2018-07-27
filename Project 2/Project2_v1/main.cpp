/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on:
 * Purpose:
*/

//System Libraries Here


//User Libraries Here
#include "Player.h"
#include "Dice.h"

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
void first(Dice *,int,Player *,int);   //Determining who goes first
void turn(Dice *,int,Player *,int);    //Cycling through the turns

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    //Declare all Variables Here
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    
    //Array sizing stuff
    const int DICE=5;//Number of dice thrown
    Player *plyr=nullptr;
    Dice *dice=nullptr;
    
    //Scoring and other game-related stuff
    char deci;                  //Decision to play the game or not
    int turns=1;                //Game lasts 20 turns, starts at 1
    int nPlyr;                  //How many players are determined to play
    float total,avgPt;          //Total points and average points per turn
    
    //Member Function Variables
    string name;
    
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    //End of Variable Declaring
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    
    //Introduction
    cout<<"This program can play Yahtzee with 2-5 people."<<endl;
    cout<<"Press 'y' to play and 'n' to exit."<<endl;
    
    cin>>deci;
    
    while(deci!='y'&&deci!='n'){
        cout<<"Please input a valid response."<<endl;
        cin>>deci;
    }
    
    if(deci=='n'){
        exit(0);
    }
    
    //Determining how many players are going to play the game
    cout<<"How many players are going to play the game? Pick from 2-5."<<endl;
    while(nPlyr<2||nPlyr>5){
        cin>>nPlyr;
        
        //Input Validation
        if(nPlyr<2||nPlyr>5){
            cout<<"Invalid number of players. Please enter a number from "
                    "2-5."<<endl;
            cin>>nPlyr;
        }
    }
    
    //Skips to the next line
    cin.ignore();
    
    //Declaring the array of objects parallel to each other
    plyr=new Player[nPlyr];
    dice=new Dice[nPlyr];
    
    //Getting the player's names
    for(int i=0;i<nPlyr;i++){
        cout<<"Please input player "<<i+1<<"'s name."<<endl;
        getline(cin,name);
        plyr[i].setName(name);
    }
    
    //Deciding who will go first
    first(dice,DICE,plyr,nPlyr);
    
    //Display Results
    
    
    //Exit
    
    delete [] plyr;
    delete [] dice;
    
    return 0;
}
void first(Dice *dice,int nDice,Player *plyr,int nPlyr){
    //Variables for organization
    int indx1,indx2;
    
    
    cout<<"Players will now roll to see who will go first."<<endl;
    cout<<"========================"<<endl;
    
    for(int i=0;i<nPlyr;i++){
        cout<<plyr[i].getName()<<" is rolling..."<<endl;
        dice[i].roll();
        indx1=dice[i].sum();
        plyr[i].setIndx(indx1);
        
        //Displaying outcome
        cout<<plyr[i].getName()<<" rolled : ";
        dice[i].display();
        cout<<endl;
        cout<<"========================"<<endl;
        
    }
    
    //Comparing indexes and sorting based on who got the highest scores
    for(int i=0;i<nPlyr;i++){
        for(int j=i+1;j<nPlyr;j++){
            indx1=plyr[i].getIndx();
            indx2=plyr[j].getIndx();
            if(plyr[i].getIndx()<plyr[j].getIndx()){
                Player temp=plyr[i];
                plyr[i]=plyr[j];
                plyr[j]=temp;
            }
        }
    }
    
    //Displaying who will go first
    for(int i=0;i<nPlyr;i++){
        cout<<plyr[i].getName()<<" will be player "<<i+1<<endl;
    }
}
void turn(Dice *,int,Player *,int);    //Cycling through the turns