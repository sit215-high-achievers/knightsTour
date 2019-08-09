#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <string>
#include "treeNode.h"

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

void usage()
{
    std::cout << "Usage: ./knightsTour.exe {board_size(int)} {1 for closed tour, 0 for first found tour}" << std::endl;
    exit(0);
}

int main(int argc, char *argv[])
{
    //If correct parameters not passed on startup, present message to user and quit
    if (argc != 3)
        usage();
    else
    {
        int boardSize;        
        std::random_device rd;
        //Get board size from arguments, convert char array to int
        std::string bs(argv[1]);
        std::stringstream str(bs);
        str >> boardSize;
        //If the board size isn't valid, present usage message and quit
        if (!str)
            usage();
        //Get closed tour requirement from arguments
        if (*argv[2] == '1')
            TreeNode::closedTourRequired = true;

        //Initialise board as a 2d vector filled with 0s
        std::vector<std::vector<int>> board(boardSize, std::vector<int>(boardSize));

        //Create first node in tree with starting coordinates of the knight
        TreeNode current(4, 4, board);

        //Process first node. processNode is called recursively on child nodes
        auto stamp = std::clock();
        TreeNode::processNode(current, 1, board);

        //Print board after solution is found, or all paths exhausted
        printBoard(board);
        std::cout << "Board size: " << boardSize << "\n";
        std::cout << "Closed tour: " << std::boolalpha << TreeNode::closedTourRequired << "\n";
        std::cout << "Tour completed in: " << std::clock() - stamp << "ms" << std::endl;
    }
}
