/*------------------------------------------------------------
Program showing the use of an if-elseif-else statement.
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    int i = 1;

    if(i < 1){
        printf("i = %d (i < 1)\n", i);
    }
    else if(i == 1){
        printf("i is equal to 1\n");
    }
    else{
        printf("i = %d (i > 1)\n", i);
    }

    return 0;
}
