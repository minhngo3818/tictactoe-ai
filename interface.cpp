
#include "interface.h"

void displayMenu()
{
    std::cout   << "\n\n=============================================\n"
                << "||      Welcome to Tictactoe Simulator     ||\n"
                << "=============================================\n\n";

    std::cout   << "        Are you ready to play ?\n\n";
}

void runGame(char array[][SUB_SIZE_OF_BOARD])
{
    std::string playerInput = "c";
    bool done = false;
    bool gameOn = false;

    while (!done)
    {
        if (gameOn)
        {
            printBoard(array);
            std::cout << "\n\n >> Enter your move(eg. 2,1): ";
            std::cin >> playerInput;
        }
        else
        {
            displayMenu();
            std::cout << " >> Your answer(y/n): ";
            std::cin >> playerInput;

            if (playerInput == "y")
            {
                gameOn = true;
            }
            else if (playerInput == "n")
            {
                std::cout << "\n      Thank you for playing this game :)\n\n";
                done = true;
            }
            else
            {
                std::cout   << "\n    Uh Oh :)) Invalid input.\n"
                            << "        Please enter a proper answer\n\n";
            }
        }
    }
}

void printBoard(char array[][SUB_SIZE_OF_BOARD])
{
    std::cout   << "\n====================================\n"
                << "              0   1   2\n"
                << "         -----------------\n";
    int limitPrint = SIZE_OF_BOARD - 1;
    for (int row = 0; row < SIZE_OF_BOARD; row++)
    {
        std::cout << "\t " << row << "  | ";
        for (int col = 0; col < SIZE_OF_BOARD; col++)
        {
            std::cout << array[row][col];

            if (col < 2)
            {
                std::cout << " | ";
            }
        }

        if (row < 2)
            std::cout << "\n         -----------------\n";
    }
}

void resetGame(char array[][SUB_SIZE_OF_BOARD])
{
    for (int row = 0; row < SIZE_OF_BOARD; row++)
    {
        for (int col = 0; col < SIZE_OF_BOARD; col++)
        {
            array[row][col] = 'o';
        }
    }
}


int checkMoveRemains(char state[][SUB_SIZE_OF_BOARD])
{
    int count = 0;
    for (int row = 0; row < SIZE_OF_BOARD; row++)
    {
        for (int col = 0; col < SIZE_OF_BOARD; col++)
        {
            if (state[row][col] != player || state[row][col] != ai)
                count++;
        }
    }

    return count;
}