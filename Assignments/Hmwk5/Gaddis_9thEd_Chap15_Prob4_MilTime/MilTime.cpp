/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MilTime.cpp
 * Author: Juan
 * 
 * Created on July 23, 2018, 7:24 PM
 */

#include "MilTime.h"

//Constructor
MilTime::MilTime(int h,int s) {
    milHrs=h;
    milSec=s;
}

MilTime::MilTime(const MilTime& orig) {
}

MilTime::~MilTime() {
}

void MilTime::setTime(int h, int s){
    milHrs=h;
    milSec=s;
    
    //Setting the seconds to standard
    sec=milSec;
    
    //Getting the hours
    if(milHrs>=1300){
        hour=(milHrs-1200)/100;
    }
    else{
        hour=milHrs;
    }
    //Converting to hours
    cout<<"Hour   : "<<hour<<endl;
    //Getting the minutes
    min=milHrs%100;
    cout<<"Minute : "<<min<<endl;
}

int MilTime::getHour(){
    return milHrs;
}
void MilTime::getStHr(){
    if(sec==0&&min<10){
        cout<<hour<<":0"<<min<<":0"<<sec<<endl;
    }
    else if(sec==0){
        cout<<hour<<":"<<min<<":0"<<sec<<endl;
    }
    else{
        cout<<hour<<":"<<min<<":"<<sec<<endl;
    }
    
}