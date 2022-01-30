// @author: Minh Minh
// @filename: interface.cpp
// @date: 01/18/2022


#include "interface.h"

void displayMenu()
{
    std::cout   << "\n\n=============================================\n"
                << "||      Welcome to Tictactoe Simulator     ||\n"
                << "=============================================\n\n";

    std::cout   << "        Are you ready to play ?\n\n";
}

void runGame(char state[][SUB_SIZE_OF_BOARD])
{
    std::string playerInput = "c";
    bool menuTrigger = true;
    bool done = false;
    bool gameOn = false;

    while (!done)
    {
        if (gameOn)
        {
            if (checkMoveRemains(state) == 0)
            {
                int finalScore = evaluateScore(state);

                if (finalScore == 0)
                    std::cout << "\n\n    !-!-!- NO WINNER -!-!-! \n";
                else if (finalScore == -10)
                    std::cout << "\n\n    CONGRATS! YOU ARE THE WINNER !!!!!!!! \n";
                else if (finalScore == 10)
                    std::cout << "\n\n    TOO BAD! YOU'RE LOST :((\n";

                gameOn = false;

                std::cout << "\n\n Wanna play a new game?\n";
            }
            else
            {
                printBoard(state);
                std::cout << "\n\n >> Enter your move(eg. 2,1): ";
                std::cin >> playerInput;

                if (!improperInput(playerInput))
                {
                    std::cout << "\n\n :(( Please enter a proper input.";
                    continue;
                }
                else
                {
                    int rowPlayer = static_cast<int>(playerInput[0]);
                    int colPlayer = static_cast<int>(playerInput[2]);
                    state[rowPlayer][colPlayer] = player;
                }
            }


        }
        else
        {
            if (menuTrigger)
                displayMenu();
                menuTrigger = false;

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
                std::cout   << "\n    Uh Oh :(( Invalid input.\n"
                            << "        Please enter a proper answer\n\n";
            }
        }
    }
}

void printBoard(char state[][SUB_SIZE_OF_BOARD])
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
            std::cout << state[row][col];

            if (col < 2)
            {
                std::cout << " | ";
            }
        }

        if (row < 2)
            std::cout << "\n         -----------------\n";
    }
}

void resetGame(char state[][SUB_SIZE_OF_BOARD])
{
    for (int row = 0; row < SIZE_OF_BOARD; row++)
    {
        for (int col = 0; col < SIZE_OF_BOARD; col++)
        {
            state[row][col] = ' ';
        }
    }
}


bool improperInput(const std::string& playerInput)
{
    if (playerInput.size() != 3)
        return false;
    else
    {
        if ((playerInput[0] > -1 && playerInput[0] < 3)
            && (playerInput[2] > -1 && playerInput[2] < 3)
            && playerInput[1] == ',')
            return true;
        else
            return false;
    }
}