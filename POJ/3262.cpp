// =====================================================================================================================
// http://poj.org/problem?id=3262
// =====================================================================================================================

#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

#define MAX_N 100001
typedef long long ll;

int N;
ll T[MAX_N];
ll D[MAX_N];
int indices[MAX_N];

bool cmp(int i, int j) { return D[i] * T[j] > D[j] * T[i]; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> T[i] >> D[i];
    indices[i] = i;
  }
  sort(indices, indices + N, cmp);

  ll ret = 0;
  ll t = 0;
  for (int k = 0; k < N; ++k) {
    int i = indices[k];
    ret += D[i] * t;
    t += 2 * T[i];
  }
  cout << ret << '\n';

  return 0;
}