/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.cpp
 * Author: Juan
 * 
 * Created on July 23, 2018, 10:24 PM
 */

#include "Date.h"

Date::Date() {
    mon=day=year=0;
}
Date::Date(int d,int m,int y){
    day=d;
    mon=m;
    year=y;
}

Date::Date(const Date& orig) {
}

Date::~Date() {
}
void Date::setMont(int m){
    if(m<1||m>12){
        throw BadMon();
    }
    else{
        mon=m;
    }
    
}
void Date::setDay(int d){
    if(d<1||d>31){
        throw BadDay();
    }
    else{
        day=d;  
    }
    
}
void Date::setYear(int y){
    year=y;
}
    
int Date::getMont(){
    return mon;
}
int Date::getDay(){
    return day;
}
int Date::getYear(){
    return year;
}

//Dates
void Date::form1(){
    cout<<mon<<"/"<<day<<"/"<<year<<endl;
}
void Date::form2(){
    string month;
    if(mon==1){
        month="January";
    }
    if(mon==2){
        month="February";
    }
    if(mon==3){
        month="March";
    }
    if(mon==4){
        month="April";
    }
    if(mon==5){
        month="May";
    }
    if(mon==6){
        month="June";
    }
    if(mon==7){
        month="July";
    }
    if(mon==8){
        month="August";
    }
    if(mon==9){
        month="September";
    }
    if(mon==10){
        month="October";
    }
    if(mon==11){
        month="November";
    }
    if(mon==12){
        month="December";
    }
    cout<<month<<" "<<day<<","<<year<<endl;
}
void Date::form3(){
    string month;
    if(mon==1){
        month="January";
    }
    if(mon==2){
        month="February";
    }
    if(mon==3){
        month="March";
    }
    if(mon==4){
        month="April";
    }
    if(mon==5){
        month="May";
    }
    if(mon==6){
        month="June";
    }
    if(mon==7){
        month="July";
    }
    if(mon==8){
        month="August";
    }
    if(mon==9){
        month="September";
    }
    if(mon==10){
        month="October";
    }
    if(mon==11){
        month="November";
    }
    if(mon==12){
        month="December";
    }
    cout<<day<<" "<<month<<" "<<year<<endl;
}

