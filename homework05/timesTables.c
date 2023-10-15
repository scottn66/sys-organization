/*
 * This table prints out the multiplication table for numbers 0 to n
 */

#include <stdio.h>

int main() {
	int i, j;
	int n = 0;
	printf( "   > Enter the max number on your table: " );
    fflush( stdin );
    scanf( "%d", &n );

	//printing the columns
	printf("%4c", ' ' );
	for (i = 2; i <= n; i++) {
		printf("%4d", i);
	}
	printf("\n");

	//print the inside of the mul table
	for (i = 2; i <= n; i++) {
		printf("%4d", i);
		for (j = 2; j <= n; j++) {
			printf("%4d", i * j);
		}
		printf("\n");
	}
}