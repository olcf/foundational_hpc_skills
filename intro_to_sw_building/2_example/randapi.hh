#ifndef __RAND_API_H
#define __RAND_API_H

// Call this first to initialize the random number generator
void initRand ();

// Get a random floating point number between 1 and 10.
float getSRand ();

// Get a random integer between 1 and max.
int getRand (int max);

#endif
