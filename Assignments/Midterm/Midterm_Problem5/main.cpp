/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <cmath>   //Sqrt Function
using namespace std;

//User Libraries Here
struct Prime{
	unsigned char prime;
	unsigned char power;
};
struct Primes{
	Prime *prime;
	unsigned char nPrimes;
};

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    int number=0, powCntr=0, primeN=0;
    Primes num;
    num.prime=nullptr;

    cout<<"Enter a number between 2 and 10000"<<endl;
    cin>>number; //input number to find the prime factors
    
    num.prime=new Prime[number/2];

    for (int i=2;i<=number;i++) { //loop through to find factors
        while (number%i==0) {
            number/=i;
            powCntr++;
        }
        num.prime[primeN].power=powCntr;
        num.prime[primeN].prime=i;
        
        if (powCntr>0){
            primeN++;
        }
        powCntr=0;
    }

    for (int i=0;i<primeN;i++) {
        cout<<"Prime: "<<num.prime[i].prime<<
              "   Power: "<<num.prime[i].power<<endl;
    }

    delete [] num.prime;
    
    return 0;
}