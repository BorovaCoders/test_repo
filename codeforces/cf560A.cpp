// Problem http://codeforces.com/problemset/problem/560/A
// It it easier than you could think.
// I have already implemented input/output data.
// You need only to write solution!
// Good Luck!

#include <iostream>
#include <vector>

using namespace std;

// Find min amount that could not be represented
// in currency system with given nominals.
// Return -1 if there are no such amount.
int findMinBadAmount(const vector<int>& nominals) {
  // Write your solution here!!!

  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> nominals(n);
  for (int i = 0; i < n; ++i) {
    cin >> nominals[i];
  }

  cout << findMinBadAmount(nominals) << endl;
}
