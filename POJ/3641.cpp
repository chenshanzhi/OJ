// =====================================================================================================================
// http://poj.org/problem?id=3641
// =====================================================================================================================
#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull modPow(ull x, ull n, ull m) {
  ull ret = 1;
  while (n) {
    if (n & 1) {
      ret = ret * x % m;
    }
    x = x * x % m;
    n >>= 1;
  }
  return ret;
}

bool isPrime(ull x) {
  for (ull i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ull p, a;
  while ((cin >> p >> a) && !(p == 0 && a == 0)) {
    if (!isPrime(p) && modPow(a, p, p) == a) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}