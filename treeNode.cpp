#include "treeNode.h"

//Moves are represented by pairs of the same index in the following arrays.
//i.e. (xMoves[0], yMoves[0]) represents a move 2 to the right and 1 up from the current position
const int TreeNode::xMoves[] = {2, 2, 1, -1, -2, -2, -1, 1};
const int TreeNode::yMoves[] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool TreeNode::closedTourRequired = false;

//Constructor. Valid moves are found and stored - any moves off the board or targeting an already explored node are ignored
TreeNode::TreeNode(int x, int y, const std::vector<std::vector<int>> &board) : x(x), y(y)
{
    for (int i = 0; i < 8; i++)
    {
        int targetX = this->x + xMoves[i];
        int targetY = this->y + yMoves[i];
        if (targetX < board.size() && targetX >= 0 && targetY < board.size() && targetY >= 0 && board[targetY][targetX] == 0)
            validMoves.push_back(std::make_pair(targetX, targetY));
    }
}

//Build the child layer and store child nodes in vector. Sort child vector by number of possible moves, ascending (Warnsdorff)
void TreeNode::makeChildLayer(const std::vector<std::vector<int>> &board)
{
    for (const auto &p : validMoves)
        this->children.push_back(TreeNode(p.first, p.second, board));
    std::sort(this->children.begin(), this->children.end(), [](TreeNode a, TreeNode b) { return a.validMoves.size() < b.validMoves.size(); });
}

//Check if tour is a valid closed tour
bool TreeNode::isClosedTour(const TreeNode &node, const std::vector<std::vector<int>> &board)
{
    for (int i = 0; i < 8; i++)
    {
        int targetX = node.x + xMoves[i];
        int targetY = node.y + yMoves[i];
        if (targetX < board.size() && targetX >= 0 && targetY < board.size() && targetY >= 0 && board[targetY][targetX] == 1)
            return true;
    }
    return false;
}

//Process the current position
bool TreeNode::processNode(TreeNode &node, int depth, std::vector<std::vector<int>> &board)
{
    //Mark the current position with the current depth of the tree (i.e current move number)
    board[node.y][node.x] = depth;

    //If we've covered the board and met closed tour requirements, bounce out of recursion stack
    if (depth == board.size() * board.size() && (!TreeNode::closedTourRequired || TreeNode::isClosedTour(node, board)))
        return true;

    //Add valid moves as child nodes to current node
    node.makeChildLayer(board);

    //Process child nodes in order from least moves to most moves
    for (auto &n : node.children)
    {
        if (processNode(n, depth + 1, board))
            return true;
        board[n.y][n.x] = 0;
    }
}
