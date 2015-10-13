#include <iostream>
#include <cmath>

#define ASSERT(cond) if (!(cond)) {	               			\
    std::cout << "Condition " << #cond					\
              << " failed at line " <<  __LINE__ << "\n";		\
  } else {;}

#define ASSERT_NEAR(a, b, delta) if (fabs((a) - (b)) > (delta)) {	\
    std::cout << "Assert failed! " << (a) << " is too far from "	\
	      << (b) << " at line " << __LINE__ << "\n"; }		\

#define ASSERT_EQ(a, b) if ((a) != (b)) {				\
    std::cout << "Failed! " << #a << " is NOT equal to " << #b          \
	      << " that is " << (b) << " line " << __LINE__ << "\n"; }
