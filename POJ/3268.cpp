
// =====================================================================================================================
// http://poj.org/problem?id=3268
// =====================================================================================================================
#include <iostream>
#include <vector>
using namespace std;

#define MAX_T 1000000

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, X;
  cin >> N >> M >> X;
  vector<int> A(M), B(M), T(M);
  for (int i = 0; i < M; ++i) {
    cin >> A[i] >> B[i] >> T[i];
  }

  vector<int> ds(N + 1, MAX_T), dt(N + 1, MAX_T);
  ds[X] = dt[X] = 0;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int a = A[j], b = B[j], t = T[j];
      ds[a] = min(ds[a], ds[b] + t);
      dt[b] = min(dt[b], dt[a] + t);
    }
  }

  int ret = 0;
  for (int i = 1; i <= N; ++i) {
    ret = max(ret, ds[i] + dt[i]);
  }
  cout << ret << '\n';

  return 0;
}