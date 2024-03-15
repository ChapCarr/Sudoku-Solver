#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "board.h"

int main()
{


    int board[9][9] =
    {{0,7,5,0,9,0,0,0,6},
    {0,2,3,0,8,0,0,4,0},
    {8,0,0,0,0,3,0,0,1},
    {5,0,0,7,0,2,0,0,0},
    {0,4,0,8,0,6,0,2,0},
    {0,0,0,9,0,1,0,0,3},
    {9,0,0,4,0,0,0,0,7},
    {0,6,0,0,7,0,5,8,0},
    {7,0,0,0,1,0,3,9,0}};

    
    printBoard(board);
    printf("\n--------------\n");
    solveBoard(board, 0, 0);

    printBoard(board);

    return 0;
}