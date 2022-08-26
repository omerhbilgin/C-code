#include <stdio.h>

#define SIZE 10

void displayArray (int [], int);
void bubbleSort (int [], int);
 
int main (void) {
	
	int array[SIZE];
	
	for (int i=0; i<SIZE; i++) 
		scanf ("%d", &array[i]);

	bubbleSort (array, SIZE);
	displayArray (array, SIZE);

	return 0;
}

void displayArray (int array[], int size) {
	int i;

	for (i=0; i<size; i++) 
		printf ("%d  ", array[i]);

	printf ("\n");
}

void bubbleSort (int array[], int size) {

	int i, j;
	int temp;

	for (i=size-1; i>=0; i--) {
	
		for (j=0; j<i; j++) {

			if (array[j] > array[j+1]) {
				
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;

			}
	
		}

	}


}
