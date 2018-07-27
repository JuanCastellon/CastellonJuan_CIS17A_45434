/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dice.cpp
 * Author: Juan
 * 
 * Created on July 27, 2018, 1:12 PM
 */

#include "Dice.h"

//Default Constructor
Dice::Dice() {
    d1=d2=d3=d4=d5=0;
}

Dice::Dice(const Dice& orig) {
}

Dice::~Dice() {
    
}
void Dice::roll(){
    int dice1=rand()%6+1;
    int dice2=rand()%6+1;
    int dice3=rand()%6+1;
    int dice4=rand()%6+1;
    int dice5=rand()%6+1;
    
    d1=dice1;
    d2=dice2;
    d3=dice2;
    d4=dice4;
    d5=dice5;
}
void Dice::display(){
    cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<" "<<d5<<endl;
}
int Dice::sum(){
   int sum;
   sum+=d1+d2+d3+d4+d5;
   return sum;
}

