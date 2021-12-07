/*------------------------------------------------------------
Program showing the basic idea of a while loop. A float 
variable (x) is initially set to 1000.0. Within the loop, as 
long as the value of x is greater than 1, the value of x is
printed and x's value is cut in half. 
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    float x = 1000.0;

    while(x > 1.0){
        printf("x = %f\n", x);
        x = x / 2.0;
    }

    return 0;
}
