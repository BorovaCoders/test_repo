#include <iostream>
#include "my_assert.h"

using namespace std;

// Math sin(x) funtion of angle x in DEGREES!
// You could use standart library or
// Taylor series:)
/*long double my_fact(int n){
	if(n < 0)
	return 0;
	else if( n == 0)
	return 1;
	else //if( n > 0)
	return n*MyFact(n-1);
}*/
double my_sin(double deg) {
  double PI = 3.14159265359;	
  if(deg >= 360)
  {
  	int t1 = (int)(deg/(360));
  	//cout <<"t1 = "<< t1 << endl; 
  	deg = deg - t1*360;
  }	
  //double PI = 3.1415;
  double x = deg*PI/180;
  /*cout <<"before x = "<< x << endl; 
  if(x >= 2*PI)
  {
  	int t1 = (int)(x/(2*PI));
  	cout <<"t1 = "<< t1 << endl; 
  	x = x - t1*2*PI;
  }	
  cout <<"after x = "<< x << endl; */
  double res = x;
  double my_pow = x;
  double my_fact = 1;
  int minus = -1;
  for(int i = 1; i < 20; ++i){
  	//my_p_fact += 8*i + 6; 
  	//my_fact = (2*i+1)*2*i + 8*i + 6;
  	my_fact *= (2*i+1)*2*i;
  	my_pow *= x*x; 
  	//res += pow(-1, i)*pow(x, 2*i + 1)/MyFact(2*i + 1); 
  	//res += pow(-1, i)*pow(x, 2*i + 1)/my_fact; 
  	//res += minus*my_pow/my_fact; 
  	res += pow(-1, i)*my_pow/my_fact; 
  	//minus *= -1;
  }
  return res;
}

void testSin() {
  ASSERT(my_sin(0.0) == 0.0);
  cout <<"my_sin(3600000.0) = "<< my_sin(3600000.0) << endl;
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
