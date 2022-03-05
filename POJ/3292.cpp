// =====================================================================================================================
// http://poj.org/problem?id=3292
// =====================================================================================================================
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int H = 1000001;
  int N = (H - 1) / 4;

  vector<int> isHPrime(N + 1, 1);
  isHPrime[0] = 0;
  for (int x = 5; x <= H; x += 4) {
    int i = (x - 1) / 4;
    if (isHPrime[i]) {
      for (int y = 5; x * y <= H; y += 4) {
        int j = (x * y - 1) / 4;
        isHPrime[j] = 0;
      }
    }
  }

  vector<int> semiHPrime(N + 1);
  for (int x = 5; x * x <= H; x += 4) {
    int i = (x - 1) / 4;
    if (isHPrime[i]) {
      int y = H / x;
      int j = (y - 1) / 4;
      for (int k = i; k <= j; ++k) {
        if (isHPrime[k]) {
          int t = (x * (k * 4 + 1) - 1) / 4;
          semiHPrime[t] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    semiHPrime[i] += semiHPrime[i - 1];
  }

  int h;
  while ((cin >> h) && h) {
    cout << h << ' ' << semiHPrime[(h - 1) / 4] << '\n';
  }
  return 0;
}
