/*------------------------------------------------------------
Program that prints that value of several variables to the
screen along with their size in bytes.
------------------------------------------------------------*/

#include <stdio.h>

int main(){
	
    char a   = 'X';
    int i    = 22;
    float x  = 3.14159265358979323846264338327;
    double y = 3.14159265358979323846264338327;

    // Strings in C are arrays of char
    char pi[31] = "3.14159265358979323846264338327";

    printf("\n");
    printf("The value of character a:             %c (size %lu byte)\n", a, sizeof(char));
    printf("The value of integer i:               %d (size %lu bytes)\n", i, sizeof(int));
    printf("The value of float x:                 %.16f (size %lu bytes)\n", x, sizeof(float));
    printf("The value of double y:                %.16f (size %lu bytes)\n", y, sizeof(double));
    printf("The value of pi to 29 decimal places: %s\n", pi);
    printf("\n");

    return 0;
}
