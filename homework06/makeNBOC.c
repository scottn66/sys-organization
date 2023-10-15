/* 
 *    C program to determine whether the computer
 * is little endian or big endian. and if it is little endian 
 * the program converts it to NBO
 */
 
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

bool checkNBO (unsigned int x) {
  //returns true if uint is in NBO, false if it's little endian
  bool isNBO = true;
  //uint32_t x = 0x76543210;
  char *c = (char*) &x;
  printf ("*c is: 0x%x\n", *c);
  if (*c == 0x10) {
    printf ("\n  Host byte order: little endian. \n");
    isNBO = false;
  } else {
    printf ("\n  Network byte order: big endian. \n");
    isNBO = true;
  }
  return isNBO;
}


uint32_t makeNBOC(uint32_t net) {
	//if the parameter passed in is in little endian convert it and return NBO
	if ((checkNBO(net)) == false) {
		int first = (net & 0x000000ff) << 24;
		int second = (net & 0x0000ff00) << 8;
		int third = (net & 0x00ff0000) >> 8;
		int fourth = (net & 0xff000000) >> 24;
		net = (first | second | third | fourth);
		return net;
    } else {
    	return net;
    }
}