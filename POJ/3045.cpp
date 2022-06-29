// ============================================================================
// http://poj.org/problem?id=3045
// ============================================================================
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

typedef long long ll;

#define MAX_N 50000

int N;
int W[MAX_N + 1];
int S[MAX_N + 1];
int T[MAX_N + 1];
bool cmp(int i, int j) { return W[i] + S[i] < W[j] + S[j]; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> W[i] >> S[i];
    T[i] = i;
  }
  sort(T, T + N, cmp);

  int ps = 0;
  int ret = INT_MIN;
  for (int i = 0; i < N; ++i) {
    int k = T[i];
    ret = max(ret, ps - S[k]);
    ps += W[k];
  }
  cout << ret << '\n';

  return 0;
}
