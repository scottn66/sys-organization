/*
if its little endian it will print a 1, if it is big endian it will
print 0. 

*/

#include <stdio.h>
#include <stdint.h>


int main() {
    int x = 1;
    char *y = (char*)&x;
    printf("%c\n",*y+48);
}