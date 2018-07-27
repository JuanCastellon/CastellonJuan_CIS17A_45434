/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.cpp
 * Author: Juan
 * 
 * Created on July 23, 2018, 11:54 AM
 */

#include "Employee.h"

Employee::Employee() {
    
}

Employee::Employee(const Employee& orig) {
}

Employee::~Employee() {
}
//123412341234123412341234123412341234123412341234123412341234123412341234123412
//                            Setter Functions
//123412341234123412341234123412341234123412341234123412341234123412341234123412
void Employee::setName(string str){
    eName=str;
}
void Employee::setNumb(int num){
    eNum=num;
}
void Employee::setDate(string str){
    hreDate=str;
}
//123412341234123412341234123412341234123412341234123412341234123412341234123412
//                            Getter Functions 
//123412341234123412341234123412341234123412341234123412341234123412341234123412
string Employee::getName(){
    return eName;
}
int Employee::getNumb(){
    return eNum;
}
string Employee::getDate(){
    return hreDate;
}