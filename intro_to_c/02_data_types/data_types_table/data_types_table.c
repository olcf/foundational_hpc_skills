/*------------------------------------------------------------
Program that prints that value of several variables to the
screen along with their size in bytes (in a table format).
------------------------------------------------------------*/

#include <stdio.h>

int main(){
	
    char a      = 'X';
    int i       = 22;
    float x     = 3.14159265358979323846264338327;
    double y    = 3.14159265358979323846264338327;
    char pi[31] = "3.14159265358979323846264338327";

    printf("\n--------------------------------------------------------------------------\n");
    printf("%-20s %-20s %-20s %-20s \n", "Variable", "Data Type", "Value", "Size (B)");
    printf("--------------------------------------------------------------------------\n");
    printf("%-20s %-20s %-20c %-20lu \n", "a", "char", a, sizeof(char));
    printf("%-20s %-20s %-20i %-20lu \n", "i", "int", i, sizeof(int));
    printf("%-20s %-20s %-20.16f %-20lu \n", "x", "float", x, sizeof(float));
    printf("%-20s %-20s %-20.16f %-20lu \n", "y", "double", y, sizeof(double));
    printf("--------------------------------------------------------------------------\n");
    printf("Actual value of pi ( 29 decimal places ): 3.14159265358979323846264338327\n\n");

    return 0;
}
