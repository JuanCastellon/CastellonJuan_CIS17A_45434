/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <string>  //String library
#include <cstring>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
void sort(string *,int);
int binSrch(string *,int, string);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=20;
    string array[SIZE] ={"Collins, Bill","Smith, Bart","Allen, Jim",
                         "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                         "Taylor, Terri","Johnson, Jill",
                         "Allison, Jeff","Looney, Joe","Wolfe, Bill",
                         "James, Jean","Weaver, Jim","Pore, Bob",
                         "Rutherford, Greg","Javens, Renee","Harrison, Rose",
                         "Setzer, Cathy","Pike, Gordon","Holland, Beth"};
    string value="Rutherford, Greg";//Searching for this in the array
    
    int pos;
    
    
    
    //Initialize Variables
    
    
    
    //Process Input/Output
    cout<<"Original Array of Names:"<<endl;
    cout<<"========================"<<endl;
    for(int count=0;count<SIZE;count++){
        cout<<array[count]<<endl;
    }
    cout<<"========================"<<endl;
    
    sort(array,SIZE);
    
    cout<<"Sorted Array of Names:"<<endl;
    cout<<"======================"<<endl;
    for(int count=0;count<SIZE;count++){
        cout<<array[count]<<endl;
    }
    cout<<"======================="<<endl;
    
    pos=binSrch(array,SIZE,value);
    
    cout<<"Position of '"<<value<<"' in array = "<<pos<<endl;
    
    //Display Results
    
    
    //Exit
    return 0;
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
