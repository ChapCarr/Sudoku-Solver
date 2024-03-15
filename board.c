#include "board.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printBoard(int boardArray[BOARD_HEIGHT][BOARD_WIDTH])
{
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            printf(" %d ", boardArray[i][j]);
        }
        printf("\n");
    }
}

bool checkMove(int board[BOARD_HEIGHT][BOARD_WIDTH], int row, int col, int input)
{
    // check row
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        if (input == board[row][i])
        {
            
            return false;
        }
    }

    // check cols
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        if (input == board[i][col])
        {
           
            return false;
        }
    }

    // check subgrid
    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;
    for (int i = subgrid_row; i < subgrid_row + 3; i++)
    {
        for (int j = subgrid_col; j < subgrid_col + 3; j++)
        {
            if (board[i][j] == input)
            {
                
                return false;
            }
        }
    }
    return true;
}



zeroFound *is_empty(int board[BOARD_HEIGHT][BOARD_WIDTH], zeroFound *zeros)
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                zeros->i = i;
                zeros->j = j;
                return zeros;
            }
        }
    }

    zeros->i = 100;
    return zeros;
}

bool solveBoard(int board[BOARD_HEIGHT][BOARD_WIDTH], int row, int col)
{
    zeroFound *zeros = malloc(sizeof(zeroFound));
    is_empty(board, zeros);
    if (zeros->i == 100)
    {
        return true;
    }

    row = zeros->i;
    col = zeros->j;

    for (int i = 0; i <= 9; i++)
    {
        if (checkMove(board, row, col, i))
        {
            board[row][col] = i;
            if (solveBoard(board, row, col))
            {
                return true;
            }
        }
        board[row][col] = 0;
    }

    return false;
}