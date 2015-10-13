#include <iostream>

using namespace std;

const int N = 10 * 1000 * 1000;

char isPr[N], isPo[N];
int pi[N];
int rub[N];

void Eratosphen(int n) {
  for (int i = 0; i < n; ++i)
    isPr[i] = 1;

  for (int i = 2; i * i < n; ++i) {
    if (isPr[i]) {
      for (int j = i * i; j < n; j += i)
	isPr[j] = 0;
    }
  }
}

void addPo(int half) {
  int n = half;
  int ans = half;
  while (n) {
    ans = 10 * ans + (n % 10);
    n /= 10;
  }
  
  if (ans < N)
    isPo[ans] = 1;
}

void addPo(int half, int dig) {
  int n = half;
  int ans = half * 10 + dig;
  while (n) {
    ans = 10 * ans + (n % 10);
    n /= 10;
  }
  
  if (ans < N)
    isPo[ans] = 1;
}


void init() {
  Eratosphen(N);
  pi[1] = 0;
  for (int i = 2; i < N; ++i)
    pi[i] = pi[i-1] + isPr[i];

  for (int i = 1; i < 10; ++i) {
    isPo[i] = 1;
    isPo[i * 10 + i] = 1;
  }

  for (int i = 1; i < 10000; ++i) {
    addPo(i);
    for (int dig = 0; dig < 10; ++dig)
      addPo(i, dig);
  }
  rub[1] = isPo[1];
  for (int i = 2; i < N; ++i)
    rub[i] = rub[i-1] + isPo[i];
}

int main() {
  init();
  long long p,q;
  cin >> p >> q;

  for (int n = N-1; n > 0; --n) {
    if (pi[n] * q <= p * rub[n]) {
      cout << n << endl;
      break;
    }
  }
  
  return 0;
}
