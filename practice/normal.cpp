#include <iostream>
#include "my_assert.h"

using namespace std;

// Math sin(x) funtion of angle x in DEGREES!
// You could use standart library or
// Taylor series:)
long double MyFact(int n){
	if(n < 0)
	return 0;
	else if( n == 0)
	return 1;
	else //if( n > 0)
	return n*MyFact(n-1);
}
double my_sin(double deg) {
  double PI = 3.14159265359;		
  double x = deg*PI/180;	
  double res = 0;
  for(int i = 0; i < 100; ++i){
  	res += pow(-1, i)*pow(x, 2*i + 1)/MyFact(2*i + 1); 
  }
  return res;
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
