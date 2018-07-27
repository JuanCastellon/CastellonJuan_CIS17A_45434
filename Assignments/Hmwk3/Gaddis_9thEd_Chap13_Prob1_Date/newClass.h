/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newClass.h
 * Author: kevr1
 *
 * Created on July 8, 2018, 2:17 PM
 */

#ifndef NEWCLASS_H
#define NEWCLASS_H
#include <iostream>
#include <string>
using namespace std;
class date{
private:
    int day;//day of the month
    int month; //month of the day
    int year; //year of the day
    
public:
    date (int, int, int);
    
    void date1 ()const;
    void date2 ()const;
    
};    

#endif /* NEWCLASS_H */

