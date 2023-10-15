#include <stdio.h>

main() {
	printf("hello, world\n");
    //convert();
//}

//Farenheit -> Celsius

//int convert() {
	float f, c;
	int lower, upper, step;

	lower = 0;
	upper = 200;
	step = 10;

	f = lower;
	while (f <= upper) {
		c = (5.0/9.0) * (f - 32);
		printf("%3.0f %10.1f\n", f, c); //%d indicated integer, f-> float
		f = f + step;
	}
}


//RUNNING
/* 
 *
 *  % gcc -o helloworld helloworld.c 
 *  % ./helloworld
 *
 */