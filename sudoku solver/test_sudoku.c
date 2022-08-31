#include "test_sudoku.h"
#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

sudokuGrid game0 = {'1', '.', '.', '4', '8', '9', '.', '.', '6',   
                       '7', '3', '.', '.', '.', '.', '.', '4', '.',   
                       '.', '.', '.', '.', '.', '1', '2', '9', '5',  
                       '.', '.', '7', '1', '2', '.', '6', '.', '.',  
                       '5', '.', '.', '7', '.', '3', '.', '.', '8',  
                       '.', '.', '6', '.', '9', '5', '7', '.', '.',  
                       '9', '1', '4', '6', '.', '.', '.', '.', '.',
                       '.', '2', '.', '.', '.', '.', '.', '3', '7',
                       '8', '.', '.', '5', '1', '2', '.', '.', '4'};

void test_validateBox (void) {
	printf ("Running test_validateBox()\n");

	sudokuGrid game = {'1', '.', '.', '4', '8', '9', '.', '.', '6',   
                       '7', '3', '.', '.', '.', '.', '.', '4', '.',   
                       '.', '.', '.', '.', '.', '1', '2', '9', '5',  
                       '.', '.', '7', '1', '2', '.', '6', '.', '.',  
                       '5', '.', '.', '7', '.', '3', '.', '.', '8',  
                       '.', '.', '6', '.', '9', '5', '7', '.', '.',  
                       '9', '1', '4', '6', '.', '.', '.', '.', '.',
                       '.', '2', '.', '.', '.', '.', '.', '3', '7',
                       '8', '.', '.', '5', '1', '2', '.', '.', '4'};

	int box_0_indices[] = {0, 1, 2, 9, 10, 11, 18, 19, 20};
	int box_1_indices[] = {3, 4, 5, 12, 13, 14, 21, 22, 23};
	int box_2_indices[] = {6, 7, 8, 15, 16, 17, 24, 25, 26};
	int box_3_indices[] = {27, 28, 29, 36, 37, 38, 45, 46, 47};
	int box_4_indices[] = {30, 31, 32, 39, 40, 41, 48, 49, 50};
	int box_5_indices[] = {33, 34, 35, 42, 43, 44, 51, 52, 53};
	int box_6_indices[] = {54, 55, 56, 63, 64, 65, 72, 73, 74};
	int box_7_indices[] = {57, 58, 59, 66, 67, 68, 75, 76, 77};
	int box_8_indices[] = {60, 61, 62, 69, 70, 71, 78, 79, 80};

	//int* indices[9] = {box_0_indices, box_1_indices, box_2_indices, box_3_indices, box_4_indices, box_5_indices, box_6_indices, box_7_indices, box_8_indices};

	// {validity_of_0, validity_of_1, ...}
	// validity_of_0 = validity_of_0_for_box_1, validity_of_0_for_box_2, ...
	
	assert (validateBox (game, 31, '2') == FALSE);
	assert (validateBox (game, 31, '5') == FALSE);
	assert (validateBox (game, 31, '6') == TRUE);

	assert (validateBox (game, 69, '1') == TRUE); 
	assert (validateBox (game, 69, '2') == TRUE);
	assert (validateBox (game, 69, '5') == TRUE);

	assert (validateBox (game, 10, '8') == TRUE);
	assert (validateBox (game, 10, '9') == TRUE);
	assert (validateBox (game, 10, '1') == FALSE);

	assert (validateBox (game, 0, '3') == FALSE);
	assert (validateBox (game, 0, '7') == FALSE);
	assert (validateBox (game, 0, '2') == TRUE);

	assert (validateBox (game, 80, '5') == TRUE);
	assert (validateBox (game, 80, '4') == FALSE);
	assert (validateBox (game, 80, '3') == FALSE);

	printf ("test_validateBox() has succeeded!\n\n");
}


void test_validateRow (void) {
	printf ("Running test_validateRow()\n");

	sudokuGrid game = {'1', '.', '.', '4', '8', '9', '.', '.', '6',   
                       '7', '3', '.', '.', '.', '.', '.', '4', '.',   
                       '.', '.', '.', '.', '.', '1', '2', '9', '5',  
                       '.', '.', '7', '1', '2', '.', '6', '.', '.',  
                       '5', '.', '.', '7', '.', '3', '.', '.', '8',  
                       '.', '.', '6', '.', '9', '5', '7', '.', '.',  
                       '9', '1', '4', '6', '.', '.', '.', '.', '.',
                       '.', '2', '.', '.', '.', '.', '.', '3', '7',
                       '8', '.', '.', '5', '1', '2', '.', '.', '4'};

	int existence_1[9] = {1, 0, 1, 1, 0, 0, 1, 0, 1};
	int validity_1[9]  = {0, 1, 0, 0, 1, 1, 0, 1, 0};

	int existence_2[9] = {0, 0, 1, 1, 0, 0, 0, 1, 1};
	int validity_2[9]  = {1, 1, 0, 0, 1, 1, 1, 0, 0};

	int existence_3[9] = {0, 1, 0, 0, 1, 0, 0, 1, 0};
	int validity_3[9]  = {1, 0, 1, 1, 0, 1, 1, 0, 1};

	int existence_4[9] = {1, 1, 0, 0, 0, 0, 1, 0, 1};
	int validity_4[9]  = {0, 0, 1, 1, 1, 1, 0, 1, 0};

	int existence_5[9] = {0, 0, 1, 0, 1, 1, 0, 0, 1};
	int validity_5[9]  = {1, 1, 0, 1, 0, 0, 1, 1, 0};

	int existence_6[9] = {1, 0, 0, 1, 0, 1, 1, 0, 0};
	int validity_6[9]  = {0, 1, 1, 0, 1, 0, 0, 1, 1};

	int existence_7[9] = {0, 1, 0, 1, 1, 1, 0, 1, 0};
	int validity_7[9]  = {1, 0, 1, 0, 0, 0, 1, 0, 1};

	int existence_8[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	int validity_8[9]  = {0, 1, 1, 1, 0, 1, 1, 1, 0};

	int existence_9[9] = {1, 0, 1, 0, 0, 1, 1, 0, 0};
	int validity_9[9]  = {0, 1, 0, 1, 1, 0, 0, 1, 1};

	int *validities[9] = {validity_1, validity_2, validity_3, validity_4, validity_5, validity_6, validity_7, validity_8, validity_9};

	int validity_from_function, validity_from_array;
	int row;

	for (int i = 0; i < 9; i++) {
		//printf ("%d:\n\n", i);
		value currentValue = (char) ((i+1) + 48);
		for (row = 0; row < 9; row++) {
			validity_from_function = validateRow (game, row*9, currentValue);
			validity_from_array = validities[i][row];
			//printf ("%d %d\n", validity_from_array, validity_from_function);
			assert (validity_from_array == validity_from_function);
		}
		//printf ("----------------------------------\n");
	}
	
	printf ("test_validateRow() has succeeded!\n\n");
}

void test_validateCol (void) {
	printf ("Running test_validateCol()\n");

	sudokuGrid game = {'1', '.', '.', '4', '8', '9', '.', '.', '6',   
                       '7', '3', '.', '.', '.', '.', '.', '4', '.',   
                       '.', '.', '.', '.', '.', '1', '2', '9', '5',  
                       '.', '.', '7', '1', '2', '.', '6', '.', '.',  
                       '5', '.', '.', '7', '.', '3', '.', '.', '8',  
                       '.', '.', '6', '.', '9', '5', '7', '.', '.',  
                       '9', '1', '4', '6', '.', '.', '.', '.', '.',
                       '.', '2', '.', '.', '.', '.', '.', '3', '7',
                       '8', '.', '.', '5', '1', '2', '.', '.', '4'};

	int existence_1[9] = {1, 1, 0, 1, 1, 1, 0, 0, 0};
	int validity_1[9]  = {0, 0, 1, 0, 0, 0, 1, 1, 1};

	int existence_2[9] = {0, 1, 0, 0, 1, 1, 1, 0, 0};
	int validity_2[9]  = {1, 0, 1, 1, 0, 0, 0, 1, 1};

	int existence_3[9] = {0, 1, 0, 0, 0, 1, 0, 1, 0};
	int validity_3[9]  = {1, 0, 1, 1, 1, 0, 1, 0, 1};

	int existence_4[9] = {0, 0, 1, 1, 0, 0, 0, 1, 1};
	int validity_4[9]  = {1, 1, 0, 0, 1, 1, 1, 0, 0};

	int existence_5[9] = {1, 0, 0, 1, 0, 1, 0, 0, 1};
	int validity_5[9]  = {0, 1, 1, 0, 1, 0, 1, 1, 0};

	int existence_6[9] = {0, 0, 1, 1, 0, 0, 1, 0, 1};
	int validity_6[9]  = {1, 1, 0, 0, 1, 1, 0, 1, 0};

	int existence_7[9] = {1, 0, 1, 1, 0, 0, 1, 0, 1};
	int validity_7[9]  = {0, 1, 0, 0, 1, 1, 0, 1, 0};

	int existence_8[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	int validity_8[9]  = {0, 1, 1, 1, 0, 1, 1, 1, 0};

	int existence_9[9] = {1, 0, 0, 0, 1, 1, 0, 1, 0};
	int validity_9[9]  = {0, 1, 1, 1, 0, 0, 1, 0, 1};

	int* validities[9] = {validity_1, validity_2, validity_3, validity_4, validity_5, validity_6, validity_7, validity_8, validity_9};

	int validity_from_function, validity_from_array;
	int column;

	for (int i = 0; i < 9; i++) {
		//printf ("%d:\n\n", i);
		value currentValue = (char) ((i+1) + 48);
		for (column = 0; column < 9; column++) {
			validity_from_function = validateCol (game, column, currentValue);
			validity_from_array = validities[i][column];
			//printf ("%d %d\n", validity_from_array, validity_from_function);
			assert (validity_from_array == validity_from_function);
		}
		//printf ("----------------------------------\n");
	}

	printf ("test_validateCol() has succeeded!\n\n");
}


void test_isLegal (void) {
	printf("Running test_isLegal()\n");

	sudokuGrid game = {'1', '.', '.', '4', '8', '9', '.', '.', '6',   
           			   '7', '3', '.', '.', '.', '.', '.', '4', '.',   
           			   '.', '.', '.', '.', '.', '1', '2', '9', '5',  
           			   '.', '.', '7', '1', '2', '.', '6', '.', '.',  
           			   '5', '.', '.', '7', '.', '3', '.', '.', '8',  
            		   '.', '.', '6', '.', '9', '5', '7', '.', '.',  
            		   '9', '1', '4', '6', '.', '.', '.', '.', '.',
            		   '.', '2', '.', '.', '.', '.', '.', '3', '7',
        		       '8', '.', '.', '5', '1', '2', '.', '.', '4'};

	assert (!isLegal (game, 2, '1'));
	assert (!isLegal (game, 6, '1'));	
	assert (!isLegal (game, 7, '1'));

	assert (isLegal (game, 1, '5'));
	assert (isLegal (game, 7, '7'));
	
	assert (!isLegal (game, 38, '7'));
	assert (!isLegal (game, 38, '5'));
	assert (!isLegal (game, 38, '6'));

	assert (!isLegal (game, 78, '7'));
	assert (!isLegal (game, 78, '3'));
	assert (!isLegal (game, 78, '4'));
	assert (isLegal (game, 78, '9'));

	printf ("test_isLegal() has succeeded!\n\n");
}


void test_readGame (void) {
	printf("Running test_readGame()\n");
	sudokuGrid game;

	readGame (game);

	printf ("This is what you have entered:\n");
	showGame (game);

	if (game[31] != 'z') {
		fprintf (stderr, "test_readGame() has failed on 1st condition!\n");
		exit(1);
	}

	if (game[80] != 'z') {
		fprintf (stderr, "test_readGame() has failed on 2nd condition!\n");
		exit(1);
	}

	printf ("\n\ntest_readGame() has succeeded!\n\n");
}

void test_clearCell (void) {
	printf("Running test_clearCell()\n");
	sudokuGrid game_0 = {'.', '.', '.', '.', '.', '.', '.', '.', '.',   
            '.', '.', '.', '.', '.', '.', '.', '.', '.',   
            '.', '.', '.', '.', '.', '.', '.', '.', '.',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '.', '.', '.', '.', '.', '.', '.', '.', '.',  
            '.', '.', '.', '.', '.', '.', '.', '.', '.',  
            '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.'};

    sudokuGrid game_1 = {'1', '2', '3', '4', '5', '6', '7', '8', '9',
            '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	assert (game_0[30] != '.');
	clearCell (game_0, 30);
	if (game_0[30] != '.') {
		fprintf (stderr, "test_clearCell() has failed on game_0, part 1!\n");
		exit(1);
	}

	assert (game_0[31] != '.');
	clearCell (game_0, 31);
	if (game_0[31] != '.') {
		fprintf (stderr, "test_clearCell() has failed on game_0, part 2!\n");
		exit(1);
	}

	clearCell (game_0, 0);
	if (game_0[0] != '.') {
        fprintf (stderr, "test_clearCell() has failed on game_0, part 3!\n");
        exit(1);
    }

	assert (game_1[4] != '.');
	clearCell (game_1, 4);
	if (game_1[4] != '.') {
        fprintf (stderr, "test_clearCell() has failed on game_1!\n");
        exit(1);
    }

	printf ("test_clearCell() has succeeded!\n\n");
}


void test_setCell (void) {
	printf("Running test_setCell()\n");
	sudokuGrid game_0;
	sudokuGrid game_1;
	sudokuGrid game_2;

	cell candidateCell_0 = 13;
	cell candidateCell_1 = 31;
	cell candidateCell_2 = 18;

	value testValue = 't';

	setCell (game_0, candidateCell_0, testValue);
	if (game_0[candidateCell_0] != testValue) {
		fprintf (stderr, "test_setCell() has failed on game_0!\n");
		exit(1);
	}

	setCell (game_1, candidateCell_1, testValue);
	if (game_1[candidateCell_1] != testValue) {
		fprintf (stderr, "test_setCell() has failed on game_1!\n");
		exit(1);
	}

	setCell (game_2, candidateCell_2, testValue);
	if (game_2[candidateCell_2] != testValue) {
		fprintf (stderr, "test_setCell() has failed on game_2!\n");	
		exit(1);
	}

	printf ("test_setCell() has succeeded!\n\n");
}

void test_isFull (void) {
	printf("Running test_isFull()\n");
	sudokuGrid game_0 = {'.', '.', '.', '.', '.', '.', '.', '.', '.',   
   			'.', '.', '.', '.', '.', '.', '.', '.', '.',   
			'.', '.', '.', '.', '.', '.', '.', '.', '.',  
			'.', '.', '.', '.', '.', '.', '.', '.', '.',  
			'.', '.', '.', '.', '.', '.', '.', '.', '.',  
			'.', '.', '.', '.', '.', '.', '.', '.', '.',  
			'.', '.', '.', '.', '.', '.', '.', '.', '.',  
			'.', '.', '.', '.', '.', '.', '.', '.', '.',  
			'.', '.', '.', '.', '.', '.', '.', '.', '.'};

	sudokuGrid game_1 = {'1', '2', '3', '4', '5', '6', '7', '8', '9',  
			'1', '2', '3', '4', '5', '6', '7', '8', '9',  
			'1', '2', '3', '4', '5', '6', '7', '8', '9',   
			'1', '2', '3', '4', '5', '6', '7', '8', '9',   
			'1', '2', '3', '4', '5', '6', '7', '8', '9',  
			'1', '2', '3', '4', '5', '6', '7', '8', '9',  
			'1', '2', '3', '4', '5', '6', '7', '8', '9',  
			'1', '2', '3', '4', '5', '6', '7', '8', '9',  
			'1', '2', '3', '4', '5', '6', '7', '8', '9'};


/*
	sudokuGrid game_2 = {'.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.'};	
*/

	int full;

	full = isFull (game_0);
	if (full) {
		fprintf (stderr, "test_isFull() 1st try has failed!\n");
		exit(1);
	}

	full = isFull (game_1);
	if (!full) {
		fprintf (stderr, "test_isFull() 2nd try has failed!\n");
		exit(1);
	}	

	printf ("test_isFull() has succeeded!\n\n");
}

void test_getEmptyCell (void) {
	printf("Running test_getEmptyCell()\n");
	sudokuGrid game_0 = {'1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '.', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',   
            '1', '2', '3', '4', '5', '6', '7', '8', '9',   
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	sudokuGrid game_1 = {'.', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',   
            '1', '2', '3', '4', '5', '6', '7', '8', '9',   
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	sudokuGrid game_2 = {'1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',   
            '1', '2', '3', '4', '5', '6', '7', '8', '9',   
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '9',  
            '1', '2', '3', '4', '5', '6', '7', '8', '.'};

	cell empty_cell;
	empty_cell = getEmptyCell (game_0);
	if (empty_cell != 10) {
		fprintf (stderr, "test_getEmptyCell() has failed on game_0!\n");
		exit(1);
	}

	empty_cell = getEmptyCell (game_1);
	if (empty_cell != 0) {
		fprintf (stderr, "test_getEmptyCell() has failed on game_1!\n");
		exit(1);
	}

	empty_cell = getEmptyCell (game_2);
	if (empty_cell != 80) {
		fprintf (stderr, "test_getEmptyCell() has falied on game_2!\n");
		exit(1);
	}			

	printf ("test_getEmptyCell() has succeeded!\n\n");
}

void test_hasSolution (void) {
	

	sudokuGrid game0 =   {'.', '.', '.', '.', '.', '.', '.', '.', '.',   
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',   
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',
                        '.', '.', '.', '.', '.', '.', '.', '.', '.'};

	assert (hasSolution(game0));

	sudokuGrid game1 =   {'1', '2', '3', '.', '.', '.', '.', '.', '.',   
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',   
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',
                        '.', '.', '.', '.', '.', '.', '.', '.', '.'};

	assert (hasSolution(game1));

	sudokuGrid game2 =   {'1', '.', '.', '.', '.', '.', '.', '.', '.',   
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',   
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',  
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',
                        '.', '.', '.', '.', '.', '.', '.', '.', '.',
                        '.', '.', '.', '.', '.', '.', '.', '.', '9'};	
					
	assert (hasSolution(game2));

	sudokuGrid game3 =   {'1', '.', '.', '4', '8', '9', '.', '.', '6',   
                        '7', '3', '.', '.', '.', '.', '.', '4', '.',   
                        '.', '.', '.', '.', '.', '1', '2', '9', '5',  
                        '.', '.', '7', '1', '2', '.', '6', '.', '.',  
                        '5', '.', '.', '7', '.', '3', '.', '.', '8',  
                        '.', '.', '6', '.', '9', '5', '7', '.', '2',  
                        '9', '1', '4', '6', '.', '.', '.', '.', '.',
                        '.', '2', '.', '.', '.', '.', '.', '3', '7',
                        '8', '.', '.', '5', '1', '2', '.', '.', '4'};
	//printf ("game3 -> hasSolution(game3) = %d\n", hasSolution(game3));

	assert (!hasSolution(game3));

	sudokuGrid game4 =   {'1', '.', '.', '4', '8', '9', '.', '.', '6',   
                        '7', '3', '.', '.', '.', '.', '.', '4', '.',   
                        '.', '.', '.', '.', '.', '1', '2', '9', '5',  
                        '.', '.', '7', '1', '2', '.', '6', '.', '.',  
                        '5', '.', '.', '7', '.', '3', '.', '.', '8',  
                        '.', '.', '6', '.', '9', '5', '7', '.', '.',  
                        '9', '1', '4', '6', '.', '.', '.', '.', '.',
                        '.', '2', '.', '.', '8', '.', '.', '3', '7',
                        '8', '.', '.', '5', '1', '2', '.', '.', '4'};

	assert (!hasSolution(game4));

	printf ("test_hasSolution() has succeeded\n");
		
}

void testSudoku (void) {
	test_isFull();
	test_getEmptyCell();
	test_setCell();
	test_clearCell();
//	test_readGame();
	test_validateCol();
	test_validateRow();
	test_validateBox();
	test_isLegal();
	test_hasSolution();
} 
