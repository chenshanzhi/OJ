// ============================================================================
// http://poj.org/problem?id=3368
// ============================================================================
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

#define MAX_N 100000

struct Range {
  int v_min, v_max;
  int n_min, n_max;
  int n_mode;
  void set(int v, int n) {
    v_min = v;
    v_max = v;
    n_min = n;
    n_max = n;
    n_mode = n;
  }
};

int A[MAX_N];
int N;
Range tree[MAX_N * 4];

void merge(const Range &lc, const Range &rc, Range &ret) {
  ret.v_min = lc.v_min;
  ret.v_max = rc.v_max;

  if (lc.v_max < rc.v_min) {
    ret.n_min = lc.n_min;
    ret.n_max = rc.n_max;
    ret.n_mode = max(lc.n_mode, rc.n_mode);
  } else if (lc.v_max == rc.v_min) {
    int v_mid = lc.v_max;
    int n_mid = lc.n_max + rc.n_min;

    ret.n_min = lc.n_min;
    if (lc.v_min == v_mid) {
      ret.n_min = n_mid;
    }

    ret.n_max = rc.n_max;
    if (rc.v_max == v_mid) {
      ret.n_max = n_mid;
    }

    ret.n_mode = max(lc.n_mode, rc.n_mode);
    ret.n_mode = max(ret.n_mode, n_mid);
  }
}

void build(int l, int r, int k) {
  if (l + 1 == r) {
    tree[k].set(A[l], 1);
    return;
  }

  int m = l + (r - l) / 2;
  build(l, m, k * 2 + 1);
  build(m, r, k * 2 + 2);
  merge(tree[k * 2 + 1], tree[k * 2 + 2], tree[k]);
}

void init(int n) {
  build(0, n, 0);
}

Range query(int a, int b, int l, int r, int k) {
  Range ret;
  if (r <= a) {
    ret.set(A[a], 0);
  } else if (b <= l) {
    ret.set(A[b - 1], 0);
  } else if (a <= l && r <= b) {
    ret = tree[k];
  } else {
    int m = l + (r - l) / 2;
    Range lc = query(a, b, l, m,  k * 2 + 1);
    Range rc = query(a, b, m, r,  k * 2 + 2);
    merge(lc, rc, ret);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while ((cin >> N) && N != 0) {
    int Q;
    cin >> Q;

    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }

    build(0, N, 0);

    for (int i = 0; i < Q; ++i) {
      int a, b;
      cin >> a >> b;
      Range t = query(a - 1, b, 0, N, 0);
      cout << t.n_mode << '\n';
    }
  }
  return 0;
}
