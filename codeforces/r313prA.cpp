#include <iostream>

using namespace std;

int a[6];

int main() {
  for (int i = 0; i < 6; ++i)
    cin >> a[i];

  int sum = 0;

  int r1 = min(a[1], a[5]);
  int r3 = min(a[2], a[4]);
  int r2 = a[1] + a[2] - r1 - r3;

  int k = 2 * a[0] + 1;
  for (int i = 0; i < r1; ++i) {
    sum += k;
    k += 2;
  }

  sum += (k-1) * r2;

  k = 2 * a[3] + 1;
  for (int i = 0; i < r3; ++i) {
    sum += k;
    k += 2;
  }

  cout << sum << endl;
  return 0;
}
