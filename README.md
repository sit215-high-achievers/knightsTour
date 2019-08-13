# knightsTour

Instructions:
1. Compile knightsTour.cpp and treeNode.cpp with your preferred c++ compiler (development used g++)
2. Execute program with: ./{executable name} {board dimensions} {1 for closed tour required, 0 for any tour}

e.g. Launching with "./knightsTour.exe 8 1" will find a closed knights tour on an 8x8 board.
     Launching with "./knightsTour.exe 10 0" will return the first tour on a 10x10 board.
     
The output will be an NxN grid of integers representing the board. Each number on the board indicates
the order of moves, with 1 as the starting position.
