// =====================================================================================================================
// http://poj.org/problem?id=3977
// =====================================================================================================================

#include <algorithm>
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

#define MAX_N 35
#define MAX_N1 18

typedef long long ll;
struct T {
  ll sum;
  int num;
  T(ll s = 0, int n = 0) : sum(s), num(n) {}
  bool operator<(const T &rhs) const {
    return sum < rhs.sum || (sum == rhs.sum && num < rhs.num);
  }
};

int N;
ll input[MAX_N];
T A[1 << MAX_N1];

ll min_abs_sum;
int min_num;

void update(ll curr_sum, int curr_num) {
  ll curr_abs_sum = abs(curr_sum);
  if (curr_abs_sum < min_abs_sum) {
    min_abs_sum = curr_abs_sum;
    min_num = curr_num;
  } else if (curr_abs_sum == min_abs_sum) {
    min_num = min(min_num, curr_num);
  }
}

int sort_and_unique(T *a, int n) {
  sort(a, a + n);
  int t = 0;
  for (int i = 1; i < n; ++i) {
    if (a[t].sum != a[i].sum && ++t != i) {
      a[t].sum = a[i].sum;
      a[t].num = a[i].num;
    }
  }
  return ++t;
}

void solve() {
  min_abs_sum = numeric_limits<ll>::max();
  min_num = numeric_limits<int>::max();

  // Enumerate results from the 1st part
  int n1 = min(MAX_N1, N);
  int nA = (1 << n1) - 1;
  for (int i = 1; i <= nA; ++i) {
    ll curr_sum = 0;
    int curr_num = 0;
    for (int j = 0, mask = 1; j < n1; ++j, mask <<= 1) {
      if (i & mask) {
        curr_sum += input[j];
        ++curr_num;
      }
    }
    update(curr_sum, curr_num);

    A[i - 1].sum = curr_sum;
    A[i - 1].num = curr_num;
  }

  if (n1 == N) {
    return;
  }

  // Sort and Unique
  int nX = sort_and_unique(A, nA);

  // Enumerate results from the 2nd part. 
  int n2 = N - n1;
  int nB = (1 << n2) - 1;
  for (int i = 1; i <= nB; ++i) {
    ll curr_sum = 0;
    int curr_num = 0;
    for (int j = 0, mask = 1; j < n2; ++j, mask <<= 1) {
      if (i & mask) {
        curr_sum += input[n1 + j];
        ++curr_num;
      }
    }
    update(curr_sum, curr_num);

    T mid(-curr_sum, 0);
    T *p = lower_bound(A, A + nX, mid);
    if (p != A + nA) {
      update(p->sum + curr_sum, p->num + curr_num);
    }
    if (p != A) {
      --p;
      update(p->sum + curr_sum, p->num + curr_num);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while ((cin >> N) && N != 0) {
    for (int i = 0; i < N; ++i) {
      cin >> input[i];
    }
    solve();
    cout << min_abs_sum << ' ' << min_num << '\n';
  }
  return 0;
}
