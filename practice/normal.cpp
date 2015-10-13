#include <iostream>
#include "my_assert.h"

using namespace std;

// Math sin(x) funtion of angle x in DEGREES!
// You could use standart library or
// Taylor series:)
double my_sin(double deg) {
  // NOT IMPLEMENTED
  return -1.0;
}

void testSin() {
  ASSERT(my_sin(0.0) == 0.0);
  
  const double eps = 1e-4;
  ASSERT_NEAR(1.0, my_sin(90), eps);
  ASSERT_NEAR(0.0, my_sin(180), eps);
  ASSERT_NEAR(-1.0, my_sin(270), eps);
  ASSERT_NEAR(sqrt(2.0)/2, my_sin(45), eps);
  ASSERT_NEAR(0.5, my_sin(30), eps);

  cout << "Tests finished!\n";
}
  
int main() {
  testSin();
  
  return 0;
}
