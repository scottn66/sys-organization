/*
 *
 */

#include <stdio.h>
#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>


extern uint64_t makeNBOC(uint64_t a);


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

int main() {
	uint64_t argc;
	printf("Enter 32 bit integer: ");
	scanf("%lld", argc);
    bool isNBO = checkNBO(argc);
    if (isNBO) {
    	return argc;
    } else {
    	makeNBOC(argc);
    }
	return 0;
}