// @author: Minh Minh
// @filename: interface.cpp
// @date: 01/18/2022


#include "interface.h"
#include "ai.h"

extern const char player;
extern const char ai;

void displayMenu()
{
    std::cout   << "\n\n=============================================\n"
                << "||      Welcome to Tictactoe Simulator     ||\n"
                << "=============================================\n\n";

    std::cout   << "        Are you ready to play ?\n\n";
}

void runGame(char state[][3])
{
    std::string playerInput = "c";
    bool menuTrigger = true;
    bool done = false;
    bool gameOn = false;

    while (!done)
    {
        if (gameOn)
        {
            int finalScore = evaluateScore(state);

            if (checkMoveRemains(state) == 0 || finalScore > 0 || finalScore < 0)
            {
                if (finalScore == 0)
                    std::cout << "\n\n    !-!-!- NO WINNER -!-!-! \n";
                else if (finalScore == -10)
                    std::cout << "\n\n    CONGRATS! YOU ARE THE WINNER !!!!!!!! \n";
                else if (finalScore == 10)
                    std::cout << "\n\n    TOO BAD! YOU'RE LOST :((\n";

                gameOn = false;
                resetGame(state);

                std::cout << "\nWanna play a new game?\n\n";
            }
            else
            {
                printBoard(state);
                std::cout << "\n\n >> Enter your move(eg. 2,1): ";
                std::cin >> playerInput;

                if (improperInput(playerInput))
                {
                    std::cout << "\n\n :(( Please enter a proper input.";
                    continue;
                }
                else
                {
                    int rowPlayer = static_cast<int>(playerInput[0]) - '0';   
                    // convert char to int: static_cast<int>(int) - '0'
                    int colPlayer = static_cast<int>(playerInput[2]) - '0'; 
                    if (state[rowPlayer][colPlayer] == ai)
                    {
                        std::cout << "\n !! The position was occupied. !!\n";
                    }
                    else
                    {
                        state[rowPlayer][colPlayer] = player;
                        printBoard(state);
                        AIMove(state);
                        printBoard(state);
                    }             
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

void printBoard(char state[][3])
{
    std::cout   << "\n====================================\n\n"
                << "              0   1   2\n"
                << "         -----------------\n";
    int limitPrint = 3 - 1;
    for (int row = 0; row < 3; row++)
    {
        std::cout << "\t " << row << "  | ";
        for (int col = 0; col < 3; col++)
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

void resetGame(char state[][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            state[row][col] = ' ';
        }
    }
}



bool improperInput(const std::string& playerInput)
{
    if (playerInput.size() == 3)
    {
        if ((playerInput[0] >= '0' && playerInput[0] <= '2') &&
            (playerInput[2] >= '0' && playerInput[2] <= '2') &&
            (playerInput[1] == ','))
            return false;
        else    
            return true;
    }
    else 
    {
        std::cout << " playerInput size: " << playerInput.size() << std::endl;
        return true;
    }

    return false;
}
