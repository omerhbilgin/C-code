#include <stdio.h>

#define SIZE 10

void displayArray (int [], int);
void swap (int [], int, int);
void insertionSort (int [], int);

int main (void) {

	int array[SIZE];
	for (int i=0; i<SIZE; i++)
		scanf ("%d", &array[i]);

	insertionSort (array, SIZE);
	displayArray (array, SIZE);


	return 0;
}

void displayArray (int array[], int size) {

	int i;
	for (i=0; i<size; i++)
		printf ("%d  ", array[i]);

	printf ("\n");

}

void swap (int array[], int i, int j) {
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void insertionSort (int array[], int size) {

	int i, j;
	int temp;
	
	for (i=0; i<size; i++) {
		j = i;
		while (j > 0) {
			if (array[j] < array[j-1]) {
				swap(array, j, j-1);
			}
			j--;
		}
	}

}
