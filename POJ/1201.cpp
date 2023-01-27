// ============================================================================
// http://poj.org/problem?id=1201
// ============================================================================

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

#define MAX_AB 50000

struct S {
  int a, b, c;
  bool operator<(const S &rhs) const { return b < rhs.b; }
};

int aN;
vector<int> tree;

void init(int n) {
  aN = 1;
  while (aN < n) {
    aN *= 2;
  }
  tree.resize(aN * 2 - 1, 0);
}

bool point_update(int i) {
  int k = aN - 1 + i;
  if (tree[k] == 1) {
    return false;
  }
  tree[k] = 1;
  while (k > 0) {
    k = (k - 1) / 2;
    tree[k] += 1;
  }
  return true;
}

int range_query(int a, int b, int l, int r, int k) {
  if (r <= a || b <= l) {
    return 0;
  } else if (a <= l && r <= b) {
    return tree[k];
  } else {
    int m = l + (r - l) / 2;
    int vl = range_query(a, b, l, m, k * 2 + 1);
    int vr = range_query(a, b, m, r, k * 2 + 2);
    return vl + vr;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<S> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].a >> v[i].b >> v[i].c;
  }
  sort(v.begin(), v.end());

  init(MAX_AB + 1);
  for (int i = 0; i < n; ++i) {
    int l = v[i].a;
    int r = v[i].b + 1;
    int c = range_query(l, r, 0, aN, 0);
    while (c < v[i].c && l <= --r) {
      if (point_update(r)) {
        ++c;
      }
    }
  }
  cout << tree[0] << '\n';
  return 0;
}
