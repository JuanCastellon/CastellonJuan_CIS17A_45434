/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //Formatting Output
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
float median(int *,int);
float mode(int *,int);
float mean(int *,int);
void bubSor(int *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Program Introduction
    cout<<"This program can calculate the mean, median, and mode of a set "
            "of data input by the user."<<endl;
    
    //Declare Variables
    int *array;
    int size;
    float meen,med,mde;
    cout<<"Input the size of the set of data."<<endl;
    cin>>size;
    array=new int[size];
    
    //Initialize Variables
    for(int i=0;i<size;i++){
        cout<<"Please enter element #"<<i+1<<" of the set of data."<<endl;
        cin>>*(array+i);
    }
    
    //Setting these to 0 just in case
    meen=med=mde=0;
    
    //Process Input/Output
    bubSor(array,size);
    
    meen=mean(array,size);
    med=median(array,size);
    
    
    //Display Results
    cout<<"Mean   = "<<meen<<endl;
    cout<<"Median = "<<med<<endl;
    mde=mode(array,size);
    
    //Delete Dynamic Memory
    delete [] array;
    array=nullptr;

    
    //Exit
    return 0;
}
float mean(int *a,int size){
    float sum=0;
    float average=0;
    for(int i=0;i<size;i++){
        sum+=*(a+i);
    }
    average=sum/size;
    return average;
}

float median(int *a,int size){
    int even,odd;//variables for choosing the middle value of a variable
    int median;
    even=odd=median=0;
    //Test to see if even or odd
    if(size%2==0){//even
        even=(size/2);
        even+=(size/2)+1;
        median=(even/2);
    }
    else{//odd
        odd=(size-1)/2;
        median=*(a+odd);
    }
    return median;
}

float mode(int *a,int size){
    int numMode;//Number of modes
    int freq;//Frequency of the current number that is being searched
    int numFreq;//Number in question
    int maxFreq;//Maximum number of frequencies
    int *index=nullptr;
    
    //Allocating the most general size of the mode array
    int *mde;
    mde=new int[size];
    
    freq=1;//Element in array always occurs at least once
    maxFreq=1;//Element in array always occurs at least once
    numMode=0;//Assuming there are no modes to start off, may go up
    
    for(int i=0;i<size;i++){
        numFreq=*(a+i);
        for(int j=0;j<size;j++){
            if(numFreq==*(a+j)&&i!=j){
                freq++;//Incrementing the frequency
            }
            if(freq>maxFreq){
                maxFreq=freq;
            }
            
            
        }
        //Storing the frequency of the current number
        *(mde+i)=freq;
        
        if(freq==maxFreq&&*(mde+i)>1&&*(a+i)!=*(a+i+1)){
                numMode++;
            }
        
        freq=1;//Resetting the frequency back to 0 
        
        }
    
    //Finding the numbers that are modes
    cout<<"Number of Modes = "<<numMode<<endl;
    
    //Dynamic memory for tracking the modes
    index=new int[numMode];
    
    for(int i=0;i<size;i++){
        if(*(mde+i)>1&&*(mde+i)==maxFreq&&*(a+i)!=*(a+i+1)){
            *(index+i)=*(a+i);
            cout<<"Mode = "<<*(index+i)<<endl;
        }
    }
    
    //Outputting the elements of the array and their frequency
    cout<<"Element of Array ===== Frequency of Element"<<endl;
    for(int i=0;i<size;i++){
        cout<<setw(9)<<*(a+i)<<setw(25)<<*(mde+i)<<endl;
    }
    
    //Deleting Memory
    delete [] index;
    index=nullptr;
    
}

void bubSor(int *a,int size){
    for (int i=0;i<size; i++){
        for (int j=i+1;j<size;j++){
            if (*(a+i)<*(a+j)){
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
}