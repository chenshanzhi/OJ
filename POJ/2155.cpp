// ============================================================================
// http://poj.org/problem?id=2155
// ============================================================================

#include <iostream>
#include <vector>
using namespace std;

int sum_2d(vector<vector<int> > &v, int x, int y) {
  int s = 0;
  for (int i = y; i > 0; i -= (i & -i)) {
    for (int j = x; j > 0; j -= (j & -j)) {
      s += v[i][j];
    }
  }
  return s;
}

void add_2d(vector<vector<int> > &v, int n, int x, int y, int e) {
  for (int i = y; i <= n; i += (i & -i)) {
    for (int j = x; j <= n; j += (j & -j)) {
      v[i][j] += e;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int X, N, T;
  cin >> X;
  while (X--) {
    cin >> N >> T;
    vector<vector<int> > v(N + 2, vector<int>(N + 2));
    while (T--) {
      char ch;
      cin >> ch;
      if (ch == 'C') {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++x2;
        ++y2;
        add_2d(v, N + 1, x1, y1, 1);
        add_2d(v, N + 1, x1, y2, 1);
        add_2d(v, N + 1, x2, y1, 1);
        add_2d(v, N + 1, x2, y2, 1);
      } else {
        int x, y;
        cin >> x >> y;
        cout << (sum_2d(v, x, y) % 2) << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}

