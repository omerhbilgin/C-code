#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include "bubblesort.h"

void bubbleSort (int *array, int length, char option);

int main (int argc, char *argv[]) {

   char option = 'a';   
   int length = -1;

   int ch;
   while ((ch = getopt (argc, argv, "adhl:")) != -1) {
      switch (ch) {
         case 'a':
            option = 'a';
            break;

         case 'd':
            option = 'd';
            break;
   
         case 'l':
            assert (atoi (optarg) > 0);
            length = atoi (optarg);
            break;

         case 'h':
			printUsage(argv[0]);
			exit(1);
            break;
      }
   }  

   if (length > 0) {
	   int array[length];
	   readArray (array, length);
	   bubbleSort (array, length, option);
	   printArray (array, length);
	} else {
		printUsage(argv[0]);
	}

   return EXIT_SUCCESS;
}

void bubbleSort (int *array, int length, char option) {
   assert (option == 'a' || option == 'd');
   assert (length != -1);
   assert (length > 0);

   if (option == 'a') {
      bubbleSortAscending (array, length);
   }

   else if (option == 'd') {
      bubbleSortDescending (array, length);
   }

   else {
      exit(2);
   }
}   
