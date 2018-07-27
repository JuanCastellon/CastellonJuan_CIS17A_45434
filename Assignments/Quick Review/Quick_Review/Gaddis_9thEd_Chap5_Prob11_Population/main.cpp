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

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
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
    
    //Exit
    return 0;
}

