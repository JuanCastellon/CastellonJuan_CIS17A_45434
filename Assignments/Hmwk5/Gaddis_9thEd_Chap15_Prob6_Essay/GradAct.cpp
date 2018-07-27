/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GradAct.cpp
 * Author: Juan
 * 
 * Created on July 23, 2018, 9:02 PM
 */

#include "GradAct.h"

//Default Constructor
GradAct::GradAct() {
    score=0.0f;
}
//Constructor
GradAct::GradAct(float s){
    score=s;
}

GradAct::GradAct(const GradAct& orig) {
}

GradAct::~GradAct() {
}
void GradAct::setScre(float s){
    score=s;
}
float GradAct::getScre(){
    return score;
}
char GradAct::getLtGr() const{
    char grade;
    if(score>89){
        grade='A';
    }
    else if(score>79){
        grade='B';
    }
    else if(score>69){
        grade='C';
    }
    else if(score>59){
        grade='D';
    }
    else{
        grade='F';
    }
    return grade;
}
