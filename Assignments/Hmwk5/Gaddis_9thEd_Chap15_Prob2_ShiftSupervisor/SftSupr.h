/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SftSupr.h
 * Author: Juan
 *
 * Created on July 23, 2018, 9:43 PM
 */

#ifndef SFTSUPR_H
#define SFTSUPR_H
#include "Employee.h"

class SftSupr : public Employee {
public:
    //Default Constructor
    SftSupr();
    
    //Constructor
    SftSupr(float,float);
    
    SftSupr(const SftSupr& orig);
    virtual ~SftSupr();
    
    //Setter Function
    void setSal(float);
    void setBon(float);
    
    //Getter Function
    float getSal();
    float getBon();
    
private:
    float salary;
    float bonus;
};

#endif /* SFTSUPR_H */

