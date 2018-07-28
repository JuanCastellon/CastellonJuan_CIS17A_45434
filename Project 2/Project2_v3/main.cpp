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
#include "Winner.h"
#include <array>

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
void first(Dice *,int,Player *,int);   //Determining who goes first
void turn(Dice *,int,Player *,int);    //Cycling through the turns
void sort(int [],int);                 //Sorting the dice

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
    float score;
    int yah;
    
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
    //Intialization of the static variable
    
    
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
    
    //Turns of the game (there are 20 of them)
    do{
        cout<<"==========="<<endl;
        cout<<"==Turn "<<plyr->getTurn()<<"=="<<endl;
        cout<<"==========="<<endl;
        turn(dice,DICE,plyr,nPlyr);
        plyr->incTurn();
        
    }while(plyr->getTurn()<=20);
    
    //Organizing the array of objects based on score
    for(int i=0;i<nPlyr;i++){
        int indx1,indx2;
        for(int j=i+1;j<nPlyr;j++){
            indx1=plyr[i].getIndx();
            indx2=plyr[j].getIndx();
            if(plyr[i].getScre()<plyr[j].getScre()){
                Player temp=plyr[i];
                plyr[i]=plyr[j];
                plyr[j]=temp;
            }
        }
    }
    
    //For initializing
    name=plyr[0].getName();
    score=plyr[0].getScre();
    yah=plyr[0].getYaht();
    
    //Naming the winner (the first player in the array since it's organized)
    Winner winner(name,score,yah);
    
    //Displaying the winner's stats
    winner.results();
    
    //Deleting Memory
    delete [] plyr;
    delete [] dice;
    
    //Exit
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
void turn(Dice *dice,int nDice,Player *plyr,int nPlyr){
    int choice;  //Choice of scoring
    char decis;  //Decision to reroll any dice
    
    
    for(int i=0;i<nPlyr;i++){
        //Variables that need to be reset for each player every time
        const int SIZE=5;//Size of the array equivalent to the number of dice
        array <int,SIZE>roll;//Array for sorting/scoring. Makes things easier
        int rolls=3;     //Max amount of times you can reroll dice is 3
        int counter=0;   //Counter for scoring later on
        int pChance=plyr[i].getChan();//For determining if chance has been used
        
        //Variables in the class that need to be initialized
        plyr[i].setRoll(3);//They get 3 rerolls
        
        cout<<plyr[i].getName()<<" is rolling..."<<endl;
        
        //Rolling the dice
        dice[i].roll();
        
        //Displaying Results
        cout<<plyr[i].getName()<<" rolled : ";
        dice[i].display();
        cout<<endl;
        cout<<"Would you like to reroll your dice?"<<endl;
        cout<<"y/n : ";
        cin>>decis;
        
        //Input Validation
        while(decis!='y'&&decis!='n'){
            cout<<"Please input a valid response."<<endl;
            cin>>decis;
        }
        
        if(decis=='y'){
            do{
                cout<<"Which die would you like to reroll? ";
                cout<<"Input a number 1-5"<<endl;
                cin>>choice;
                
                //Input Validation
                while(choice>5&&choice<1){
                    cout<<"Please input a number from 1-5.";
                    cin>>choice;
                    cout<<endl;
                }
                
                //Reroll the desired dice
                
                if(choice==1){
                    dice[i].setD1();
                }
                if(choice==2){
                    dice[i].setD2();
                }
                if(choice==3){
                    dice[i].setD3();
                }
                if(choice==4){
                    dice[i].setD4();
                }
                if(choice==5){
                    dice[i].setD5();
                }
                
                //Display the dice after the change
                
                cout<<"========New Roll========= "<<endl;
                cout<<plyr[i].getName()<<" rolled : ";
                dice[i].display();
                cout<<endl;
                
                --plyr[i];
                cout<<"Rerolls left : "<<plyr[i].getRoll()<<endl;
                
                
                if(plyr[i].getRoll()!=0){
                    cout<<"Would you like to reroll again?"<<endl;
                    cout<<"y/n : ";

                    cin>>decis;
                    cout<<endl;
                }
            }while(decis=='y'&&plyr[i].getRoll()!=0);
        }
        
        //Copying the numbers in the dice object to an array for easier scoring
        roll[0]=dice[i].getD1();
        roll[1]=dice[i].getD2();
        roll[2]=dice[i].getD3();
        roll[3]=dice[i].getD4();
        roll[4]=dice[i].getD5();
        
        //Scoring the dice rolls now
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
        cout<<"Note! You may only score by chance once!"<<endl;
        
        cin>>choice;
        
        //Input Validation
        while(choice>13&&choice<1){
            cout<<"Invalid choice. Please choose a number from 1-13."<<endl;
            cin>>choice;
        }
        
        while(pChance>0){
            cout<<"You have already chosen the Chance category. Please "
                    "select another category."<<endl;
            cin>>choice;
        }
        
        //Checking if Chance category was selected
        if(choice==13){
            plyr[i].incChan();
        }
        
        switch(choice){
            case 1:{
                cout<<"Scoring Aces"<<endl;
                if(roll[0]==1){
                    plyr[i].setScre(1);
                }
                if(roll[1]==1){
                    plyr[i].setScre(1);
                }
                if(roll[2]==1){
                    plyr[i].setScre(1);
                }
                if(roll[3]==1){
                    plyr[i].setScre(1);
                }
                if(roll[4]==1){
                    plyr[i].setScre(1);
                }
                
                break;
            }
            case 2:{
                cout<<"Scoring Twos"<<endl;
                if(roll[0]==2){
                    plyr[i].setScre(2);
                }
                if(roll[1]==2){
                    plyr[i].setScre(2);
                }
                if(roll[2]==2){
                    plyr[i].setScre(2);
                }
                if(roll[3]==2){
                    plyr[i].setScre(2);
                }
                if(roll[4]==2){
                    plyr[i].setScre(2);
                }
                break;
            }
            case 3:{
                cout<<"Scoring Threes"<<endl;
                if(roll[0]==3){
                    plyr[i].setScre(3);
                }
                if(roll[1]==3){
                    plyr[i].setScre(3);
                }
                if(roll[2]==3){
                    plyr[i].setScre(3);
                }
                if(roll[3]==3){
                    plyr[i].setScre(3);
                }
                if(roll[4]==3){
                    plyr[i].setScre(3);
                }
                break;
            }
            case 4:{
                cout<<"Scoring Fours"<<endl;
                if(roll[0]==4){
                    plyr[i].setScre(4);
                }
                if(roll[1]==4){
                    plyr[i].setScre(4);
                }
                if(roll[2]==4){
                    plyr[i].setScre(4);
                }
                if(roll[3]==4){
                    plyr[i].setScre(4);
                }
                if(roll[4]==4){
                    plyr[i].setScre(4);
                }
                break;
            }
            case 5:{
                cout<<"Scoring Fives"<<endl;
                if(roll[0]==5){
                    plyr[i].setScre(5);
                }
                if(roll[1]==5){
                    plyr[i].setScre(5);
                }
                if(roll[2]==5){
                    plyr[i].setScre(5);
                }
                if(roll[3]==5){
                    plyr[i].setScre(5);
                }
                if(roll[4]==5){
                    plyr[i].setScre(5);
                }
                break;
            }
            case 6:{
                cout<<"Scoring Sixes"<<endl;
                if(roll[0]==6){
                    plyr[i].setScre(6);
                }
                if(roll[1]==6){
                    plyr[i].setScre(6);
                }
                if(roll[2]==6){
                    plyr[i].setScre(6);
                }
                if(roll[3]==6){
                    plyr[i].setScre(6);
                }
                if(roll[4]==6){
                    plyr[i].setScre(6);
                }
                break;
            }
            case 7:{
                cout<<"Scoring 3 of a Kind"<<endl;
                
                //The Bubble Sort
                for(int i=0;i<nDice;i++){
                    for(int j=i+1;j<nDice;j++){
                        if(roll[i]>roll[j]){
                            int temp=roll[i];
                            roll[i]=roll[j];
                            roll[j]=temp;
                        }
                    }
                }
                
                int temp=roll[0];
                for(int count=0;count<nDice;count++){
                    roll[count]==temp?counter++:temp=roll[count];
                }
                if(counter==3){
                    for(int count=0;count<nDice;count++){
                        plyr[i].setScre(roll[count]);
                    }
                }
                break;
            }
            case 8:{
                cout<<"Scoring 4 of a Kind"<<endl;
                
                //The Bubble Sort
                for(int i=0;i<nDice;i++){
                    for(int j=i+1;j<nDice;j++){
                        if(roll[i]>roll[j]){
                            int temp=roll[i];
                            roll[i]=roll[j];
                            roll[j]=temp;
                        }
                    }
                }
                
                int temp=roll[0];
                for(int count=0;count<nDice;count++){
                    if(roll[count]==temp){
                        counter++;    
                    }else{
                        temp=roll[count];
                    }
                }
                if(counter==4){
                    for(int count=0;count<nDice;count++){
                        plyr[i].setScre(roll[count]);
                    }
                }
                break;
            }
            case 9:{
                cout<<"Scoring Full House"<<endl;
                if(roll[0]==roll[1]){
                    if(roll[2]==roll[3]==roll[4]){
                        plyr[i].setScre(25);
                    }
                }
                if(roll[0]==roll[1]==roll[2]){
                    if(roll[4]==roll[5]){
                        plyr[i].setScre(25);
                    }
                }
                break;
            }
            case 10:{
                cout<<"Scoring Small Straight"<<endl;
                
                //The Bubble Sort
                for(int i=0;i<nDice;i++){
                    for(int j=i+1;j<nDice;j++){
                        if(roll[i]>roll[j]){
                            int temp=roll[i];
                            roll[i]=roll[j];
                            roll[j]=temp;
                        }
                    }
                }
                
                //Scoring
                if((roll[4]-roll[3])==1){
                    if((roll[3]-roll[2]==1)){
                        if((roll[2]-roll[1]==1)){
                            plyr[i].setScre(30);
                        }
                    }
                }
                if((roll[3]-roll[2])==1){
                    if((roll[2]-roll[1]==1)){
                        if((roll[1]-roll[0]==1)){
                            plyr[i].setScre(30);
                        }
                    }
                }
                break;
            }
            case 11:{
                cout<<"Scoring Long Straight"<<endl;
                
                //The Bubble Sort
                for(int i=0;i<nDice;i++){
                    for(int j=i+1;j<nDice;j++){
                        if(roll[i]>roll[j]){
                            int temp=roll[i];
                            roll[i]=roll[j];
                            roll[j]=temp;
                        }
                    }
                }
                
                //Scoring
                if((roll[4]-roll[3])==1){
                    if((roll[3]-roll[2]==1)){
                        if((roll[2]-roll[1]==1)){
                            if((roll[1]==roll[0])==1){
                                plyr[i].setScre(40);
                            }
                        }
                    }
                }
                break;
            }
            case 12:{
                cout<<"Scoring Yahtzee"<<endl;
                if(roll[0]==roll[1]==roll[2]==roll[3]==roll[4]){
                    if(plyr[i].getYaht()>0){
                        plyr[i].setScre(100);
                    }else if(&plyr[i].getYaht==0){
                        plyr[i].setScre(50);
                        ++plyr[i];
                    } 
                }
                break;
            }
            case 13:{
                cout<<"Scoring Chance"<<endl;
                for(int count=0;count<nDice;count++){
                    plyr[i].setScre(roll[count]);
                }
                break;
            }
        }
        cout<<plyr[i].getName()<<"'s score this turn = "<<plyr[i].getScre();
        cout<<endl;
        cout<<"========================"<<endl;
    }
}
void sort(int a[],int nDice){
    //The Bubble Sort
    for(int i=0;i<nDice;i++){
        for(int j=i+1;j<nDice;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }   
}
