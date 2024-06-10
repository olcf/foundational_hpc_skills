/*-------------------------------------------------------------------
Program that swaps the values of two integers within a function
-------------------------------------------------------------------*/

#include <stdio.h>

// Function Definition
// NOTE: This should be "call by reference", so you will use pointers
void swap_numbers(int *num1, int *num2){

    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


// Main Function
int main(){

    int a = 2;
    int b = 4;

    printf("a = %d and b = %d\n", a, b);

    swap_numbers(&a, &b);

    // NOTE: The values should be swapped here so that a = 4 and b = 2
    printf("a = %d and b = %d\n", a, b);

    return 0;
}
