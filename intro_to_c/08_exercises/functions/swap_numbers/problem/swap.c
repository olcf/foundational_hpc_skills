/*-------------------------------------------------------------------
Program that swaps the values of two integers within a function.
Fill in the TODO sections below.
-------------------------------------------------------------------*/

#include <stdio.h>

// Function Definition
// NOTE: This should be "call by reference", so you will use pointers
void swap_numbers( /* TODO: Enter two formal arguments here */ ){

    // TODO: Enter function body to swap two integers.
    // NOTE: You will not need to return anything from this function.
}


// Main Function
int main(){

    int a = 2;
    int b = 4;

    printf("a = %d and b = %d\n", a, b);

    // NOTE: You will need to pass the addresses of the arguments
    swap_numbers( /* TODO: Enter two actual arguments here */ );

    // NOTE: The values should be swapped here so that a = 4 and b = 2
    printf("a = %d and b = %d\n", a, b);

    return 0;
}
