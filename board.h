#ifndef BOARD_H
#define BOARD_H

#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9
#include <stdbool.h>
// int boardArray[BOARD_HEIGHT][BOARD_WIDTH];


typedef struct zeroFound
{
    int i;
    int j; 

}zeroFound;


void printBoard(int boardArray[BOARD_HEIGHT][BOARD_WIDTH]);

bool checkMove(int board[BOARD_HEIGHT][BOARD_WIDTH], int row, int col, int input);

bool solveBoard(int board[BOARD_HEIGHT][BOARD_WIDTH], int row, int col); 

zeroFound* is_empty(int board[BOARD_HEIGHT][BOARD_WIDTH], zeroFound *zeros);

#endif // BOARD_H