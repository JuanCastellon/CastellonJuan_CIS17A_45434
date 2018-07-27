/* 
 * File:   main.cpp
 * Author: Juan
 * Created on May 27th, 2018, 11:30 PM
 * Purpose: Quick Review Menu
 */

//System Libraries Here
#include <iostream>//I/O 
#include <iomanip>// Format
#include <cstdlib>// Random Library
#include <ctime>//   Time Library
#include <cmath>//   Power
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

float const YPD=98.93f;//Yen Per Dollar
float const EUPD=.74f;     //Euros Per Dollar

//Function Prototypes Here
float celsius(float);
void sort(string *,int);
int binSrch(string *,int, string);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int choice;
    do{
    cout<<"This is a menu for accessing all Assignment 3 projects."<<endl;
    cout<<"Press 1 for Gaddis Chapter 3 Problem 12"<<endl;
    cout<<"Press 2 for Gaddis Chapter 3 Problem 13"<<endl;
    cout<<"Press 3 for Gaddis Chapter 4 Problem 10"<<endl;
    cout<<"Press 4 for Gaddis Chapter 5 Problem 11"<<endl;
    cout<<"Press 5 for Gaddis Chapter 6 Problem 7"<<endl;
    cout<<"Press 6 for Gaddis Chapter 7 Problem 6"<<endl;
    cout<<"Press 7 for Gaddis Chapter 8 Problem 7"<<endl;
 
    cin>>choice;
    //Input or initialize values Here
    
    if (choice>=1 && choice<=10){
        switch(choice){
            case 1:{
                //Declare Variables
                float cel,fah;

                //Initialize Variables
                cout<<"This program can convert Celsius temperatures to Fahrenheit "
                        "temperatures."<<endl;
                cout<<"Please input the temperature in Celsius."<<endl;
                cin>>cel;

                //Process Input/Output
                fah=((9.0f/5.0f)*cel)+32;

                //Display Results
                cout<<"Fahrenheit temperature = "<<fah<<endl;
                break;
            }
            case 2:{
                //Declare Variables
                float dol;//Dollar amount input
                float yen,euro;//Yen and Euro amounts converted from dollars

                //Initialize Variables
                cout<<"This program converts dollars to yen and euros."<<endl;
                cout<<"Please input the dollar amount you would like to convert."<<endl;
                cin>>dol;

                //Process Input/Output
                yen=YPD*dol;
                euro=EUPD*dol;

                //Display Results
                cout<<"Dollars : "<<dol<<" ----> Yen : "<<yen<<endl;
                cout<<"Dollars : "<<dol<<" ----> Euro : "<<euro<<endl;
                break;
            }
            case 3:{
                //Declare Variables
                int mon,year;//Inputted month and year
                bool leap;//Determine if the year is a leap year

                //Initialize Variables
                cout<<"This program will detect the number of days in a given month and "
                        "year."<<endl;
                cout<<"Please input a number 1-12 for the month."<<endl;
                cin>>mon;
                cout<<"Please input a number for the year."<<endl;
                cin>>year;

                leap==false;

                //Process Input/Output
                if(year%100==0){
                    if(year%400==0){
                        leap=true;
                    }
                }

                if(year%100==0){
                    leap=true;
                }

                //Display Results
                switch(mon){
                    case 1:
                        cout<<"Days in month = 31"<<endl;
                        break;

                    case 2:
                        if(leap==true){
                            cout<<"Days in month = 29"<<endl;
                            break;
                        }
                        else{
                            cout<<"Days in month = 28"<<endl;
                            break;
                        }

                    case 3:
                        cout<<"Days in month = 31"<<endl;
                        break;

                    case 4:
                        cout<<"Days in month = 30"<<endl;
                        break;

                    case 5:
                        cout<<"Days in month = 31"<<endl;
                        break;

                    case 6:
                        cout<<"Days in month = 30"<<endl;
                        break;

                    case 7:
                        cout<<"Days in month = 31"<<endl;
                        break;

                    case 8:
                        cout<<"Days in month = 31"<<endl;
                        break;

                    case 9:
                        cout<<"Days in month = 30"<<endl;
                        break;

                    case 10:
                        cout<<"Days in month = 31"<<endl;
                        break;

                    case 11:
                        cout<<"Days in month = 30"<<endl;
                        break;

                    case 12:
                        cout<<"Days in month = 31"<<endl;
                        break;
                }
                break;
            }
            case 4:{
                //Declare Variables
                int pop,totPop,year;//Starting pop, final pop, year they grow for
                float rate;//Growth Rate

                //Initialize Variables
                cout<<"This program can calculate the population of an organism "
                        "by inputting the starting population, growth rate, and number "
                        "of year they'll grow for."<<endl;
                cout<<"Please input the starting population, growth rate, and number of "
                        "year they'll grow for."<<endl;
                do{
                    cin>>pop;
                    if(pop<2){
                        cout<<"Invalid starting population. Reinput 2 or more."<<endl;
                    }
                }while(pop<2);
                do{
                    cin>>rate;
                    if(rate<1){
                        cout<<"Invalid growth rate. Reinput growth rate."<<endl;
                    }
                }while(rate<1);
                do{
                    cin>>year;
                    if(year<1){
                        cout<<"Invalid numbers of year. Reinput years."<<endl;
                    }
                }while(year<1);


                //Process Input/Output
                totPop=pop;

                cout<<"Starting population = "<<totPop<<endl;

                for(int count=1;count<year+1;count++){
                    totPop+=(totPop*rate);
                    cout<<"Year "<<count<<" Population = "<<totPop<<endl;
                }

                //Display Results
                cout<<"Total Population after "<<year<<" year = "<<totPop<<endl;
                break;
            }
            case 5:{
                //Declare Variables
                float cels=0;

                //Display Outputs
                cout<<"This program will calculate the temperature in degrees Celsius "
                        "from 0-20 degrees Fahrenheit"<<endl;
                cout<<"Fahrenheit    Celsius"<<endl;

                //Loop for displaying conversion
                for(float fahren=0;fahren<=20;fahren++){
                    cels = celsius(fahren);
                    cout<<setw(5)<<fahren<<setw(16)<<cels<<endl;
                }

                //Exit Program!
                return 0;
                break;
            }
            case 6:{
                //Declare Variables
                ifstream inputFile;
                inputFile.open("Numbers.dat");
                int SIZE=10;
                int array[SIZE];

                //Initialize Variables


                for(int count=0;count<SIZE;count++){
                    inputFile>>array[count];
                }

                for(int count=0;count<SIZE;count++){
                    cout<<array[count]<<endl;
                }
                //Process Input/Output


                //Display Results

                //Close File

                inputFile.close();
                break;
            }
            case 7:{
                //Declare Variables
                int SIZE=10;
                int array[SIZE];
                ifstream inputFile;
                inputFile.open("Numbers.dat");
                int hi,lo;
                float avg,tot;

                //Initialize Variables


                for(int count=0;count<SIZE;count++){
                    inputFile>>array[count];
                }

                //Process Input/Output
                cout<<"Outputting unsorted array :"<<endl;
                for(int count=0;count<SIZE;count++){
                    cout<<array[count]<<endl;
                }
                cout<<"==========================="<<endl;
                for(int count=0;count<SIZE-1;count++){
                    for(int place=count+1;place<SIZE;place++){
                        if(array[count]>array[place]){
                            int temp=array[count];
                            array[count]=array[place];
                            array[place]=temp;
                        }
                    }
                }
                cout<<"Outputting sorted array   :"<<endl;
                for(int count=0;count<SIZE;count++){
                    cout<<array[count]<<endl;
                }

                for(int count=0;count<SIZE;count++){
                    tot+=array[count];
                }
                avg=tot/10;

                //Display Results
                cout<<"Highest Number : "<<array[9]<<endl;
                cout<<"Lowest Number  : "<<array[0]<<endl;
                cout<<"Total Numbers in the array: "<<SIZE<<endl;
                cout<<"Average of the numbers : "<<avg<<endl;


                //Close File
                inputFile.close();
                break;
            }
        }
    }else{
        cout<<"Exiting menu"<<endl;
    }
    cout<<"Repeat menu? Press 0"<<endl;
    cin>>choice;
    }while(choice==0);
  
    //Exit
    return 0;
}
float celsius(float fahren){
    return 5*(fahren-32)/9;
}

void sort(string a[], int size){
    int min;
    string minNm;
    for(int count=0;count<size;count++){
        min=count;
        minNm=a[count];
        for(int cntr=count+1;cntr<size;cntr++){
            if(a[cntr]<minNm){
                minNm=a[cntr];
                min=cntr;
            }
        }
        a[min]=a[count];
        a[count]=minNm;
    }
}


binSrch(string a[], int size, string value){
    int first=0,
        last=size-1,
        middle,
        pos=-1;
    bool found=false;
    while(!found&&first<=last){
        middle=(first+last)/2;
        if(a[middle]==value){
            found=true;
            pos=middle;
        }else if(a[middle]>value){
            last=middle-1;
        }else
            first=middle+1;
    }
    return pos;
}
