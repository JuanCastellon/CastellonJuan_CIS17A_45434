/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on
 * Purpose:  Yahtzee Game
 */

//System Libraries Here
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

//User Libraries Here
struct Player{
    string name;  //Name of Player
    float score=0;//Score of Player
    int yah=0;    //Yahtzee Counter for each Player
    int index=0;  //For determining who goes first
};
struct Dice{
    int d1,d2,d3,d4,d5;
};

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//123412341234123412341234123412341234123412341234123412341234123412341234123412
//Function Prototypes Here
//123412341234123412341234123412341234123412341234123412341234123412341234123412

//Starting the game
int pTotal(int [],int);           //Calculates the total roll of a player
bool first(Dice,int,Player,int);//Sees who goes first  

//Essentials for playing the game
int turn(int [],int,Player);//Turns for the game
void rolDice(int [],int);                 //Rolling the Dice

//Scoring
int scre(int [],int,int,int,int);//Scoring Both Sections

//Sorting
void sort(int [],int);    //Bubble Sort

//123412341234123412341234123412341234123412341234123412341234123412341234123412
//End of Function Prototypes
//123412341234123412341234123412341234123412341234123412341234123412341234123412

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Set precision
    cout<<showpoint<<fixed<<setprecision(1);
    
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    //Declare all Variables Here
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    
    //Array sizing constants
    const int DICE=5;  //Number of dice thrown
    Player *plyr=nullptr;
    Dice *dice=nullptr;
    
    
    //Player Names
    string name1,name2,//Input names of the players
           ply1,ply2;  //Determines who goes 
    
    
    //Boolean Variables for checking things
    
    
    
    //Scoring and other game-related stuff
    char deci;                  //Decision to play the game or not
    int turns=1;                //Game lasts 20 turns, starts at 1
    int roll[DICE]={};          //Array for holding the dice
    int nPlyr;                  //How many players are determined to play
    float total,avgPt;          //Total points and average points per turn
    
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    //End of Variable Declaring
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    
    
    //Initialize Variables
    total=0;
    
    ofstream out; //Output File
    string fileIn;//Name of file
    char fileOut[]="WinLoss.dat";//Outputs the win and loss for players
    
    //Opening Files
    out.open(fileOut);
    
    
    
    //Introduction
    cout<<"This program can play Yahtzee with 2-5 people."<<endl;
    cout<<"Press 'y' to play and 'n' to exit."<<endl;
    
    //Input Validation/Proceeding or Exiting Main
    do{
        cin.get(deci);
            
    }while(deci!='y'&&deci!='n');
    cout<<endl;
    
    if(deci=='n'){
        exit(0);
    }
    
    //Skip to next line
    cin.ignore();
    
    //Determining how many players are going to play the game
    cout<<"How many players are going to play the game? Pick from 2-5."<<endl;
    while(nPlyr<2||nPlyr>5){
        cin>>nPlyr;
        
        //Input Validation
        if(nPlyr<2||nPlyr>5){
            cout<<"Invalid number of players. Please enter a number from "
                    "2-5."<<endl;
        }
    }
    
    //Dynamically allocating array of structures
    plyr=new Player[nPlyr];
    dice=new Dice[nPlyr];
    
    //Input User Names
    for(int i=0;i<nPlyr;i++){
        cout<<"Please input player "<<i+1<<"'s name."<<endl;
        getline(cin,plyr->name);
    }
    
    
    //Roll to determine who goes first
    first(dice,DICE,plyr,nPlyr);
        
    
    //Turns
    
    do{
        for(int plays=0;plays<nPlyr;plays++){
            cout<<"It is now "<<plyr->name<<"'s turn."<<endl;
            plyr->score+=turn(roll,DICE,Player plyr);
            cout<<plyr->name<<"'s score is : "<<plyr->score<<endl;
        }
    
        turns++;
        
    }while(turns<=20);
    
    //Determining the Winner and outputs to a file
//    if(p1Tot>p2Tot){
//        cout<<"Player 1 is the winner!"<<endl;
//        out<<"Player 1 is the winner!"<<endl;
//    }
//    if(p2Tot>p1Tot){
//        cout<<"Player 2 is the winner!"<<endl;
//        out<<"Player 2 is the winner!"<<endl;
//    }
//    if(p1Tot==p2Tot){
//        cout<<"The game resulted in a tie."<<endl;
//        out<<"The game resulted in a tie."<<endl;
//    }
//    
//    total=(static_cast<float>(p1Tot))+p2Tot;
//    avgPt=round(total/20);
//    
//    cout<<"Average points per turn = "<<avgPt<<endl;
    
    //Closing files
    
    out.close();
    
    //Exit
    return 0;
}

//First Player Function
bool first(int roll[],int dice,Player plyr,int nPlyr){
    
    for(int i=0;i<nPlyr;i++){
        
    }
    
    
    
//    do{
//        //Player 1 Roll and Total
//        cout<<name1<<" now rolling..."<<endl;
//        p1Tot=pTotal(roll,dice);
//        
//        cout<<"======================="<<endl;
//
//        //Player 2 Roll and Total
//        cout<<name2<<" now rolling..."<<endl;
//        p2Tot=pTotal(roll,dice);
//        
//        cout<<"======================="<<endl;
//    
//    }while(p1Tot==p2Tot);
//    
//    if(p1Tot>p2Tot){
//        return true;
//    }else{
//        return false;
//    }
    
}

//Player Total Roll Function
int pTotal(int roll[],int dice){
    int tot,count;
    count=tot=0;
    rolDice(roll,dice);
    while(count<dice){
        tot+=roll[count];
        count++;
    }
    cout<<"Total = "<<tot<<endl;
    return tot;
}

//Dice Roll Function
void rolDice(int roll[],int dice){
    for(int count=0;count<dice;count++){
        roll[count]=rand()%6+1;
    }
    cout<<"Your roll is: ";
    for(int count=0;count<dice;count++){
        cout<<roll[count]<<" ";
    }
    cout<<endl;
}

//Function for playing the game's turns
int turn(int roll[],int dice,Player plyr){
    int choice,score,rolls;
    rolls=score=0;
    cout<<current<<"'s turn"<<endl;
    cout<<"Rolling dice..."<<endl;
    rolDice(roll,dice);
    
    cout<<"Which category would you like to score?"<<endl;
    cout<<"Aces           = 1"<<endl;
    cout<<"Twos           = 2"<<endl;
    cout<<"Threes         = 3"<<endl;
    cout<<"Fours          = 4"<<endl;
    cout<<"Fives          = 5"<<endl;
    cout<<"Sixes          = 6"<<endl;
    cout<<"3 of a Kind    = 7"<<endl;
    cout<<"4 of a Kind    = 8"<<endl;
    cout<<"Full House     = 9"<<endl;
    cout<<"Small Straight = 10"<<endl;
    cout<<"Large Straight = 11"<<endl;
    cout<<"Yahtzee        = 12"<<endl;
    cout<<"Chance         = 13"<<endl;
    
    
    //Input Validation:Checks to see if choice is within the range  
    do{
    cin>>choice;
    }while(choice<1&&choice>13);
    
    score=scre(roll,dice,choice,plyr);

    cout<<"================"<<endl;
    
    return score;
    
    
}

//Scoring Function
int scre(int roll[],int dice,int choice,int yah,int oLoad){
    int total,counter;
    total=counter=0;
    switch(choice){
        case 1:{
            cout<<"Scoring Aces"<<endl;
            for(int count=0;count<dice;count++){
                roll[count]==1?total+=1:total+=0;
            }
            break;
        }
        case 2:{
            cout<<"Scoring Twos"<<endl;
            for(int count=0;count<dice;count++){
                roll[count]==2?total+=2:total+=0;
            }
            break;
        }
        case 3:{
            cout<<"Scoring Threes"<<endl;
            for(int count=0;count<dice;count++){
                roll[count]==3?total+=3:total+=0;
            }
            break;
        }
        case 4:{
            cout<<"Scoring Fours"<<endl;
            for(int count=0;count<dice;count++){
                roll[count]==4?total+=4:total+=0;
            }
            break;
        }
        case 5:{
            cout<<"Scoring Fives"<<endl;
            for(int count=0;count<dice;count++){
                roll[count]==5?total+=5:total+=0;
            }
            break;
        }
        case 6:{
            cout<<"Scoring Sixes"<<endl;
            for(int count=0;count<dice;count++){
                roll[count]==6?total+=6:total+=0;
            }
            break;
        }
        case 7:{
            cout<<"Scoring 3 of a Kind"<<endl;
            sort(roll,dice);
            int temp=roll[0];
            for(int count=0;count<dice;count++){
                roll[count]==temp?counter++:temp=roll[count];
            }
            if(counter==3){
                for(int count=0;count<dice;count++){
                    total+=roll[count];
                    total*=3;
                }
            }
            break;
        }
        case 8:{
            cout<<"Scoring 4 of a Kind"<<endl;
            sort(roll,dice);
            int temp=roll[0];
            for(int count=0;count<dice;count++){
                if(roll[count]==temp){
                    counter++;    
                }else{
                    temp=roll[count];
                }
            }
            if(counter==4){
                for(int count=0;count<dice;count++){
                    total+=roll[count];
                    total*=4;
                }
            }
            break;
        }
        case 9:{
            cout<<"Scoring Full House"<<endl;
            if(roll[0]==roll[1]){
                if(roll[2]==roll[3]==roll[4]){
                    total=25;
                }
            }
            if(roll[0]==roll[1]==roll[2]){
                if(roll[4]==roll[5]){
                    total=25;
                }
            }
            break;
        }
        case 10:{
            cout<<"Scoring Small Straight"<<endl;
            sort(roll,dice);
            if((roll[4]-roll[3])==1){
                if((roll[3]-roll[2]==1)){
                    if((roll[2]-roll[1]==1)){
                        total=30;
                    }
                }
            }
            if((roll[3]-roll[2])==1){
                if((roll[2]-roll[1]==1)){
                    if((roll[1]-roll[0]==1)){
                        total=30;
                    }
                }
            }
            break;
        }
        case 11:{
            cout<<"Scoring Long Straight"<<endl;
            sort(roll,dice);
            if((roll[4]-roll[3])==1){
                if((roll[3]-roll[2]==1)){
                    if((roll[2]-roll[1]==1)){
                        if((roll[1]==roll[0])==1){
                            total=40;
                        }
                    }
                }
            }
            break;
        }
        case 12:{
            cout<<"Scoring Yahtzee"<<endl;
            if(roll[0]==roll[1]==roll[2]==roll[3]==roll[4]){
                if(yah>0){
                    total=100;
                }else if(yah==0){
                    total=50;   
                } 
            }
            break;
        }
        case 13:{
            cout<<"Scoring Chance"<<endl;
            for(int count=0;count<dice;count++){
                total+=roll[count];
            }
            break;
        }
    }
    cout<<"Total scored = "<<total<<endl;
    return total;
}

//Bubble Sort
void sort(int roll[],int dice){
    for(int count=0;count<dice-1;count++){
        for(int place=count+1;place<dice;place++){
            if(roll[count]>roll[place]){
                int temp=roll[count];
                roll[count]=roll[place];
                roll[place]=temp;
            }
        }
    }
}



