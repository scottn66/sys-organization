/**
 * 1. Divide the decimal number by 16. Treat the division as an integer division.  
 * 2. Write down the remainder (in hexadecimal).
 * 3. Divide the result again by 16.  Treat the division as an integer division.  
 * 4. Repeat step 2 and 3 until result is 0.
 * 5. The hex value is the digit sequence of the remainders from the last to first
 * Filename: dec2hex.c
 * Author: Scott Nelson
 * Description: takes a decimal number and converts it into a hexidecimal number 
 *
 */

#include <stdio.h>


int main() {
	long dec, q, r;
    int i, j = 0;
    char hexnum[100];
    printf("Enter a decimal to convert: ");
    scanf("%ld", &dec);
    
    q = dec;
    while (q != 0) {
        r = q % 16;
        if ( r < 10 ) {
            hexnum[j++] = 48 + r;
        } else {
            hexnum[j++] = 55 + r;
        }
        q = q / 16;
    }
    for (i = j; i >= 0; i--) {
        printf("%c", hexnum[i]);
    }
    printf("\n");
    return 0;
}








