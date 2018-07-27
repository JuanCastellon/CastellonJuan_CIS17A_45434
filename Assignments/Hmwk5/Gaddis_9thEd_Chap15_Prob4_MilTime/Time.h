/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: Juan
 *
 * Created on July 23, 2018, 7:06 PM
 */

#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time {
public:
    //Default Constructor
    Time();
    //Constructor
    Time(int,int,int);
    Time(const Time& orig);
    virtual ~Time();
    
    //Getter Functions
    int getHour();
    int getMin();
    int getSec();
protected:
    int hour;
    int min;
    int sec;
};

#endif /* TIME_H */

