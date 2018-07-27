/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on:
 * Purpose: Retail Item Class program, outputs the information of the items
*/

//System Libraries Here
#include <iostream>//cin,cout

using namespace std;

//User Libraries Here
class Retail{
    public:
        //Constructor
        Retail(string, int, float);
        
        //Setter functions
        void setDesc(string);
        void setUnit(int);
        void setPric(float);
        
        //Getter functions
        string getDesc();
        int getUnit();
        float getPric();
        
    private:
        string desc;
        int units;
        float price;
        
};

//Constructor
Retail::Retail(string a,int b, float c){
    desc=a;
    units=b;
    price=c;
}

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Intro to the program
    cout<<"This program will store and output the data of an inventory of "
            "jackets, jeans, and shirts."<<endl;
    
    //Variables for initialization
    string a="temp";
    int b=0;
    float c=0.0f;
    
    //Class objects and initializing them to default values
    Retail itm1(a,b,c);
    Retail itm2(a,b,c);
    Retail itm3(a,b,c);
    
    //Initialize Objects
    itm1.setDesc("Jacket");
    itm2.setDesc("Designer Jeans");
    itm3.setDesc("Shirt");
    
    itm1.setUnit(12);
    itm2.setUnit(40);
    itm3.setUnit(20);
    
    itm1.setPric(59.95);
    itm2.setPric(34.95);
    itm3.setPric(24.95);
    
    //Process Input/Output
    
    
    //Display Results
    cout<<"=======Item 1:======="<<endl;
    cout<<"Description   : "<<itm1.getDesc()<<endl;
    cout<<"Units on Hand : "<<itm1.getUnit()<<endl;
    cout<<"Price of Item : $"<<itm1.getPric()<<endl;
    
    cout<<"=======Item 2:======="<<endl;
    cout<<"Description   : "<<itm2.getDesc()<<endl;
    cout<<"Units on Hand : "<<itm2.getUnit()<<endl;
    cout<<"Price of Item : $"<<itm2.getPric()<<endl;
    
    cout<<"=======Item 3:======="<<endl;
    cout<<"Description   : "<<itm3.getDesc()<<endl;
    cout<<"Units on Hand : "<<itm3.getUnit()<<endl;
    cout<<"Price of Item : $"<<itm3.getPric()<<endl;
          
    
    //Exit
    return 0;
}
//Getter Functions
void Retail::setDesc(string d){
    desc=d;
}
void Retail::setUnit(int u){
    units=u;
}
void Retail::setPric(float p){
    price=p;
}
//Setter Functions
string Retail::getDesc(){
    return desc;
}
int Retail::getUnit(){
    return units;
}
float Retail::getPric(){
    return price;
}