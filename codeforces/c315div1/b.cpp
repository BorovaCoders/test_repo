#include <iostream>

using namespace std;

typedef long long ll;
const int M = 1000000007;

const int N = 4111;

int eqk[N][N]; // n - power, k - num eq groups
int ck[N][N];

int NumContr(int n) {
  // num eq
  eqk[1][1] = 1;
  for (int i = 2; i <= n; ++i) {
    eqk[i][1] = 1;
    eqk[i][i] = 1;
    for (int k = 2; k < i; ++k) {
      eqk[i][k] = (eqk[i-1][k-1] + k * (ll)eqk[i-1][k]) % M;
    }
  }

  // num contr with k groups
  ck[1][0] = 1;
  for (int i = 2; i <= n; ++i) {
    ck[i][0] = 1;
    ck[i][i-1] = i; // ???
    for (int k = 1; k < i-1; ++k) {
      ck[i][k] = ((ll)eqk[i-1][k] + (ll)ck[i-1][k] +
		  ck[i-1][k-1] + k*(ll)ck[i-1][k]) % M;
    }
  }

  ll ans = 0;
  for (int k = 0; k <= n-1; ++k) {
    ans += ck[n][k];
  }
  ans %= M;
  
  return ans;
}

int main() {
  int n;
  cin >> n;

  cout << NumContr(n) << endl;
  
  return 0;
}
