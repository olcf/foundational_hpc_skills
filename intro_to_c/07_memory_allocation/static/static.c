/*------------------------------------------------------------
Program showing usage of a statically-allocated array.
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    // Statically-allocated array of floats
    int N = 5;
    float f_array[N];

    for(int i=0; i<N; i++){
        f_array[i] = 0.25*i;
    }

    for(int i=0; i<N; i++){
        printf("f_array[%d] = %f\n", i, f_array[i]);
    }

    return 0;
}
