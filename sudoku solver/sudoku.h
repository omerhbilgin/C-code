#ifndef SUDOKU_H
#define SUDOKU_H

#define GRID_SIZE 81

#define MIN_VALUE '1'
#define MAX_VALUE '9'
#define EMPTY_VALUE '.'

#define MAX_CELL (GRID_SIZE - 1)

#define TRUE 1
#define FALSE 0

typedef int cell;
typedef char value;
typedef value sudokuGrid[GRID_SIZE];

void readGame (sudokuGrid game);
void showGame (sudokuGrid game);

int hasSolution (sudokuGrid game);

int isLegal (sudokuGrid game, cell givenCell, value givenValue);
int isFull (sudokuGrid game);
cell getEmptyCell (sudokuGrid game);
void setCell (sudokuGrid game, cell givenCell, value givenValue);
void clearCell (sudokuGrid game, cell givenCell);

int validateCol (sudokuGrid game, cell givenCell, value givenValue);
int validateRow (sudokuGrid game, cell givenCell, value givenValue);
int validateBox (sudokuGrid game, cell givenCell, value givenValue);

#endif // SUDOKU_H