#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 10

void displayArray (int array[], int size);
void merge (int result[], int size_result, int a[], int size_a, int b[], int size_b);
void mergeSort (int array[], int size);

int main (int argc, char **argv) {
	int array[SIZE] = {31, 1, 2, 34, 9, 7, 45, 3, 998, 100};
	
	displayArray (array, SIZE);
	mergeSort (array, SIZE);
	displayArray (array, SIZE);

	return 0;
}

void mergeSort (int array[], int size) {
	// if size <= 1, array is already sorted
	if (size <= 1) {
		return;
	}
	
	// split array into left & right and sort these seperately
	int * left = malloc ((size/2) * sizeof(int));
	int * right = malloc ((size - size/2) * sizeof(int));

	int i;
	for (i = 0; i < size/2; i++) {
		left[i] = array[i];
	}

	for (i = 0; i < size - size/2; i++) {
		right[i] = array[(size/2) + i];
	}

	mergeSort (left, size/2);
	mergeSort (right, size - size/2);

	// merge left & right
	merge (array, size, left, size/2, right, size - size/2);
}

void merge (int result[], int size_result, int a[], int size_a, int b[], int size_b) {
	assert (size_a + size_b == size_result);
	int i;

	int a_idx = 0;
	int b_idx = 0;
	int index = 0;

	while ((a_idx < size_a) && (b_idx < size_b)) {
		if (a[a_idx] < b[b_idx]) {
			result[index] = a[a_idx];
			a_idx++;
			index++;
		} else {
			result[index] = b[b_idx];
			b_idx++;
			index++;
		}
	}

	// if a[] is fully appended to result[], then add the leftovers from b[]
	if (a_idx == size_a) {
		for (i = 0; i < (size_b - b_idx); i++) {
			result[index + i] = b[b_idx + i];
		} 
	} else {
		for (i = 0; i < (size_a - a_idx); i++) {
			result[index + i] = a[a_idx + i];
		}
	}
}

void displayArray (int array[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf ("%d ", array[i]);
	}
	printf ("\n");
}

