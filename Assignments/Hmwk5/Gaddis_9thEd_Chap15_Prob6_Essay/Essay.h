/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Essay.h
 * Author: Juan
 *
 * Created on July 23, 2018, 9:12 PM
 */

#ifndef ESSAY_H
#define ESSAY_H
#include "GradAct.h"

class Essay : public GradAct {
public:
    //Default Constructor
    Essay();
    //Constructor
    Essay(float,float,float,float);
    
    Essay(const Essay& orig);
    virtual ~Essay();
    //Setter Functions
    void setGram(float);
    void setSpel(float);
    void setLeng(float);
    void setCont(float);
    
    //Getter Functions
    float getGram();
    float getSpel();
    float getLeng();
    float setCont();
    
    //Grading based off criteria
    float crit();
    
private:
    float gram;
    float spel;
    float leng;
    float cont;
};

#endif /* ESSAY_H */

