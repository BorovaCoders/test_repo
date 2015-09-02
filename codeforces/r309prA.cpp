// http://codeforces.com/contest/553/problem/A

#include <iostream>
using namespace std;

const int N = 1001;
const int M = 1000000007;

int C[N][N];
int c[N];

void initC() {
  C[0][0] = 1;
  for (int n = 1; n < N; ++n) {
    C[n][0] = 1;
    C[n][n] = 1;
    for (int k = 1; k < n; ++k)
      C[n][k] = (C[n-1][k] + C[n-1][k-1]) % M;
  }
}

int f[N][2];

typedef long long ll;

int solve(int k) {
  ll ans = 1;
  int n = c[0];
  for (int i = 1; i < k; ++i) {
    ans = (C[n + c[i] - 1][n] * ans) % M;
    n += c[i];
  }
  return ans;
}

int main() {
  initC();

  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> c[i];
  }

  cout << solve(k) << endl;
  return 0;
}
