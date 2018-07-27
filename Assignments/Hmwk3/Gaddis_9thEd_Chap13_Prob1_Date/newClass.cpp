/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:
 * Author: 
 * Created on:
 * Purpose:
*/

#include "newClass.h"
#include <iostream>
#include <string>
using namespace std;
date::date(int x, int y, int z){
    day=x;
    month=y;
    year=z;
}

void date::date1 () const{
    cout<<month<<"/"<<day<<"/"<<year;
    cout<<endl;
}
void date::date2() const{
    string mon;
    switch (month){
        case 1:{
            mon="January";
            break;
        }
        case 2:{
            mon="February";
            break;
        }
        case 3:{
            mon="March";
            break;
        }
        case 4:{
            mon="April";
            break;
        }
        case 5:{
            mon="May";
            break;
        }
        case 6:{
            mon="June";
            break;
        }
        case 7:{
            mon="July";
            break;
        }
        case 8:{
            mon="August";
            break;
        }
        case 9:{
            mon="September";
            break;
        }
        case 10: {
            mon="October";
            break;
        }
        case 11:{
            mon="November";
            break;
        }
        case 12:{
            mon="December";
            break;
        }
    }
    cout<<day<<" "<<mon<<" "<<year<<endl;
    cout<<mon<<" "<<day<<" "<<year<<endl;
    
}