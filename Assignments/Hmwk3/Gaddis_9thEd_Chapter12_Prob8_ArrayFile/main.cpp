/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
void arToFil(string, int *,int);
void filToAr(string, int *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Intro to the program
    cout<<"This program will write an array to a file and write data from a "
            "file to an array."<<endl;
    
    //Declare Variables
    string file1,file2;//Names of user inputted files
    int *ptr1=nullptr; //Pointer for outputting to a file
    int *ptr2=nullptr; //Pointer for to read in from a file
    int size;          //Size of the array
    
    //Initialize Variables
    cout<<"Please enter the size of the array."<<endl;
    cin>>size;
    
    ptr1=new int[size];
    ptr2=new int[size];
    
    //Filling ptr1
    for(int i=0;i<size;i++){
        cout<<"Please enter element #"<<i+1<<" of the array."<<endl;
        cin>>*(ptr1+i);
    }
    
    
    cout<<"Please enter the name of the input file."<<endl;
    cin>>file1;
    cout<<"Please enter the name of the output file."<<endl;
    cin>>file2;
    
    //Process Input/Output
    arToFil(file1,ptr1,size);
    filToAr(file2,ptr2,size);
    
    //Display Results
    cout<<"Array filled from file:"<<endl;
    for(int i=0;i<size;i++){
        cout<<*(ptr2+i)<<endl;
    }
    
    delete [] ptr1;
    delete [] ptr2;
    ptr1=ptr2=nullptr;
    
    //Exit
    return 0;
}

void arToFil(string file1, int *ptr1,int size){
    fstream outFile;
    int num;        //Variable for reading from a file
    outFile.open(file1, ios::out | ios::binary);
    //Filling the file
    for(int i=0;i<size;i++){
        outFile<<*(ptr1+i);
    }
    
    outFile.close();
}
void filToAr(string file2, int *ptr2,int size){
    fstream inFile;
    inFile.open(file2, ios::in | ios::binary);
    for(int i=0;i<size;i++){
        inFile>>*(ptr2+i);
    }
    inFile.close();
}