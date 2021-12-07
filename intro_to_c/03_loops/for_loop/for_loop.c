/*------------------------------------------------------------
Program showing the basic idea of a for loop. For each
iteration of the loop, it prints the iteration number (i) 
along with the sum of all values of i up until that point.
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    int N   = 10;
    int sum = 0;

    for(int i=0; i<N; i++){

        sum = sum + i;
        printf("Iteration: %d, sum = %d\n", i, sum);

    }

    return 0;
}
