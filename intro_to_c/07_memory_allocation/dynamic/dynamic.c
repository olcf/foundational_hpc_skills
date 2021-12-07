/*------------------------------------------------------------
Program showing usage of a dynamically-allocated array.
------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    // Dynamically-allocated array of floats
    int N = 5;
    float *f_array_dyn = malloc(N*sizeof(float));

    for(int i=0; i<N; i++){
        f_array_dyn[i] = 0.25*i;
    }

    for(int i=0; i<N; i++){
        printf("f_array_dyn[%d] = %f\n", i, f_array_dyn[i]);
    }

    free(f_array_dyn);

    return 0;
}
