/*------------------------------------------------------------
Program showing the basic idea of a do while loop while
contrasting it with a while loop. The while loop will never
get executed since the initial value of j (=10) is not between
10 and 20 (it IS 10). The do while loop will get executed
since at least one iteration of the loop is always executed.
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    int j = 10; // Declare integer j and set its value to 10

    /* --------------------------------------
    while loop
        -> Executes statements ONLY if
           condition is met
    -------------------------------------- */
    while(j > 10 && j < 20){
        printf("while: j = %d\n", j);
        j = j + 1;
    }

    j = 10; // Reset value of j to 10

    /* --------------------------------------
    do while loop
        -> Executes statements at least 1 time, 
           even if condition is not met 
    -------------------------------------- */
    do{
        printf("do-while: j = %d\n", j);
        j = j + 1;
    }while(j > 10 && j < 20);

    return 0;
}
