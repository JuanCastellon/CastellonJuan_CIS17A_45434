/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose: Number analysis
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here


//Program Execution Begins Here
int main(int argc, char** argv) {
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
    
    //Exit
    return 0;
}

