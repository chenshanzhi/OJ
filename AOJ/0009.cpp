// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/0009
// =====================================================================================================================
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N = 999999;
  vector<int> v(N + 1, 1);
  v[0] = v[1] = 0;
  for (int i = 2; i * i <= N; ++i) {
    if (v[i]) {
      for (int j = i + i; j <= N; j += i) {
        v[j] = 0;
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    v[i] += v[i - 1];
  }
  int n;
  while (cin >> n) {
    cout << v[n] << '\n';
  }
  return 0;
}