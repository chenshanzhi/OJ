// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/0033
// =====================================================================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  while (N--) {
    int l = 0;
    int r = 0;
    int curr;
    bool flag = true;
    for (int i = 0; i < 10; ++i) {
      cin >> curr;

      if (curr < l) {
        flag = false;
      } else if (curr < r) {
        l = curr;
      } else {
        r = curr;
      }
      if (l > r) {
        swap(l, r);
      }
    }

    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}