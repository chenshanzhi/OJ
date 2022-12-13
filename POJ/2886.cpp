// ============================================================================
// http://poj.org/problem?id=2886
// ============================================================================
#include <cstdio>
#include <vector>
using namespace std;

#define MAX_N 500000
#define MAX_C 10

int N, K;
char names[MAX_N + 1][MAX_C + 1];
int cards[MAX_N + 1];

// Highly composite number calculation
// 2 * 3 * 5 * 7 * 11 * 13 * 17 = 510510 > 500000 = MAX_N
const int primes[] = { 2, 3, 5, 7, 11, 13, 17 };
const int MAX_P = sizeof(primes) / sizeof(*primes);
int D;
int H;
void dfs(int idx, int val, int d, int prev_exp) {
  if (idx > MAX_P || val > N) {
    return;
  }
  if (d > D) {
    D = d;
    H = val;
  } else if (d == D) {
    H = min(H, val);
  }

  int x = val;
  for (int i = 1; i <= prev_exp; ++i) {
    if (N / x < primes[idx]) {
      break;
    }
    x *= primes[idx];
    dfs(idx + 1, x, d * (i + 1), i);
  }
}

void hcn() {
  const int MAX_E = 20; // 2^20 > 500000 = MAX_N
  D = 1;
  H = 1;
  dfs(0, 1, 1, MAX_E);
}

int sum(vector<int> &v, int i) {
  int s = 0;
  while (i > 0) {
    s += v[i];
    i -= (i & -i);
  }
  return s;
}

void add(vector<int> &v, int n, int i, int e) {
  while (i <= n) {
    v[i] += e;
    i += (i & -i);
  }
}

int find_sum(vector<int> &v, int n, int s) {
  int l = 1, r = n + 1;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (sum(v, m) < s) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}

int main() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; ++i) {
    scanf("%s%d", names[i], &cards[i]);
  }

  hcn();

  vector<int> v(N + 1);
  for (int i = 1; i <= N; ++i) {
    add(v, N, i, 1);
  }

  int k = K;
  int s = K;
  for (int h = 1; h < H; ++h) {
    add(v, N, k, -1);

    int d = cards[k];
    int r = N - h;
    if (d < 0) {
      s = ((s - 1 + d) % r + r) % r + 1;
    } else {
      s = ((s - 2 + d) % r + r) % r + 1;
    }
    k = find_sum(v, N, s);
  }
  printf("%s %d\n", names[k], D);

  return 0;
}

