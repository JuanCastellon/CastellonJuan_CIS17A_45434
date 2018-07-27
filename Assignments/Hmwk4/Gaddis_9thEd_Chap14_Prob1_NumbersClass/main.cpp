/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on:
 * Purpose: Design a class (Numbers) that can be used to translate whole
 * dollar amounts in the range of 0-9999
*/

//System Libraries Here
#include <iostream>//cin,cout

using namespace std;

//User Libraries Here
class Numbers{
    public:
        Numbers(int);
        void print();
        
    private:
        int num;
};
//Constructor with input validation
Numbers::Numbers(int n){
    while(n>9999||n<0){
        cout<<"Invalid integer, please reinput."<<endl;
        cin>>n;
    }
    num=n;
}

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n;
    
    
    //Initialize Variables
    cout<<"Please input a number from 0-9999 : ";
    cin>>n;
    Numbers num(n);
    
    //Process Input/Output
    
    
    //Display Results
    num.print();
    
    //Exit
    return 0;
}
void Numbers::print(){
    int n;
    string less20[20]={"Zero","One","Two","Three","Four","Five",
                       "Six","Seven","Eight","Nine","Ten","Eleven",
                       "Twelve","Thirteen","Fourteen","Fifteen",
                       "Sixteen","Seventeen","Eighteen","Nineteen"};
                                  
    string tens[10]={"Zero","Ten","Twenty","Thirty","Forty","Fifty",
                                "Sixty","Seventy","Eighty","Ninety"};
    string hund="Hundred";
    string thou="Thousand";
    
    
    
    //Process for outputting word
    n=num/1000;
    cout<<less20[n]<<" "<<thou<<" ";
    n=num/100;
    num%=1000;
    if(n>0){
        cout<<less20[n]<<" "<<hund<<" ";
    }
    num%=100;
    if(num>20){
        n=num/10;
        cout<<tens[n]<<" ";
    }else if(num>=10){
        cout<<less20[num];
        exit(0);
    }
    num%=10;
    if(num>0){
        cout<<less20[num]<<endl;
    }
}