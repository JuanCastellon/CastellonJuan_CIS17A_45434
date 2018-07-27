/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on: 
 * Purpose: Circle Class program, outputs the information about a circle
 *          object given a radius.
*/

//System Libraries Here
#include <iostream>//cin,cout

using namespace std;

//User Libraries Here
class Circle{
    public:
        //Default Constructor
        Circle(){
            radius=0.0f;
        }
        //Initialization Constructor
        Circle(float r){
            radius=r;
        }
        //Setter Function
        void setRadi(float);
        
        //Getter Functions
        float getRadi();
        float getArea();
        float getDiam();
        float getCirc();
        
    private:
        float radius;
        const float pi=3.14159;
};

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float r;
    
    //Initialize Variables
    cout<<"Input the radius of the circle : ";
    cin>>r;
    
    //Creating the object
    Circle c(r);
    
    //Process Input/Output
    
    //Display Results
    cout<<"Radius        = "<<c.getRadi()<<endl;
    cout<<"Diameter      = "<<c.getDiam()<<endl;
    cout<<"Area          = "<<c.getArea()<<endl;
    cout<<"Circumference = "<<c.getCirc()<<endl;
    
    //Exit
    return 0;
}
void Circle::setRadi(float r){
    radius=r;
}
float Circle::getRadi(){
    return radius;
}
float Circle::getArea(){
    return pi*radius*radius;
}
float Circle::getDiam(){
    return radius*2;
}
float Circle::getCirc(){
    return 2*pi*radius;
}