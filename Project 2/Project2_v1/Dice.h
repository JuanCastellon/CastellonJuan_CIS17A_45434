/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dice.h
 * Author: Juan
 *
 * Created on July 27, 2018, 1:12 PM
 */

#ifndef DICE_H
#define DICE_H

#include "Player.h"

class Dice {
public:
    //Default Constructor
    Dice();
    Dice(const Dice& orig);
    //Destructor
    ~Dice();
    
    //Game Functions
    void roll();
    void display();
    int sum();
    
private:
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
};

#endif /* DICE_H */

