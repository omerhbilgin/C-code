#include "password.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

char getRandomChar (int option);

void makePasswd (char *str, int length, int charset) {
   srand (time (NULL));

   int i;
   for (i=0; i<length; i++) {
      str[i] = getRandomChar(charset);
   }
   str[length] = '\0';
}

char getRandomChar (int option) {
   int randomNumber;

   const char string1[] = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
   const char string2[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
   const char string3[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!+%&()=?*-";
   char string[strlen (string3) + 1];
   
   switch (option) {
      case 1: 
         strcpy (string, string1);
         break;

      case 2:
         strcpy (string, string2);
         break;

      case 3:
         strcpy (string, string3);
         break;
   }
   randomNumber = rand(); 
   randomNumber = randomNumber % strlen (string);

   return string[randomNumber];
}
