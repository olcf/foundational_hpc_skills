#include <iostream>
#include "randapi.hh"
#define ITERATIONS 10000

using namespace std;

int main () {
  int i;
  int isum;
  float fsum;

  initRand ();

  isum = 0;
  for (i = 0; i < ITERATIONS; i++) {
    isum += getRand (10);
  }

  cout << "getRand () avg: " << isum / ITERATIONS << endl;

  fsum = 0.0;
  for (i = 0; i < ITERATIONS; i++) {
    fsum += getSRand ();
  }

  cout << "getSRand () avg: " << fsum / ITERATIONS << endl;
}
