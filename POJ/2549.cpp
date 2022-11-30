// =====================================================================================================================
// http://poj.org/problem?id=2549
// =====================================================================================================================

#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 1000

typedef long long ll;

ll X[MAX_N + 1];

bool three_sum(ll *X, int n, ll d) {
  for (int i = 0; i < n - 2; ++i) {
    ll a = X[i];
    int first = i + 1;
    int last = n - 1;
    while (first < last) {
      ll b = X[first];
      ll c = X[last];
      if (a + b + c == d) {
        if (d != a && d != b && d != c) {
          return true;
        }
        ++first;
        --last;
      } else if (a + b + c < d) {
        ++first;
      } else if (a + b + c > d) {
        --last;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while ((cin >> n) && n != 0) {
    for (int i = 0; i < n; ++i) {
      cin >> X[i];
    }
    sort(X, X + n);

    int i;
    for (i = n - 1; i >= 0; --i) {
      if (three_sum(X, n, X[i])) {
        break;
      }
    }

    if (i == -1) {
      cout << "no solution\n";
    } else {
      cout << X[i] << '\n';
    }
  }
  return 0;
}
