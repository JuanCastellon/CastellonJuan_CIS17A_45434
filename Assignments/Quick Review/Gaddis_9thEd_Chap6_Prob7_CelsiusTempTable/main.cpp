/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //Formatting
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
float celsius(float);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float cels=0;
    
    //Display Outputs
    cout<<"This program will calculate the temperature in degrees Celsius "
            "from 0-20 degrees Fahrenheit"<<endl;
    cout<<"Fahrenheit    Celsius"<<endl;
    
    //Loop for displaying conversion
    for(float fahren=0;fahren<=20;fahren++){
        cels = celsius(fahren);
        cout<<setw(5)<<fahren<<setw(16)<<cels<<endl;
    }
    
    //Exit Program!
    return 0;
}
float celsius(float fahren){
    return 5*(fahren-32)/9;
}