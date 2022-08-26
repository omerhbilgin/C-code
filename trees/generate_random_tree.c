/* This program generates 1000 random numbers and inserts
   them into a tree */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define NUM_RANDS 1000

typedef struct node *tree;
typedef struct node {
   int value;
   tree left;
   tree right;
} node;

void insertIntoTree (tree memory, int number);
void printTree (tree memory);

int main (int argc, char **argv) {

   srand (time (NULL));
   int seed = rand() % 10;
   int randomNumber = seed;
   int counter = 0;
   node seedNode;
   tree memory = &seedNode;
   
   memory->value = randomNumber;
   memory->left = NULL;
   memory->right = NULL;
   
   while (counter < NUM_RANDS) {

      insertIntoTree (memory, randomNumber);
      randomNumber = rand();
      // printf ("%d\n", randomNumber);

      counter++;
   }

   printTree (memory);

   return EXIT_SUCCESS;
}

void insertIntoTree (tree memory, int number) {

   assert (memory != NULL);

   if (memory->value <= number) {
      if (memory->right == NULL) {
         memory->right = malloc (sizeof (node));
         memory->right->value = number;
         memory->right->left = NULL;
         memory->right->right = NULL;
      } else {   
         insertIntoTree (memory->right, number);
      }
   }

   else { 
      if (memory->left == NULL) {
         memory->left = malloc (sizeof (node));
         memory->left->value = number;
         memory->left->left = NULL;
         memory->left->right = NULL;
      } else {
         insertIntoTree (memory->left, number);
      }
   }

   
}

void printTree (tree memory) {

   if (memory == NULL) {
      return;
   }

   printf ("%d\n", memory->value);

   if (memory->right != NULL) {
      printTree (memory->right);
   } 
 
   if (memory->left != NULL) {
      printTree (memory->left);
   }


}
