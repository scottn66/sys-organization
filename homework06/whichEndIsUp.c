

/* 
 *    C program to determine whether the computer
 * is little endian or big endian. 
 */
 
#include <stdio.h>

int main () {
  unsigned int x = 0x76543210;
  char *c = (char*) &x;
 
  printf ("*c is: 0x%x\n", *c);
  if (*c == 0x10) {
    printf ("\n  Host byte order: little endian. \n");
  } else {
    printf ("\n  Network byte order: big endian. \n");
  }
  return 0;
}