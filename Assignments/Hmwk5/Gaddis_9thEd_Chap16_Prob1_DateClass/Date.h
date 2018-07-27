/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: Juan
 *
 * Created on July 23, 2018, 10:24 PM
 */

#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date {
public:
    //Default Constructor
    Date();
    
    //Constructor
    Date(int,int,int);
    
    Date(const Date& orig);
    virtual ~Date();
    
    //Setter Functions
    void setMont(int);
    void setDay(int);
    void setYear(int);
    
    //Getter Functions
    int getMont();
    int getDay();
    int getYear();
    
    //Dates
    void form1();
    void form2();
    void form3();
    
    //Exception Classes 
    class BadDay{
        
    };
    class BadMon{
        
    };
private:
    int mon;
    int day;
    int year;
};

#endif /* DATE_H */

