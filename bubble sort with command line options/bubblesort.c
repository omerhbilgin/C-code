#include "bubblesort.h"
#include <stdio.h>

void readArray (int *array, int length) {
   int i;
   for (i=0; i<length; i++) {
      scanf ("%d", &array[i]);
   }     
}

void printArray (const int *array, int length) {
   for (int i=0; i<length; i++) {
      printf ("%d ", array[i]);
   }
   printf ("\n");
} 

void swapElements (int *array, int i, int j);

void bubbleSortAscending (int *array, int length) {
   int i, j;
   
   for (i=0; i<length-1; i++) {
      for (j=0; j<length-1-i; j++) {
         if (array[j] > array[j+1]) {
            swapElements (array, j, j+1);
         }
      }
   }

}

void bubbleSortDescending (int *array, int length) {
   int i, j;
   
   for (i=0; i<length-1; i++) {
      for (j=0; j<length-1-i; j++) {
         if (array[j] < array[j+1]) {
            swapElements (array, j, j+1);
         }
      }
   }

}

void swapElements (int *array, int i, int j) {
   int temp;
   temp = array[i];
   array[i] = array[j];
   array[j] = temp;
} 

void printUsage (char *name) {
printf ("Usage:\n" 
                   "%s [a or d] [l] length of the array\n" 
                   "a: ascending bubble sort\n" 
                   "d: descending bubble sort\n",  
                    name);
}
