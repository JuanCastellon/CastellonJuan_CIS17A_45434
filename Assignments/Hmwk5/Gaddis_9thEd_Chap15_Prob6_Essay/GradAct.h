/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GradAct.h
 * Author: Juan
 *
 * Created on July 23, 2018, 9:02 PM
 */

#ifndef GRADACT_H
#define GRADACT_H
#include <iostream>
using namespace std;

class GradAct {
public:
    //Default Constructor
    GradAct();
    
    //Constructor
    GradAct(float);
    
    GradAct(const GradAct& orig);
    virtual ~GradAct();
    
    //Setter Function
    void setScre(float);
    
    //Getter Function
    float getScre();
    
    //Scoring
    char getLtGr() const;
    
private:
    float score;
};

#endif /* GRADACT_H */

