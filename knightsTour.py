class Node:
    def __init__(self, x, y, board):
        self.x = x
        self.y = y
        self.validMoves = [] 
        self.children = []
        for i in range(8):
            targetX = x + xMoves[i]
            targetY = y + yMoves[i]
            if(isMoveOnBoard(targetX, targetY, board) and isNodeUnvisited(targetX, targetY, board)):
                self.validMoves.append([targetX, targetY])
                
    def makeChildLayer(self, board):
        for m in self.validMoves:
            self.children.append(Node(m[0], m[1], board))
        self.children.sort(key=lambda x: len(x.validMoves))  
                
def isMoveOnBoard(x, y, board):
    return x < len(board) and x >= 0 and y < len(board) and y >= 0

def isNodeUnvisited(x, y, board):
    return board[y][x] == 0

def processNode(node, depth, board):
    board[node.y][node.x] = depth
    if (depth == pow(len(board), 2)):
        return True
    node.makeChildLayer(board)
    
    for n in node.children:
        if(processNode(n, depth+1, board)):
            return True
        board[n.y][n.x] = 0

xMoves = [2, 2, 1, -1, -2, -2, -1, 1]
yMoves = [-1, 1, 2, 2, 1, -1, -2, -2]


startingX = 4
startingY = 4
boardSize = 10

board = [0]*boardSize

for i in range(boardSize):
    board[i] = [0]*boardSize
    
root = Node(startingX, startingY, board)
processNode(root, 1, board)

for a in board:
    print(a)          
