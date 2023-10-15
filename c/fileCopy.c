#include <stdio.h>

#define IN 1
#define OUT 0
/* copy input to output 1st version */
main() {
	int c, nl, nw, nc, state;
    nl = nw = nc = 0;
    state = OUT;
	//read a character, end of file, output
	while((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') //ASCII for newline 
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			nw++;
		}
		putchar(c);
	}
	printf("%d %d %d\n", nl, nw, nc);
}

//counts characters in input; v1

dummy() {}