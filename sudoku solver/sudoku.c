#include "sudoku.h"
#include <assert.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isFull (sudokuGrid game) {
	int i;
	int full = TRUE;

	for (i = 0; i < GRID_SIZE; i++) {
		if (game[i] == EMPTY_VALUE) {
			full = FALSE;
			break;
		}
	}

	return full;
}	


cell getEmptyCell (sudokuGrid game) {
	assert (!isFull (game));
	cell empty_cell;
	
	int i;
	for (i = 0; i < GRID_SIZE; i++) {
		if (game[i] == EMPTY_VALUE) {
			empty_cell = i;
			break;
		}
	}

	return empty_cell;
}


void setCell (sudokuGrid game, cell givenCell, value givenValue) {
	game[givenCell] = givenValue;
}

void clearCell (sudokuGrid game, cell givenCell) {
	game[givenCell] = EMPTY_VALUE;
}


void readGame (sudokuGrid game) {
	int ch;
	int counter = 0;
	while ((ch = getchar()) != EOF) {
		game[counter] = ch;
		counter++;
		if (counter == GRID_SIZE) {
			break;
		}
	}

}


void showGame (sudokuGrid game) {
	int i;
	for (i = 0; i < GRID_SIZE; ++i) {
		if (i % 9 == 0) {
			printf ("\n");
		}
		printf ("%c ", game[i]);
	}
}






int isLegal (sudokuGrid game, cell candidateCell, value givenValue) {
	assert (game[candidateCell] == '.');

	if (!validateCol (game, candidateCell, givenValue)) {
		//printf ("validateCol() has failed!\n");
		return FALSE;
	}

	if (!validateRow (game, candidateCell, givenValue)) {
		//printf ("validateRow() has failed!\n");
		return FALSE;
	}

	if (!validateBox (game, candidateCell, givenValue)) {
		//printf ("validateBox() has failed!\n");
		return FALSE;
	}

	return TRUE;
}








int validateCol (sudokuGrid game, cell givenCell, value givenValue) {
	int i;
	int topOfColumn = givenCell % 9;
	for (i = topOfColumn; i < GRID_SIZE; i += 9) {
		if (game[i] == givenValue) {
			return FALSE;
		}
	}

	return TRUE;
}

int validateRow (sudokuGrid game, cell givenCell, value givenValue) {
	int i;
	int givenRow = givenCell / 9;
	int startOfRow = givenRow * 9;

	for (i = startOfRow; i < startOfRow + 9; i++) {
		if (game[i] == givenValue) {
			return FALSE;
		}
	}

	return TRUE;
}


int validateBox (sudokuGrid game, cell givenCell, value givenValue) {
	int index;

	index = givenCell - (givenCell % 3);
	index = ((index / 27) * 27) + (index % 9);

	int indices[9] = {index, index+1, index+2, index+9, index+10, index+11, index+18, index+19, index+20};

	int currentIndex;
	for (int i = 0; i < 9; i++) {
		currentIndex = indices[i];
		if (game[currentIndex] == givenValue) {
			return FALSE;
		}
	}

	return TRUE;
}



int hasSolution (sudokuGrid game) {
	if (isFull (game)) {
		return TRUE;
	}

	cell candidateCell = getEmptyCell (game);
	value candidateValue = MIN_VALUE;

	while (candidateValue <= MAX_VALUE) {
		if (isLegal (game, candidateCell, candidateValue)) {
			setCell (game, candidateCell, candidateValue);

			if (hasSolution(game)) {
				return TRUE;
			}
		}
		clearCell (game, candidateCell);
		candidateValue++;
	}

	return FALSE;
}







