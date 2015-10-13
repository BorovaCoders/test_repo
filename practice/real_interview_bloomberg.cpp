// Bloomberg LP interview question!
// http://www.careercup.com/question?id=15304663
//
// Develop an algorithm to reverse a string keeping the words intact.
// Example:
// Input:  "This is not so easy question"
// Output: "question easy so not is This"
//
// Add more tests at first.

#include <iostream>
#include <string>
#include "my_assert.h"

using namespace std;

string ReverseWords(const string s) {
  // NOT IMPLEMENTED
  return "world Hello";
}

void test() {
  ASSERT("world Hello" == ReverseWords("Hello world"));
  ASSERT("e d c b a" == ReverseWords("a b c d e"));
  ASSERT_EQ("three two one", ReverseWords("one two three"));
  
  cout << "Tests finished!\n";
}
  
int main() {
  test();
  
  return 0;
}
