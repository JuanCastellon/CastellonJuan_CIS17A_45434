/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: Juan
 *
 * Created on July 23, 2018, 11:54 AM
 */
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    //Constructor
    Employee();
    Employee(const Employee& orig);
    virtual ~Employee();
    
    //Getter functions
    string getName();
    int getNumb();
    string getDate();
    
    //Setter functions
    void setName(string);
    void setNumb(int);
    void setDate(string);
    
private:
    //Name of the employee
    string eName;
    //Employee ID Number
    int eNum;
    //Employee Hire Date
    string hreDate;
    
};

#endif /* EMPLOYEE_H */

