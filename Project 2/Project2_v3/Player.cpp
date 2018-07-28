/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: Juan
 * 
 * Created on July 27, 2018, 12:59 PM
 */

#include "Player.h"
//Constructor
Player::Player(string s){
    name=s;
}

//Copy Constructor
Player::Player(Player &obj){
    name=obj.name;
    index=obj.index;
    yah=obj.yah;
    chance=obj.chance;
    score=obj.score;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

//Setter Functions
void Player::setName(string s){
    name=s;
}
void Player::setScre(float s){
    score+=s;
}
void Player::setIndx(int i){
    index=i;
}
//Getter Functions
string Player::getName(){
    return name;
}
float Player::getScre(){
    return score;
}
int Player::getIndx(){
    return index;
}
int Player::getChan(){
    return chance;
}
int Player::getYaht(){
    return yah;
}


//Game Functions
void Player::incYaht(){
    yah++;
}
void Player::incChan(){
    chance++;
}