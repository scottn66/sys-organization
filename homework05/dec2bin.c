/**
 * Filename: dec2bin
 * Description: converting a given decimal number into its binary equivalent
 * Author: Scott Nelson
 * Date: 3/9/2021
 */
#include <stdio.h>

//decr does the arithmetic for calculating the bits in reverse order
int * decr(int dec) {

	static int b[ 10 ];
    int i;

	if (dec == 0) {
		b[0] = 0;
		return b;
	}

    for ( i = 0; dec > 0; i++ ) {
        b[i] = dec % 2;
        dec = dec / 2;
	}

	return b;
}

//flipBits takes in the array of bits from decr and correctly reverses the order
void flipBits(int arr[]) {
	for (int i = 10; i >= 0; i--) {
        printf("%d", arr[i]);
	}
}


int main() {
	int dec, j;

	printf("Enter the number to convert: ");    
    scanf("%d",&dec);
	int *bb;

	bb = decr(dec);
	printf("\n conversion to bits= ");
	flipBits(bb);
	printf("\n");
	return 0;
}