// =====================================================================================================================
// http://poj.org/problem?id=1995
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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ull Z, M, H, A, B;
  cin >> Z;
  while (Z--) {
    ull ret = 0;
    cin >> M >> H;
    while (H--) {
      cin >> A >> B;
      ret = (ret + modPow(A, B, M)) % M;
    }
    cout << ret << '\n';
  }

  return 0;
}