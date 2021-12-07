/*-------------------------------------------------------------------
Program to calculate the area of a circle with a given radius.
-------------------------------------------------------------------*/

#include <stdio.h>

// Function Definition
float calculate_area(float r){

    float pi = 3.141592;

    float a = pi*r*r;

    return a;
}


// Main Function
int main(){

    float radius = 2.0;

    float area;
    area = calculate_area(radius);

    printf("The area of a circle with radius %f is: %f\n", radius, area);

    return 0;
}
