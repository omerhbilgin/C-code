#include <stdio.h>
#include <stdlib.h>
#include "password.h"
#include <assert.h>
#include <unistd.h>

int main (int argc, char *argv[]) {

   int length = 16;
   char password[8193];
   int charset = 2;
   
   int ch;
   while ((ch = getopt (argc, argv, "c:l:h")) != -1) {
      switch (ch) {
         case 'c':
            charset = atoi (optarg);
            assert (charset >= 1 && charset <=3);
            break;

         case 'l':
            length = atoi (optarg);
            assert (length > 0 && length <= 8192);
            break;
      
         case 'h':
            printf ("Usage: %s [c charst] | %s [l length] | %s -h for help", argv[0], argv[0], argv[0]);
            exit (3);
      }
   }
   
   makePasswd (password, length, charset);

   printf ("%s\n", password);

   return 0;
}
