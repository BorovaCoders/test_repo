#include <iostream>

using namespace std;

// Adds 2 integer numbers.
int add(int a, int b) {
  return a + b;
}


bool all_tests_passed = true;
void ASSERT(bool cond) {
  if (!cond) {
    cout << "ERROR!\n";
    all_tests_passed = false;
  }
}

void testAdd() {
  ASSERT(add(2, 2) == 4);
  ASSERT(add(10, 100) == 110);
  ASSERT(add(-1, 924) == 923);

  if (all_tests_passed) {
    cout << "COOL, you did it!\n";
  } else {
    cout << "SORRY, but some tests failed!\n";
  }
}
  
int main() {
  testAdd();
  
  return 0;
}
