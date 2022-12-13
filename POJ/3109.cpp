// ============================================================================
// http://poj.org/problem?id=3109
// ============================================================================
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

struct P {
  int x, y;
};
bool cmp_x(const P &l, const P &r) { return l.x < r.x; }
bool cmp_y(const P &l, const P &r) { return l.y < r.y; }
bool cmp_xy(const P &l, const P &r) {
  return l.x < r.x || (l.x == r.x && l.y < r.y);
}

void compress(vector<P> &a) {
  int n = a.size();
  vector<P> t(a);
  sort(t.begin(), t.end(), cmp_x);
  for (int i = 0; i < n; ++i) {
    a[i].x = lower_bound(t.begin(), t.end(), a[i], cmp_x) - t.begin() + 1;
  }
  sort(t.begin(), t.end(), cmp_y);
  for (int i = 0; i < n; ++i) {
    a[i].y = lower_bound(t.begin(), t.end(), a[i], cmp_y) - t.begin() + 1;
  }
}

int sum(vector<int> &a, int i) {
  int s = 0;
  while (i > 0) {
    s += a[i];
    i -= (i & -i);
  }
  return s;
}
void add(vector<int> &a, int n, int i, int x) {
  while (i <= n) {
    a[i] += x;
    i += (i & -i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<P> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].x >> v[i].y;
  }
  compress(v);

  sort(v.begin(), v.end(), cmp_xy);

  vector<int> xMin(n + 1, INT_MAX);
  vector<int> xMax(n + 1, INT_MIN);
  for (int i = 0; i < n; ++i) {
    int x = v[i].x;
    int y = v[i].y;
    xMin[y] = min(xMin[y], x);
    xMax[y] = max(xMax[y], x);
  }

  int ret = 0;
  vector<int> yBIT(n + 1);
  int y_min;
  for (int i = 0; i < n; ++i) {
    int x = v[i].x;
    int y = v[i].y;
    if (i == 0 || x != v[i - 1].x) {
      y_min = y;
    }
    if (x == xMin[y]) {
      add(yBIT, n, y, 1);
    }
    if (x == xMax[y]) {
      add(yBIT, n, y, -1);
      ++ret;
    }
    if (i == n - 1 || x != v[i + 1].x) {
      ret += sum(yBIT, y) - sum(yBIT, y_min - 1);
    }
  }
  cout << ret << '\n';
  return 0;
}
