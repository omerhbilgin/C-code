#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"
#include "test_sudoku.h"

#define TRUE 1
#define FALSE 0

#define MIN_VALUE '1'
#define MAX_VALUE '9'


int main (int argc, char **argv) {
	testSudoku();


	sudokuGrid game;
	printf ("Enter the game:\n");
	readGame (game);

	showGame (game);


	if (hasSolution(game)) {
		showGame (game);
	}


	return EXIT_SUCCESS;
}



