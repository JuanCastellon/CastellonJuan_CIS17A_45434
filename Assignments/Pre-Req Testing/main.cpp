/* 
 * File:   main.cpp
 * Author: 
 * Created on 
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

////////////////////////////////Function Prototypes Here//////////////////////////////////////////////
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order
void strrep(char[],const char[],const char[]);

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    
//Declare all Variables Here
    const int ROW=30;//Only 20 required
    char array[ROW][COLMAX];//Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order 
    
    //Input the new sort order then sort
    
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    
    
//////////////Else output different size///////////////////////////////////////////
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }

//Exit
    return 0;
}

int read(char array[][COLMAX], int &rowDet){
    int colDet = 0;
    cin.ignore(1024, '\n');
    for (int count=0;count<rowDet;count++) {
        cin.getline(array[count], COLMAX);
        int length=strlen(array[count]);
        if (length>colDet){
         colDet=length;
        }
    }
    return colDet;
}

void sort(char array[][COLMAX], int rowIn, int, const char replace[], const char with[]) { //Sort by row
    char temp[COLMAX];
    for(int count=0;count<rowIn-1;count++) {
        int min=count;
        for(int cntr=count+1;cntr<rowIn;cntr++) {
            if (strcmp(array[min], array[cntr], replace, with)>0) {
                min=cntr;
        }
    }
    if (min!=count) {
            strcpy(temp, array[count]);
            strcpy(array[count], array[min]);
            strcpy(array[min], temp);
    }
}
}

void print(const char array[][COLMAX], int rowIn, int){
    for (int count=0;count<rowIn;count++){
        cout<<array[count]<<endl;
    }
}

int strcmp(char first[], char second[], const char replace[], const char with[]) { //Replace sort order
    char firCopy[COLMAX];
       for (int count=0;firCopy[count]=='\0';count++) {
        firCopy[count] = first[count];
    }
    char secCopy[COLMAX];
    for (int count=0;secCopy[count]=='\0';count++) {
        secCopy[count] = second[count];
        
    }
    strrep(firCopy, replace, with);
    strrep(secCopy, replace, with);
    return strcmp(firCopy, secCopy);
}

void strrep(char source[], const char replace[], const char with[]) {
   int sourLen = strlen(source);
   int repLen = strlen(replace);
   for (int count=0;count<sourLen;count++) {
        for (int cntr=0;cntr<repLen&&source[count]==replace[cntr];cntr++) {
            if (source[count]==replace[cntr]) {
                source[count]=with[cntr];

            }
}
    }
}