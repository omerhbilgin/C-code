#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_RANDS 9001
#define TRUE 1
#define FALSE 0

typedef struct node *tree;
typedef struct node {
   unsigned long long value;
   tree left;
   tree right;
} node;

int seenBefore (tree memory, unsigned long long key);

int main (int argc, char **argv) {

   //unsigned long long randomNumber = 384768984llu;
   //unsigned long long randomNumber = 987654321llu;;
   unsigned long long randomNumber = 538785268llu;

   // create the top node of the tree
   node seedNode;
   tree memory = &seedNode;
   // initially just store the seed in the tree
   memory->left = NULL;
   memory->right = NULL;
   memory->value = randomNumber;;
     
   int counter = 0;
   int loopDetected = FALSE;

   while (!loopDetected) {
      randomNumber = randomNumber * randomNumber;
      randomNumber = randomNumber / 100000llu;
      randomNumber = randomNumber % 1000000000llu;

      if (seenBefore (memory, randomNumber)) {
         printf ("Loop detected at step %d\n", counter);
         loopDetected = TRUE;
      }
      printf ("%llu\n", randomNumber);
      
      counter++;
   }

   printf ("Hello, Australia!\n");

   return EXIT_SUCCESS;

}

// returns TRUE iff randomNumber is already in tree
// otherwise inserts it into the tree
int seenBefore (tree memory, unsigned long long key) {

   int alreadyInTree = FALSE;
   assert (memory != NULL);
   
   // either
   // node at top contains it
   if     (key == memory->value) {
      alreadyInTree = TRUE;
   }
   // OR it is smaller than the node value
   // so we investigate the left tree
   else if (key < memory->value) {
      if (memory->left == NULL) {
         memory->left = malloc (sizeof (node));
         memory->left->value = key;
         memory->left->left = NULL;
         memory->left->right = NULL;
      } else {
         alreadyInTree = seenBefore (memory->left, key);
      }
   }
   // OR (it is larger)
   // so we investigate the right tree
   else {
      if (memory->right == NULL) {
         memory->right = malloc (sizeof (node));
         memory->right->value = key;
         memory->right->left = NULL;
         memory->right->right = NULL;
      } else {
         alreadyInTree = seenBefore (memory->right, key);
      }
   }
   return alreadyInTree;
}









