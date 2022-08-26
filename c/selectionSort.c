#include <stdio.h>

#define SIZE 15

void displayArray (int [], int);
void selectionSort (int [], int);
 
int main (void) {
	int array[SIZE] = {12, 34, 45, 56, 76, 67, 3, 2, 987, 334, 10, 12, 65,56, 77};
//	for (int i=0; i<SIZE; i++)
//		scanf ("%d", &array[i]);
	displayArray (array, SIZE);
	printf("\n\n");
	selectionSort (array, SIZE);
	displayArray (array, SIZE);
	printf ("\n");
	return 0;
}

void displayArray (int array[], int size) {

        int i;
        for (i=0; i<size; i++)
                printf ("%d  ", array[i]);

        printf ("\n");

}

void selectionSort (int array[], int size) {

	int i, j;
	int temp;
	int smallest;
	int smallestIndex;


	for (i=0; i<size-1; i++) {
		smallest = array[i];

		for (j=i+1; j<size; j++) {
			if (array[j] < smallest) {
				smallest = array[j];
				smallestIndex = j;
			}
		}	

		temp = array[i];
		array[i] = smallest;
		array[smallestIndex] = temp;
			
	}

}
