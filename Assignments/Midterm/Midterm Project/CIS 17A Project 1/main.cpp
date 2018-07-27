/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//Input/Output
#include <cstdlib> //Random Function
#include <ctime>   //Time function
#include <iomanip> //Formatting Library
#include <fstream> //File Library

using namespace std;

//User Libraries Here

//Essentially the player card. Keeps track of everything relating the player
//and runs parallel to the array of the dice structure.
struct Player{
    string name;  //Name of Player
    float score=0;//Score of Player
    int yah=0;    //Yahtzee counter for each player
    int chance=0; //Chance counter for each player
    int index=0;  //For determining who goes first
};

//This structure is for letting the player choose which die they want to roll
//again. The contents will be ported to another basic array to make the sorting
//and scoring easier.
struct Dice{
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
};

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
void first(Dice *,int,Player *,int);   //Determining who goes first
void turn(Dice *,int,Player *,int);    //Cycling through the turns
void sort(int [],int);                 //Sorting the dice for scoring
void winner(Dice *,int,Player *,int);  //Decides/Displays the winners
bool filOpen(fstream &,string);        //Checking file status

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    //Declare all Variables Here
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    
    //Array sizing stuff
    const int DICE=5;  //Number of dice thrown
    Player *plyr=nullptr;
    Dice *dice=nullptr;
    
    //Scoring and other game-related stuff
    char deci;                  //Decision to play the game or not
    int turns=1;                //Game lasts 20 turns, starts at 1
    int nPlyr;                  //How many players are determined to play
    float total,avgPt;          //Total points and average points per turn
    
    //c-string requirement
    char str[]="Hello there";
    
    //Declaring the files and such
    fstream plyCard;//Player Card for all info 
    fstream scores; //Individual scores and placements
    string str1="player card.dat";//Name of a file
    string str2="scores.dat";     //Name of a file
    bool status;    //Status of the file when opened
    char ch;        //For use with member function
    string line;
    
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    //End of Variable Declaring
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    
    //Checking to see if the files open okay
    plyCard.open(str1,ios::app|ios::binary|ios::out|ios::in);
    if(plyCard.fail()){
        cout<<"Error opening "<<str1<<endl;
    }
    status=filOpen(scores,str2);
    if(!status){
        cout<<"Error opening "<<str2<<endl;
    }
    
    //File Formatting
    scores<<fixed;
    scores<<setprecision(2);
    
    //Writing the c-string to the file
    for(int i=0;i<11;i++){
        ch=str[i];
        plyCard.put(ch);//Writing to the file
    }
    
    //Thanking the players for playing
    
    
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
            cin>>nPlyr;
        }
    }

    //Skips to next line
    cin.ignore();
    
    //Dynamically allocating array of structures
    plyr=new Player[nPlyr];
    dice=new Dice[nPlyr];
    
    //Input User Names
    for(int i=0;i<nPlyr;i++){
        cout<<"Please input player "<<i+1<<"'s name."<<endl;
        getline(cin,plyr[i].name);
    }
    
    //Determining and displaying who goes first
    first(dice,DICE,plyr,nPlyr);
    
    do{
        cout<<"==========="<<endl;
        cout<<"==Turn "<<turns<<"=="<<endl;
        cout<<"==========="<<endl;
        turn(dice,DICE,plyr,nPlyr);
        turns++;
    }while(turns<=20);
    
    //This will output the winners
    winner(dice,DICE,plyr,nPlyr);
    
    
    //Calculating some data about the game
    
    avgPt=total=0;//Average points per turn and total points scored in the game
    
    for(int i=0;i<nPlyr;i++){
        //Average points being tallied up
        avgPt+=plyr[i].score;
        //Total points being tallied up
        total+=plyr[i].score;
    }
    avgPt/=20;//Dividing by 20 for the number of turns to get the average
    
    //Sending average/total to scores file
    scores<<"Average points scored per turn = "<<avgPt<<endl;
    scores<<"Total points scored overall    = "<<total<<endl;
    
    //Outputting the player cards
    
    
    //Deallocating memory
    delete [] plyr;
    delete [] dice;
    
    //Closing files
    plyCard.close();
    scores.close();
    
    //Exit
    return 0;
}
void first(Dice *dice,int nDice,Player *plyr,int nPlyr){
    cout<<"Players will now roll to see who will go first."<<endl;
    cout<<"========================"<<endl;
    
    for(int i=0;i<nPlyr;i++){
        cout<<plyr[i].name<<" is rolling..."<<endl;
        dice[i].d1=rand()%6+1;
        dice[i].d2=rand()%6+1;
        dice[i].d3=rand()%6+1;
        dice[i].d4=rand()%6+1;
        dice[i].d5=rand()%6+1;
        plyr[i].index+=(dice[i].d1)+(dice[i].d2)+(dice[i].d3)+(dice[i].d4)
                +(dice[i].d5);
        cout<<plyr[i].name<<" rolled : "<<plyr[i].index<<endl;
        cout<<"========================"<<endl;
    }
    
    //Comparing indexes and sorting based on who got the highest scores
    for(int i=0;i<nPlyr;i++){
        for(int j=i+1;j<nPlyr;j++){
            if(plyr[i].index<plyr[j].index){
                Player temp=plyr[i];
                plyr[i]=plyr[j];
                plyr[j]=temp;
            }
        }
    }
    
    //Displaying who will go first
    for(int i=0;i<nPlyr;i++){
        cout<<plyr[i].name<<" will be player "<<i+1<<endl;
    }
}
void winner(Dice *dice,int nDice,Player *plyr,int nPlyr){
    
    //Sorts the winners
    for(int i=0;i<nPlyr;i++){
        for(int j=i+1;j<nPlyr;j++){
            if(plyr[i].score<plyr[j].score){
                Player temp=plyr[i];
                plyr[i]=plyr[j];
                plyr[j]=temp;
            }
        }
    }
    for(int i=0;i<nPlyr;i++){
        cout<<"#"<<i+1<<" = "<<plyr[i].name<<" with "<<plyr[i].score<<
                " points!"<<endl;
    }
}
void turn(Dice *dice,int nDice,Player *plyr,int nPlyr){
    int choice;  //Choice of scoring
    int pCount;  //Counter to see what player is currently up
    char deci;   //Decision to reroll any dice
    
    
    //Initializing Variables
    pCount=0;
    
    for(int i=0;i<nPlyr;i++){
        
        //Variables that need to be reset for each player every time
        const int SIZE=5;//Size of the array equivalent to the number of dice
        int roll[SIZE];  //Array for sorting/scoring. Makes things easier
        int rolls=3;     //Max amount of times you can reroll dice is 3
        int counter=0;   //Counter for scoring later on
        
        //Rolling the dice for the player
        dice[i].d1=rand()%6+1;
        dice[i].d2=rand()%6+1;
        dice[i].d3=rand()%6+1;
        dice[i].d4=rand()%6+1;
        dice[i].d5=rand()%6+1;
        
        //Copying the dice rolls into an array for easier sorting/scoring
        roll[0]=dice[pCount].d1;
        roll[1]=dice[pCount].d2;
        roll[2]=dice[pCount].d3;
        roll[3]=dice[pCount].d4;
        roll[4]=dice[pCount].d5;
        
        //Displaying the results
        cout<<plyr[i].name<<" rolled : "<<
                dice[i].d1<<" "<<
                dice[i].d2<<" "<<
                dice[i].d3<<" "<<
                dice[i].d4<<" "<<
                dice[i].d5<<" "<<endl;
        cout<<"Would you like to reroll your dice?"<<endl;
        cout<<"y/n : ";
        cin>>deci;
        
        //Input Validation
        while(deci!='y'&&deci!='n'){
            cout<<"Please input a valid response."<<endl;
            cin>>deci;
        }
        
        if(deci=='y'){
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
                    dice[i].d1=rand()%6+1;
                }
                if(choice==2){
                    dice[i].d2=rand()%6+1;
                }
                if(choice==3){
                    dice[i].d3=rand()%6+1;
                }
                if(choice==4){
                    dice[i].d4=rand()%6+1;
                }
                if(choice==5){
                    dice[i].d5=rand()%6+1;
                }
                
                //Display the dice after the change
                
                cout<<"========New Roll========= "<<endl;
                cout<<plyr[i].name<<" rolled : "<<
                dice[i].d1<<" "<<
                dice[i].d2<<" "<<
                dice[i].d3<<" "<<
                dice[i].d4<<" "<<
                dice[i].d5<<" "<<endl;
                
                rolls--;
                cout<<"Rerolls left : "<<rolls<<endl;
                
                
                if(rolls!=0){
                    cout<<"Would you like to reroll again?"<<endl;
                    cout<<"y/n : ";

                    cin>>deci;
                    cout<<endl;
                }
                
                
            }while(deci=='y'&&rolls!=0);
        }
        
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
        while(plyr[i].chance>0){
            cout<<"You have already chosen the Chance category. Please "
                    "select another category."<<endl;
            cin>>choice;
        }
        
        //Checking if Chance category was selected
        if(choice==13){
            plyr[i].chance=1;
        }
        
        //Scoring the rolls now
        switch(choice){
            case 1:{
                cout<<"Scoring Aces"<<endl;
                if(dice[i].d1==1){
                    plyr[i].score+=1;
                }
                if(dice[i].d2==1){
                    plyr[i].score+=1;
                }
                if(dice[i].d3==1){
                    plyr[i].score+=1;
                }
                if(dice[i].d4==1){
                    plyr[i].score+=1;
                }
                if(dice[i].d5==1){
                    plyr[i].score+=1;
                }
                
                break;
            }
            case 2:{
                cout<<"Scoring Twos"<<endl;
                if(dice[i].d1==2){
                    plyr[i].score+=2;
                }
                if(dice[i].d2==2){
                    plyr[i].score+=2;
                }
                if(dice[i].d3==2){
                    plyr[i].score+=2;
                }
                if(dice[i].d4==2){
                    plyr[i].score+=2;
                }
                if(dice[i].d5==2){
                    plyr[i].score+=2;
                }
                break;
            }
            case 3:{
                cout<<"Scoring Threes"<<endl;
                if(dice[i].d1==3){
                    plyr[i].score+=3;
                }
                if(dice[i].d2==3){
                    plyr[i].score+=3;
                }
                if(dice[i].d3==3){
                    plyr[i].score+=3;
                }
                if(dice[i].d4==3){
                    plyr[i].score+=3;
                }
                if(dice[i].d5==3){
                    plyr[i].score+=3;
                }
                break;
            }
            case 4:{
                cout<<"Scoring Fours"<<endl;
                if(dice[i].d1==4){
                    plyr[i].score+=4;
                }
                if(dice[i].d2==4){
                    plyr[i].score+=4;
                }
                if(dice[i].d3==4){
                    plyr[i].score+=4;
                }
                if(dice[i].d4==4){
                    plyr[i].score+=4;
                }
                if(dice[i].d5==4){
                    plyr[i].score+=4;
                }
                break;
            }
            case 5:{
                cout<<"Scoring Fives"<<endl;
                if(dice[i].d1==5){
                    plyr[i].score+=5;
                }
                if(dice[i].d2==5){
                    plyr[i].score+=5;
                }
                if(dice[i].d3==5){
                    plyr[i].score+=5;
                }
                if(dice[i].d4==5){
                    plyr[i].score+=5;
                }
                if(dice[i].d5==5){
                    plyr[i].score+=5;
                }
                break;
            }
            case 6:{
                cout<<"Scoring Sixes"<<endl;
                if(dice[i].d1==6){
                    plyr[i].score+=6;
                }
                if(dice[i].d2==6){
                    plyr[i].score+=6;
                }
                if(dice[i].d3==6){
                    plyr[i].score+=6;
                }
                if(dice[i].d4==6){
                    plyr[i].score+=6;
                }
                if(dice[i].d5==6){
                    plyr[i].score+=6;
                }
                break;
            }
            case 7:{
                cout<<"Scoring 3 of a Kind"<<endl;
                sort(roll,nDice);
                int temp=roll[0];
                for(int count=0;count<nDice;count++){
                    roll[count]==temp?counter++:temp=roll[count];
                }
                if(counter==3){
                    for(int count=0;count<nDice;count++){
                        plyr[i].score+=roll[count];
                    }
                }
                break;
            }
            case 8:{
                cout<<"Scoring 4 of a Kind"<<endl;
                sort(roll,nDice);
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
                        plyr[i].score+=roll[count];
                    }
                }
                break;
            }
            case 9:{
                cout<<"Scoring Full House"<<endl;
                if(roll[0]==roll[1]){
                    if(roll[2]==roll[3]==roll[4]){
                        plyr[i].score=25;
                    }
                }
                if(roll[0]==roll[1]==roll[2]){
                    if(roll[4]==roll[5]){
                        plyr[i].score+=25;
                    }
                }
                break;
            }
            case 10:{
                cout<<"Scoring Small Straight"<<endl;
                sort(roll,nDice);
                if((roll[4]-roll[3])==1){
                    if((roll[3]-roll[2]==1)){
                        if((roll[2]-roll[1]==1)){
                            plyr[i].score+=30;
                        }
                    }
                }
                if((roll[3]-roll[2])==1){
                    if((roll[2]-roll[1]==1)){
                        if((roll[1]-roll[0]==1)){
                            plyr[i].score+=30;
                        }
                    }
                }
                break;
            }
            case 11:{
                cout<<"Scoring Long Straight"<<endl;
                sort(roll,nDice);
                if((roll[4]-roll[3])==1){
                    if((roll[3]-roll[2]==1)){
                        if((roll[2]-roll[1]==1)){
                            if((roll[1]==roll[0])==1){
                                plyr[i].score+=40;
                            }
                        }
                    }
                }
                break;
            }
            case 12:{
                cout<<"Scoring Yahtzee"<<endl;
                if(roll[0]==roll[1]==roll[2]==roll[3]==roll[4]){
                    if(plyr[i].yah>0){
                        plyr[i].score+=100;
                    }else if(plyr[i].yah==0){
                        plyr[i].score+=50;   
                    } 
                }
                break;
            }
            case 13:{
                cout<<"Scoring Chance"<<endl;
                for(int count=0;count<nDice;count++){
                    plyr[i].score+=roll[count];
                }
                break;
            }
        }
        
        cout<<plyr[i].name<<"'s score this turn = "<<plyr[i].score<<endl;
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
bool filOpen(fstream &file,string name){
    bool status;
    file.open(name,ios::binary|ios::out);
    if(file.fail()){
        status=false;
    }
    else{
        status=true;
    }
    return status;
}