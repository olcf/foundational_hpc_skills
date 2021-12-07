/*------------------------------------------------------------
Program showing the usage of a break statement. The loop 
iteration number is printed for values 0-6, but once the value
7 is reached the break statement terminates the loop.
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    for(int i=0; i<10; i++){

        if(i == 7){
            break;
        }

        printf("Loop iteration: %d\n", i);
    }	

    return 0;
}
