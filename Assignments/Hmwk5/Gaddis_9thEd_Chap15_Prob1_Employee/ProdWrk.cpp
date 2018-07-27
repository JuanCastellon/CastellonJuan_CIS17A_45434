/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProdWrk.cpp
 * Author: Juan
 * 
 * Created on July 23, 2018, 12:36 PM
 */

#include "ProdWrk.h"

ProdWrk::ProdWrk() {
    //Pay Rate Initialization
    payRate=0.0f;
    //Start on the Day shift
    shift=1;
}

ProdWrk::ProdWrk(const ProdWrk& orig) {
}

ProdWrk::~ProdWrk() {
}
void ProdWrk::setShif(int time){
    //Indicates what time of the day the shift is at. Day=1 and Night=0
    shift=time;
}
void ProdWrk::setRate(float rate){
    //Gets the pay rate for the employee
    payRate=rate;
}
int ProdWrk::getShif(){
    return shift;
}
float ProdWrk::getRate(){
    return payRate;
}