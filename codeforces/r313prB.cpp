#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool codePairs(const vector<int>& v1,
	       const vector<int>& v2,
	       vector<int>& t1,
	       vector<int>& t2) {
  const int n = v1.size();
  t1.resize(n / 2);
  t2.resize(n / 2);
  
  map< pair<int, int>, int> pcodes;
  map< pair<int, int>, int>::iterator it;
  int pcode = 1, cpc;
  for (int i = 0; i < v1.size(); i += 2) {
    pair<int, int> p  = make_pair(v1[i], v1[i+1]);
    pair<int, int> ip = make_pair(v1[i+1], v1[i]);
    it = pcodes.find(p);
    if (it == pcodes.end()) {
      cpc = pcode++;
      pcodes[p] = cpc;
      pcodes[ip] = cpc;
    } else {
      cpc = it->second;
    }
    t1[i/2] = cpc;
  }

  for (int i = 0; i < v2.size(); i += 2) {
    pair<int, int> p  = make_pair(v2[i], v2[i+1]);
    it = pcodes.find(p);
    if (it == pcodes.end()) {
      return false;
    } else {
      cpc = it->second;
    }
    t2[i/2] = cpc;
  }
  return true;
}

bool isEqual(const string& s1, const string& s2) {
  if (s1.size() != s2.size())
    return false;

  int n = s1.size();
  int b = n;
  while (b % 2 == 0) {
    b /= 2;
  }

  map<string, int> codes;
  map<string, int>::iterator it;
  vector<int> v1(n/b), v2(n/b);
  int code = 1, cc;
  for (int i = 0, iv = 0; i < s1.size(); i += b, ++iv) {
    string sm = s1.substr(i, b);
    it = codes.find(sm);
    if (it == codes.end()) {
      cc = code++;
      codes[sm] = cc;
    } else {
      cc = it->second;
    }
    v1[iv] = cc; 
  }

  for (int i = 0, iv = 0; i < s2.size(); i += b, ++iv) {
    string sm = s2.substr(i, b);
    it = codes.find(sm);
    if (it == codes.end()) {
      return false;
    } else {
      cc = it->second;
    }
    v2[iv] = cc; 
  }

  vector<int> t1, t2;
  while (v1.size() > 1) {
    if (!codePairs(v1, v2, t1, t2)) {
      return false;
    } else {
      swap(v1, t1);
      swap(v2, t2);
    }
  }

  return v1[0] == v2[0];
}

int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  
  bool eq = isEqual(s1, s2);

  cout << (eq ? "YES" : "NO") << endl;
  return 0;
}
