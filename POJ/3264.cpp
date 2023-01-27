// ============================================================================
// http://poj.org/problem?id=3264
// ============================================================================
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N (1 << 16)

int H[MAX_N * 2 - 1];
int L[MAX_N * 2 - 1];
int n;

void init(int m) {
  n = 1;
  while (n < m) {
    n *= 2;
  }

  for (int i = 0; i < n * 2 - 1; ++i) {
    H[i] = INT_MIN;
    L[i] = INT_MAX;
  }
}

void update(int k, int x) {
  int t = k + n - 1;
  H[t] = x;
  L[t] = x;
  while (t > 0) {
    t = (t - 1) / 2;
    H[t] = max(H[t * 2 + 1], H[t * 2 + 2]);
    L[t] = min(L[t * 2 + 1], L[t * 2 + 2]);
  }
}

int queryH(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) {
    return INT_MIN;
  } else if (a <= l && r <= b) {
    return H[k];
  } else {
    int vl = queryH(a, b, 2 * k + 1, l, (l + r) / 2);
    int vr = queryH(a, b, 2 * k + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
}

int queryL(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) {
    return INT_MAX;
  } else if (a <= l && r <= b) {
    return L[k];
  } else {
    int vl = queryL(a, b, 2 * k + 1, l, (l + r) / 2);
    int vr = queryL(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
}

int query(int a, int b) {
  int x = queryH(a, b, 0, 0, n);
  int y = queryL(a, b, 0, 0, n);
  return x - y;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;

  init(N);
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    update(i, x);
  }
  for (int i = 0; i < Q; ++i) {
    int a, b;
    cin >> a >> b;
    cout << query(a - 1, b) << '\n';
  }

  return 0;
}
