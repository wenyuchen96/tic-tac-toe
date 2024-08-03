#include <iostream>
#include <vector>
#include "function.hpp"

// Declare board as external
extern std::vector<std::string> board;

int main()
{
    // define the players: jared and emily
    // jared is the first mover, the maximum steps for jared are 5, the maximum steps for emily is 4
    std::vector<int> jaredSteps;
    std::vector<int> emilySteps;
    int jaredStep;
    int emilyStep;

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Jared's turn: ";
        std::cin >> jaredStep;
        jaredSteps.push_back(jaredStep);
        board[jaredStep] = "x";
        draw();
        if (check_win(jaredSteps)) {
                std::cout << "Jared wins!" << std::endl;
            break;
            }

        if (i < 4)
        { // Emily only plays 4 times
            std::cout << "Emily's turn: ";
            std::cin >> emilyStep;
            emilySteps.push_back(emilyStep);
            board[emilyStep] = "o";
            draw();
        }
        if (check_win(emilySteps)) {
                std::cout << "Emily wins!" << std::endl;
            break;
            }
        
        if(i == 4 && check_win(jaredSteps)==false) {
            std::cout << "It's a draw.\n";
            break;
        }
    }

    return 0;
}
