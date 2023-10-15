/*
Change the program from the previous problem to be a nasm function 
which is able to be called from a "C" program. Then write a program 
gcdFinder.c containing the code in "C" to call your function. 
Use the "assert()" functions from the "C" library. You can link this 
into your program by #include <assert.h> as you've seen in class. 
Your assembly code should take the two numbers as arguments which are passed from the "C" code.
*/
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>


extern uint64_t SubGCDfinder(uint64_t a, uint64_t b);

void assertion() {
	assert(SubGCDfinder(64, 24) == 8);
	assert(SubGCDfinder(64, 24) == 8);
	assert(SubGCDfinder(64, 24) == 8);

}