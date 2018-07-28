/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Winner.cpp
 * Author: Juan
 * 
 * Created on July 27, 2018, 10:00 PM
 */

#include "Winner.h"

Winner::Winner() {
}

Winner::Winner(string s,float f,int i){
    name=s;
    score=f;
    yah=i;
}

Winner::Winner(const Winner& orig) {
}

Winner::~Winner() {
}
void Winner::results(){
    cout<<"Winner   = "<<name<<endl;
    cout<<"Points   = "<<score<<endl;
    cout<<"Yahtzees = "<<yah<<endl;
}
