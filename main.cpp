// @author: Minh Minh
// @filename: tictactoe
// @date: 01/18/2022

#include "interface.h"
#include "interface.cpp"
#include "ai.h"
#include "ai.cpp"

int main() 
{

    // Generate empty tictactoe Board
    int num = SIZE_OF_BOARD;
    char tictactoe[SIZE_OF_BOARD][SUB_SIZE_OF_BOARD];    

    runGame(tictactoe);
}



