// @author: Minh Minh
// @filename: interface.cpp
// @date: 01/18/2022


#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <sstream>
#include <string>


void displayMenu();

void runGame(char state[][3]);

void printBoard(char state[][3]);

void resetGame(char state[][3]);

//void playerMove(char state[][3], const std::string& position);

bool improperInput(const std::string& playerInput);

#endif

