#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int M = 1000000007;
const int N = 200111;

int fact[N], ifact[N];

typedef long long ll;

// Extended Euclid algorithm to compute Greatest Common Divisor.
// gcd(a, b) == max d such as (a % d == 0 && b % d == 0).
// Moreover we could find such x and y that: gcd(a, b) == a*x + b*y
ll extGcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  ll xx, yy;
  ll d = extGcd(b, a % b, xx, yy);
  // b * xx + (a - [a/b] * b) * yy
  x = yy;
  y = xx - yy * (a / b);
  return d;
}

// This function calculated inverted number by modulo P.
// Such number x that  x * a == 1 (mod P).
// In other C++ words:   (x * a) % P == 1
int invModP(int a, int P) {
  // a * x + P * y == 1 => a * x == 1 (mod P)
  ll x, y;
  extGcd(a, P, x, y);
  while (x < 0)
    x += P;
  
  return x % P;
}

void init() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = (i * (ll)fact[i-1]) % M;
    ifact[i] = invModP(fact[i], M);
  }
}

int CmodM(int n, int k) {
  // n! / (k! * (n-k)!)
  ll ans = fact[n];
  ans = (ans * ifact[k]) % M;
  ans = (ans * ifact[n-k]) % M;
  return (int)ans;
}

int NumWays(int di, int dj) {
  return CmodM(di + dj, di);
}

// You could look how extensivly I have covered my code with tests! :)
// It happens very rarely. Unfortunately(
void testGCD(ll a, ll b) {
  ll x, y;
  ll d = extGcd(a, b, x, y);
  if (a * x + b * y != d) {
    cout << "ERROR gcd\n";
  }
  // debug
  cout << a << " * " << x << " + " << b << " * " << y << " == " << d << endl;
}

void testGCD() {
  testGCD(3, 17);
  testGCD(24, M);
  testGCD(10, 19);
}

void testFact() {
  if (fact[5] != 120) {
    cout << "ERROR wrong result 5! should be 120" << endl;
  }
  if (fact[28] != 35757887) {
    cout << "ERROR 28! is equal to 35757887" << endl;
  }
  const int A = 28;
  ll f = fact[A];
  f = (f * ifact[A]) % M;
  if (f != 1) {
    cout << fact[A] << " " << ifact[A] << " mul: " << f << endl;
    cout << "ERROR inv " << A << endl;
  }
}

void testC() {
  cout << "Manual C test\n";
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j <= i; ++j) {
      cout << CmodM(i, j) << " ";
    }
    cout << endl;
  }

  if (CmodM(28, 2) != 28 * 27 / 2) {
    cout << "Error C(28, 2) should be 378 but we get "
	 <<  CmodM(28, 2) << endl;
  }
  
  if (CmodM(28, 14) != (CmodM(27, 14) + CmodM(27, 13)) % M) {
    cout << "Error C(28, 14) " <<  CmodM(28, 14) << " "
	 << CmodM(27, 14) << " " << CmodM(27, 13) << endl;

    for (int i = 0; i < 28; ++i) {
      //cout << "C(28," << i << ") = " << CmodM(28, i) << endl;
    }
  }
}

void testNumWays() {
  if (NumWays(1, 1) != 2) {
    cout << "Error num ways 2x2" << endl;
  }
  if (NumWays(2, 1) != 3) {
    cout << "Error num ways 3x2" << endl;
  }
  if (NumWays(1, 2) != 3) {
    cout << "Error num ways 2x3" << endl;
  }
  if (NumWays(5, 5) != CmodM(10, 5)) {
    cout << "Error num ways 6x6" << endl;
  }
  if (NumWays(14, 14) != (NumWays(14, 13) + NumWays(13, 14)) % M) {
    cout << "Error num ways 15x15" << endl;
    cout << NumWays(14, 14) << " " <<  NumWays(13, 14) << " "
	 <<  NumWays(14, 13);
  }
  
}

void testAll() {
  testGCD();
  testFact();
  testC();
  testNumWays();
}

int main() {
  init();
  //testAll();
  int X, Y, n;
  cin >> X >> Y >> n;
  vector< pair<int, int> > bs(n);
  for (int i = 0; i < n; ++i) {
    cin >> bs[i].first >> bs[i].second;
  }

  sort(bs.begin(), bs.end());

  ll ans = NumWays(X-1, Y-1);
  //cout << "No bad ans: " << ans << endl;
  vector<int> num2b(n);
  for (int i = 0; i < n; ++i) {
    ll num2bi = NumWays(bs[i].first - 1, bs[i].second - 1);
    for (int j = 0; j < i; ++j) {
      if (bs[j].first <= bs[i].first && bs[j].second <= bs[i].second) {
	ll d = ((ll)num2b[j]
		* NumWays(bs[i].first - bs[j].first,
			  bs[i].second - bs[j].second)
		) % M;
	num2bi = (num2bi - d + M) % M;
      }
    }
    num2b[i] = (int)num2bi;
    
    ll dans = (num2bi * NumWays(X - bs[i].first, Y - bs[i].second)) % M;
    //    cout << i << " n2bi " << num2bi << " dans: " << dans << endl;
    ans = (ans - dans + M) % M;
  }

  cout << ans << endl;
  
  return 0;
}
