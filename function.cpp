//
//  function.cpp
//  ttt
//
//  Created by Wenyu Chen on 8/3/24.
//



#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> board = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

void draw()
{

    std::cout << "     |     |      \n";

    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";

    std::cout << "\n";
}


bool check_win(const std::vector<int>& positions) {
    // All possible winning combinations
    const std::vector<std::vector<int>> winning_combinations = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };

    // Sort the player's positions to use std::includes
    std::vector<int> sorted_positions = positions;
    std::sort(sorted_positions.begin(), sorted_positions.end());

    // Check each winning combination
    for (const auto& combination : winning_combinations) {
        if (std::includes(sorted_positions.begin(), sorted_positions.end(),
                          combination.begin(), combination.end())) {
            return true;
        }
    }

    return false;
}
