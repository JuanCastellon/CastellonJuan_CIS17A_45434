/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.cpp
 * Author: Juan
 * 
 * Created on July 23, 2018, 7:06 PM
 */

#include "Time.h"

Time::Time() {
    hour=min=sec=0;
}
Time::Time(int h,int m,int s){
    hour=h;
    min=m;
    sec=s;
}

Time::Time(const Time& orig) {
}

Time::~Time() {
}
int Time::getHour(){
    return hour;
}
int Time::getMin(){
    return min;
}
int Time::getSec(){
    return sec;
}