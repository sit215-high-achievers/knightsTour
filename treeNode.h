#ifndef TREENODE_H
#define TREENODE_H

#include <vector>
#include <algorithm>
#include <utility>

struct TreeNode
{
    TreeNode(int x, int y, const std::vector<std::vector<int>> &board);

    std::vector<TreeNode> children;
    std::vector<std::pair<int, int>> validMoves;
    int x;
    int y;
    static const int xMoves[];
    static const int yMoves[];

    void makeChildLayer(const std::vector<std::vector<int>> &board);
    static bool processNode(TreeNode &node, int depth, std::vector<std::vector<int>> &board);
};

#endif