#include <cstdlib>

using namespace std;

float getSRand () {
  float randValue = (float) rand () / (float) RAND_MAX;
  return randValue;
}
int getRand (int max) {
  int randValue = (int) ((float) max * rand () / (float) RAND_MAX + 1.0);
  return randValue;
}
