#ifndef INTERFACE_H
#define INTERFACE_H

const int SIZE_OF_BOARD = 3;
const int SUB_SIZE_OF_BOARD = 3;
const char player = 'o', ai = 'x';

#include <iostream>
#include <string>

void displayMenu();

void runGame(char array[][SUB_SIZE_OF_BOARD]);

void printBoard(char array[][SUB_SIZE_OF_BOARD]);

void resetGame(char array[][SUB_SIZE_OF_BOARD]);

#endif
