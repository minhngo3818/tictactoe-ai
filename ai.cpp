// @author: Minh Minh
// @filename: interface.cpp
// @date: 01/18/2022


#include "ai.h"


int checkMoveRemains(char state[][SUB_SIZE_OF_BOARD])
{
    int count = 0;

    for (int row = 0; row < SIZE_OF_BOARD; row++)
    {
        for (int col = 0; col < SIZE_OF_BOARD; col++)
        {
            if (state[row][col] == ' ')
                count++;
        }
    }
    std::cout << "\nAmount of remaining slots: " << count << std::endl;
    return count;
}

// Evaluate Score
// player win: -10
// ai win: 10
// no winner: 0
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

// AI calculation:
// @parameters: state - 2D array, int depth - moveRemains, bool player turn indicator 
// @return best score
// @Algorithm: 
// Notes: In tictactoe there is 3 state win, draw, and loose
//  but there can be a function to calculate to limit the moves to win
//  in order to get better speed to win and resource-used efficiency
// - evaluate current score
// - indicate terminal state aka the state when program end with an outcome
//     -> player wins
//     -> ai wins
// - check if it player's turn
//     - use depth value to indicate how deep the recursive loop is
//     - loop the board for empty spot -> make a move
//     - recur the state in each turn of both player and ai respectively
//         -> return the value of terminal state
//     - compare with the current state
//     - return the value of the current state -> store it in an array and use max/min to get best move
// - check if the ai's turn
//     <<do the same the logic as the player turn>>
// - return the best score which indicate the best move
// *addition: add a value that store the best position for ai
// *addition2: there must a factor to calculate which state is better in a player turn
// *problem: how can the function remember the how deep currently is,
// every recursive loop will reset all value except the passed parameters

// Do the simple function that only 3 terminal state win-tie-loose
int minimax(char state[][SUB_SIZE_OF_BOARD], int depth, bool aiTurn)
{
    if (depth == 0)
        return evaluateScore(state);
    else if (depth > 0 && evaluateScore(state) >= 0)
        return evaluateScore(state);
    else
    {
        if (aiTurn)
        {
            int bestScore = -100;
            for (int row = 0; row < SIZE_OF_BOARD; row++)
            {
                for (int col = 0; col < SIZE_OF_BOARD; col++)
                {
                    if (state[row][col] == ' ')
                    {
                        state[row][col] = ai;
                        bestScore = std::max(bestScore, minimax(state, depth-1, !aiTurn));
                        state[row][col] = ' ';      // Undo move
                    }
                }
            }

            return bestScore;
        }

        else    // Player's turn
        {
            int bestScore = 100;
            for (int row = 0; row < SIZE_OF_BOARD; row++)
            {
                for (int col = 0; col < SIZE_OF_BOARD; col++)
                {
                    if (state[row][col] == ' ')
                    {
                        state[row][col] = player;
                        bestScore = std::min(bestScore, minimax(state, depth-1, !aiTurn));
                        state[row][col] = ' ';      // Undo move
                    }
                }
            }

            return bestScore;
        }
    }
}


void AIMove(char state[][SUB_SIZE_OF_BOARD])
{
    if (checkMoveRemains(state) == 8)
    {
        int randomRow = rand() % 3;
        std::cout << "\nrandom row triggered " << randomRow << std::endl;

        int randomCol = rand() % 3;
        std::cout << "\nrandom row triggered " << randomRow << std::endl;

        if (state[randomRow][randomCol] == player)
        {
            randomRow = (randomRow >= 1)?(randomRow - 1) : (randomRow + 1);
            randomCol = (randomCol >= 1)?(randomCol - 1) : (randomCol + 1); 
            state[randomRow][randomCol] = ai;

            std::cout << "\nOverlap case triggered!\n";
        }
        else
        {
            state[randomRow][randomCol] = ai;
            std::cout << "\n No overlap random occur\n";
        }
    }
    else
    {
        int bestScore = -100;
        MovePosition aiBestMove;

        // Guess all possible moves from player
        for (int row = 0; row < SUB_SIZE_OF_BOARD; row++)
        {
            for (int col = 0; col < SUB_SIZE_OF_BOARD; col++)
            {
                if (state[row][col] == ' ')
                {
                    state[row][col] = player;

                    int guessScore = minimax(state, checkMoveRemains(state), false);

                    // Undo player's move;
                    state[row][col] = ' ';

                    if (bestScore < guessScore)
                    {
                        bestScore = guessScore;
                        aiBestMove.row = row;
                        aiBestMove.col = col;
                    }
                }
            }
        }

        // Ai makes a move
        state[aiBestMove.row][aiBestMove.col] = ai;
    }
}