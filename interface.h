// @author: Minh Minh
// @filename: interface.cpp
// @date: 01/18/2022


#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>

const int SIZE_OF_BOARD = 3;
const int SUB_SIZE_OF_BOARD = 3;
const char player = 'o', ai = 'x';

void displayMenu();

void runGame(char state[][SUB_SIZE_OF_BOARD]);

void printBoard(char state[][SUB_SIZE_OF_BOARD]);

void resetGame(char state[][SUB_SIZE_OF_BOARD]);

void playerMove(char state[][SUB_SIZE_OF_BOARD], std::string position);

bool improperInput(const std::string& playerInput);

#endif
