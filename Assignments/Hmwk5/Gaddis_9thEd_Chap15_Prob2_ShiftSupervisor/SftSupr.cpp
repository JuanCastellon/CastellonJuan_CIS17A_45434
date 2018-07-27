/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SftSupr.cpp
 * Author: Juan
 * 
 * Created on July 23, 2018, 9:43 PM
 */

#include "SftSupr.h"

//Default Constructor
SftSupr::SftSupr() {
    salary=0;
    bonus=0;
}
//Constructor
SftSupr::SftSupr(float s,float b){
    salary=s;
    bonus=b;
}

SftSupr::SftSupr(const SftSupr& orig) {
}

SftSupr::~SftSupr() {
}

//Setter Functions
void SftSupr::setSal(float s){
    salary=s;
}
void SftSupr::setBon(float b){
    bonus=b;
}

//Getter Functions
float SftSupr::getSal(){
    return salary;
}
float SftSupr::getBon(){
    return bonus;
}
