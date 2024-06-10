/*--------------------------------------------------------------------
Program that adds two vectors together. Fill in the TODO sections.
--------------------------------------------------------------------*/

#include <stdio.h>

int main(){

    int N = 50;

    // TODO: Define 3 vectors called A, B, and C (each of length N) here
    // As an additional challenge, create a copy of this file and try 
    // making one file with static memory allocation and the other with
    // dynamic memory allocation 


    /* This loop performs the following initializations
        A[0] to A[49] get the values 1 to 50
        B[0] to B[49] get the values 49 to 0
        C[0] to C[49] get the value 0
    */
    for(int i=0; i<N; i++){
        A[i] = i + 1;
        B[i] = N - (i + 1);
        C[i] = 0;
    }

    for(int i=0; i<N; i++){

    /* TODO: Use this loop to perform a vector addition of A = B + C, such that
        C[0] = A[0] + B[0];
        C[1] = A[1] + B[1];
        ...
        C[49] = A[49] + B[49];
    */

    }

    // The value of every element of C should be 50
    for(int i=0; i<N; i++){
        printf("C[%d] = %d\n", i, C[i]);
    }

    return 0;
}
