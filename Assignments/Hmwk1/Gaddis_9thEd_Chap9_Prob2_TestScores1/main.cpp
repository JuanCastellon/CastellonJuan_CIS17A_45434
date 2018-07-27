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
    int* scores=nullptr;//Dynamic memory pointer
    int count,exams;    //Counter variable and array
    int avg;            //Average test score
    
    
    //Initialize Variables
    cout<<"This program takes in any given number of tests and computes "
            "the average as well as return the inputted test scores in "
            "ascending order."<<endl;
    cout<<"How many tests are you going to input?"<<endl;
    cin>>exams;
    scores=new int[exams];//Dynamically allocating the number of exams
    
    //Process Input/Output
    for(count=0;count<exams;count++){
        cout<<"Input Test #"<<count+1<<endl;
        do{
        cin>>*(scores+count);
        }while(*(scores+count)<0);
    }
    
    for(int count=0;count<exams;count++){
        for(int cntr=count+1;cntr<exams;cntr++){
            if(scores[count]<scores[cntr]){
                int temp=scores[count];
                scores[count]=scores[cntr];
                scores[cntr]=temp;
            }
        }
    }
    
    for(int count=0;count<exams;count++){
        avg+=*(scores+count);
    }
    
    cout<<"Test Scores in Ascending Order:"<<endl;
    
    for(count=0;count<exams;count++){
        cout<<*(scores+count)<<endl;
    }
    
    cout<<"Average = "<<avg/exams<<"%"<<endl;
    
    //Deleting Dynamic Memory
    delete [] scores;
    scores=nullptr;
    
    //Exit
    return 0;
}
