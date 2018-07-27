/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MilTime.h
 * Author: Juan
 *
 * Created on July 23, 2018, 7:24 PM
 */

#ifndef MILTIME_H
#define MILTIME_H

#include "Time.h"

class MilTime : public Time {
public:
    //Default Constructor
    MilTime();
    //Constructor
    MilTime(int,int);
    MilTime(const MilTime& orig);
    virtual ~MilTime();
    
    //Setter Function
    void setTime(int,int);
    
    //Getter Functions
    int getHour();
    void getStHr();
    
    //Exceptions
    class BadHour{
        
    };
    class BadSecs{
        
    };
    
private:
    int milHrs;
    int milSec;
};

#endif /* MILTIME_H */

