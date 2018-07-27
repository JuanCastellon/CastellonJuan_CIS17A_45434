/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Essay.cpp
 * Author: Juan
 * 
 * Created on July 23, 2018, 9:12 PM
 */

#include "Essay.h"

//Default Constructor
Essay::Essay() {
    gram=0;
    spel=0;
    leng=0;
    cont=0;
}

Essay::Essay(float g,float s,float l,float c) {
    gram=g;
    spel=s;
    leng=l;
    cont=c;
}

Essay::Essay(const Essay& orig) {
}

Essay::~Essay() {
}
//Getter Functions
void Essay::setGram(float g){
    gram=g;
}
void Essay::setSpel(float s){
    spel=s;
}
void Essay::setLeng(float l){
    leng=l;
}
void Essay::setCont(float c){
    cont=c;
}

//Setter Functions
float Essay::getGram(){
    return gram;
}
float Essay::getSpel(){
    return spel;
}
float Essay::getLeng(){
    return leng;
}
float Essay::setCont(){
    return cont;
}

//Grading
float Essay::crit(){
    float score;
    score=gram+spel+leng+cont;
    return score;
}