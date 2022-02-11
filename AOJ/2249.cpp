// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/2249
// =====================================================================================================================
#include <numeric>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 10000
#define MAX_D 10000000
#define MAX_C 10000000

struct Edge {
  int s, t, d, c;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  while ((cin >> N >> M) && !(N == 0 && M == 0)) {
    vector<Edge> edges;
    for (int i = 0; i < M; ++i) {
      int u, v, d, c;
      cin >> u >> v >> d >> c;
      edges.push_back((Edge) { u - 1, v - 1, d, c });
      edges.push_back((Edge) { v - 1, u - 1, d, c });
    }

    vector<int> D(N, MAX_D), C(N, MAX_C);
    D[0] = C[0] = 0;
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < M * 2; ++j) {
        int s = edges[j].s;
        int t = edges[j].t;
        int d = edges[j].d;
        int c = edges[j].c;

        if ((D[s] + d < D[t]) || (D[s] + d == D[t] && c < C[t])) {
          D[t] = D[s] + d;
          C[t] = c;
        }
      }
    }
    cout << accumulate(C.begin(), C.end(), 0) << '\n';
  }

  return 0;
}
