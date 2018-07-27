/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on:
 * Purpose: Driver program with two constructs
*/

//System Libraries Here
#include <iostream>//cin,cout

using namespace std;

//User Libraries Here
class Inventory{
    public:
        //Constructor #1 : Default Constructor
        Inventory(){
            itemNum=0;
            quan=0;
            cost=0;
            totCost=0;
        }
        //Constructor #2 : Inputting arguments
        Inventory(int itNm,int quantit,float cst){
            itemNum=itNm;
            quan=quantit;
            cost=cst;
            totCost=quan*cost;
        }
        
        //Setter Functions
        void setItNm(int);
        void setQuan(int);
        void setCost(float);
        void setTotC(float);
        
        //Getter Functions
        int getItNm();
        int setQuan();
        float setCost();
        float setTotC();
        
    private:
        int itemNum;
        int quan;
        float cost;
        float totCost;
};


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Intro to the program
    cout<<"This is a just a stub program. The code is within the files of the "
            "program."<<endl;
    cout<<"Please refer to the folder of the program."<<endl;
    
    //Declare Variables
    int itNm;
    int quantit;
    float cst;
    float totCst;
    
    //Initialize Variables
    
    
    //Process Input/Output
    
    
    //Display Results
    
    
    //Exit
    return 0;
}
void Inventory::setItNm(int num){
    itemNum=num;
}
void Inventory::setQuan(int num){
    quan=num;
}
void Inventory::setCost(float num){
    cost=num;
}
void Inventory::setTotC(float num){
    totCost=num;
}
int Inventory::getItNm(){
    return itemNum;
}
int Inventory::setQuan(){
    return quan;
}
float Inventory::setCost(){
    return cost;
}

float Inventory::setTotC(){
    return cost*quan;
}
            