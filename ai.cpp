// @author: Minh Minh
// @filename: interface.cpp
// @date: 01/18/2022


#include "ai.h"

// Evaluate Score
int evaluateScore(char array[][SUB_SIZE_OF_BOARD])
{
    // Check row
    for (int row = 0; row < SIZE_OF_BOARD; row++)
    {
        if (array[row][0] == array[row][1] && array[row][0] == array[row][2])
        {
            if (array[row][0] == player)
                return -10;
            else if (array[row][0] == ai)
                return 10;
        }
    }

    // Check colum
    for (int colum = 0; colum < SIZE_OF_BOARD; colum++)
    {
        if (array[0][colum] == array[1][colum] && array[0][colum] == array[2][colum])
        {
            if (array[0][colum] == player)
                return -10;
            else if (array[0][colum] == ai)
                return 10;
        }
    }

    // Check diagonal lines
    if ((array[0][0] == array[1][1] && array[0][0] == array[2][2]) ||
        ((array[0][2] == array[1][1] && array[0][2] == array[2][0])))
    {
        if (array[1][1] == player)
                return -10;
            else if (array[1][1] == ai)
                return 10;
    }

    return 0;   // If there is not win state yet
}


// AI action
void AIMove(char array[][SUB_SIZE_OF_BOARD])
{
    
}

// AI calculation: can it be a recursive function ?
std::string bestMove(char state[][SUB_SIZE_OF_BOARD], int depth, bool AITurn)
{

    int score = evaluateScore(state);

    return "";
}
