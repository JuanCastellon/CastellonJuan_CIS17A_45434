/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Winner.h
 * Author: Juan
 *
 * Created on July 27, 2018, 10:00 PM
 */

#ifndef WINNER_H
#define WINNER_H

#include "Player.h"

class Winner : public Player{
public:
    //Constuctor
    Winner();
    //Constructor
    Winner(string,float,int);
    Winner(const Winner& orig);
    virtual ~Winner();
    
    //Results
    void results();

};

#endif /* WINNER_H */

