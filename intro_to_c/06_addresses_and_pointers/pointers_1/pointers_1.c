#include <stdio.h>

int main(){

    float x = 2.713;
    float *p_x;

    p_x = &x;

    printf("The value of x:   %f\n", x);
    printf("The address of x: %p\n", &x);
    printf("The value of p_x: %p\n", p_x);
    printf("The value stored at the memory address stored in p_x: %f\n", *p_x);

    return 0;
}
