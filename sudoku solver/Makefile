play: main.o sudoku.o test_sudoku.o
	gcc main.o sudoku.o test_sudoku.o -o play

main.o: main.c
	gcc -c main.c

sudoku.o: sudoku.c sudoku.h
	gcc -c sudoku.c

test_sudoku.o: test_sudoku.c test_sudoku.h
	gcc -c test_sudoku.c

clean: 
	rm *.o output
