/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProdWrk.h
 * Author: Juan
 *
 * Created on July 23, 2018, 12:36 PM
 */

#ifndef PRODWRK_H
#define PRODWRK_H

#include "Employee.h"

class ProdWrk : public Employee{
public:
    //Constructor
    ProdWrk();
    ProdWrk(const ProdWrk& orig);
    virtual ~ProdWrk();
    //Setter Functions
    void setShif(int);
    void setRate(float);
    
    //Getter Functions
    int getShif();
    float getRate();
    
private:
    int shift;
    float payRate; 
};

#endif /* PRODWRK_H */

