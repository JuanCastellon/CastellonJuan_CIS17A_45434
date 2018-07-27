/* 
 * File:   main.cpp
 * Author: Juan
 * Created on May 27th, 2018, 11:30 PM
 * Purpose: Assignment 6 Menu
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

//Function Prototypes Here
void inpDona1(int *,int);
void bubSor1(int *,int);
void shoArry1(const int *,int);
void shArPtr1(int *,int);
void inpDona2(int *,int);
void bubSor2(int *,int);
void shoArry2(const int *,int);
void shArPtr2(int *,int);
void bubSor(int *,int);
int finMedi(int *,int);
void reverse(int *,int *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int choice;
    do{
    cout<<"This is a menu for accessing all Homework 1 projects."<<endl;
    cout<<"Press 1 for Gaddis Chapter 9 Problem 2"<<endl;
    cout<<"Press 2 for Gaddis Chapter 9 Problem 6"<<endl;
    cout<<"Press 3 for Gaddis Chapter 9 Problem 7"<<endl;
    cout<<"Press 4 for Gaddis Chapter 9 Problem 9"<<endl;
    cout<<"Press 5 for Gaddis Chapter 9 Problem 10"<<endl;
    cout<<"Press any other key to exit the menu."<<endl;
    cout<<"---------------------------------------------------------"<<endl;
 
    cin>>choice;
    //Input or initialize values Here
    
    if (choice>=1 && choice<=5){
        switch(choice){
            case 1:{
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
                break;
            }
            case 2:{
                //Declare Variables
                int numDona;
                int *dona=nullptr;
                cout<<"This program organizes the donations inputted by the user in "
                        "ascending order."<<endl;
                cout<<"Input number of donations to be inputted."<<endl;
                cin>>numDona;
                dona=new int[numDona];

                //Input donation values
                inpDona1(dona,numDona);

                // An array of pointers to int.
                int *arrPtr=nullptr;
                arrPtr=new int[numDona];

                // Each element of arrPtr is a pointer to int. Make each
                // element point to an element in the donations array.
                for (int count = 0; count <numDona; count++){
                    *(arrPtr+count) = *(dona+count); 
                }


                //Sort the elements of the array of pointers
                bubSor1(arrPtr,numDona);

                // Display the donations using the array of pointers. This
                // will display them in sorted order.
                cout << "The donations, sorted in ascending order are: "<<endl;
                shArPtr1(arrPtr,numDona); 


                // Display the donations in their original order.
                cout << "The donations, in their original order are: "<<endl;
                shoArry1(dona,numDona); 

                delete [] dona;
                delete [] arrPtr;
                dona=arrPtr=nullptr;
                break;
            }
            case 3:{
                //Declare Variables
                int numDona;
                int *dona=nullptr;
                cout<<"This program organizes the donations inputted by the user in "
                        "descending order."<<endl;
                cout<<"Input number of donations to be inputted."<<endl;
                cin>>numDona;
                dona=new int[numDona];

                //Input donation values
                inpDona2(dona,numDona);

                // An array of pointers to int.
                int *arrPtr=nullptr;
                arrPtr=new int[numDona];

                // Each element of arrPtr is a pointer to int. Make each
                // element point to an element in the donations array.
                for (int count = 0; count <numDona; count++){
                *(arrPtr+count) = *(dona+count); 
                }


                //Sort the elements of the array of pointers
                bubSor2(arrPtr,numDona);

                // Display the donations using the array of pointers. This
                // will display them in sorted order.
                cout << "The donations, sorted in descending order are: "<<endl;
                shArPtr2(arrPtr,numDona); 


                // Display the donations in their original order.
                cout << "The donations, in their original order are: "<<endl;
                shoArry2(dona,numDona); 

                delete [] dona;
                delete [] arrPtr;
                dona=arrPtr=nullptr;
                break;
            }
            case 4:{
                //Formatting
                cout<<showpoint<<setprecision(2)<<showpoint;

                //Declare Variables
                int size,median;//Size of the array and the mode

                cout<<"This program will the determine the mode of a dynamically allocated"
                        " array."<<endl;

                cout<<"Enter size of the array"<<endl;
                cin>>size;
                int *array=nullptr;
                array=new int[size];

                //Initialize Variables
                for(int i=0;i<size;i++){
                    cout<<"Input Value #"<<i+1<<" of the Array."<<endl;
                    cin>>*(array+i);
                }

                //Process Input/Output
                bubSor(array,size);

                median=finMedi(array,size);

                //Display Results
                cout<<"Median of the Array = "<<median<<endl;

                delete [] array;
                array=nullptr;
                break;
            }
            case 5:{
                //Declare Variables
                int *array=nullptr;
                int *newAry=nullptr;
                int size;

                cout<<"This array will take an array, reverse the order, and return a "
                        "pointer."<<endl;
                cout<<"Input the size of the array."<<endl;
                cin>>size;


                //Initialize Variables
                array=new int[size];
                newAry=new int[size];
                for(int i=0;i<size;i++){
                    cout<<"Input Element #"<<i+1<<" of the Array"<<endl;
                    cin>>*(array+i);
                }

                //Process Input/Output
                reverse(array,newAry,size);


                //Display Results
                cout<<"Reversed Array:"<<endl;
                for(int i=0;i<size;i++){
                    cout<<*(newAry+i)<<endl;
                }
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
void inpDona1(int *a,int size){
    for(int count=0;count<size;count++){
        cout<<"Input Donation #"<<count+1<<endl;
        cin>>*(a+count);
    }
}
void bubSor1(int *a,int size){
    for (int i=0;i<size; i++){
        for (int j=i+1;j<size;j++){
            if (*(a+i)>*(a+j)){
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
}
void shoArry1(const int *a,int size){
    for (int count=0;count<size; count++){
        cout << *(a+count) << " ";
        cout << endl; 
    }
}
void shArPtr1(int *a,int size){
    for (int count=0;count<size;count++){
        cout<<*(a+count) << " ";
        cout<<endl;
    }
}
void inpDona2(int *a,int size){
    for(int count=0;count<size;count++){
        cout<<"Input Donation #"<<count+1<<endl;
        cin>>*(a+count);
    }
}
void bubSor2(int *a,int size){
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
void shoArry2(const int a[],int size){
    for (int count=0;count<size; count++){
        cout << a[count] << " ";
        cout << endl; 
    }
}
void shArPtr2(int *a,int size){
    for (int count=0;count<size;count++){
        cout<<*(a+count) << " ";
        cout<<endl;
    }
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
int finMedi(int *a,int size){
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
void reverse(int *a,int *n,int size){
    for (int i=0;i<size;i++){
        *(n+i) = *(a+i); 
    }
    
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            int temp=*(n+i);
            *(n+i)=*(n+j);
            *(n+j)=temp;
        }
            
    }
}