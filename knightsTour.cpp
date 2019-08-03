#include <iostream>
#include <iomanip>
#include <vector>
#include "treeNode.h"

#define BOARD_SIZE 9

void printBoard(const std::vector<std::vector<int>> &board)
{
    for (const auto &v : board)
    {
        for (const auto &i : v)
            std::cout << std::setw(5) << i;
        std::cout << "\n";
    }
    std::cout << std::endl;
}

int main()
{
    //Initialise board as a 2d vector filled with 0s
    std::vector<std::vector<int>> board(BOARD_SIZE, std::vector<int>(BOARD_SIZE));
    //Create first node in tree with starting coordinates of the knight
    TreeNode current(0, 0, board);
    //Process first node. processNode is called recursively on child nodes
    TreeNode::processNode(current, 1, board);
    //Print board after solution is found, or all paths exhausted
    printBoard(board);
}