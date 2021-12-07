/*------------------------------------------------------------
Program showing a continue statement within a for loop. The 
loop iteration number is printed except for the value 7 since
the continue statement moves on to the next iteration of the 
loop.
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    for(int i=0; i<10; i++){

        if(i == 7){
            continue;
        }

        printf("Loop iteration: %d\n", i);
    }	

    return 0;
}
