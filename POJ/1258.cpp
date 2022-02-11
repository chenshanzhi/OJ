// =====================================================================================================================
// http://poj.org/problem?id=1258
// =====================================================================================================================
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &S, int i) {
  return S[i] < 0 ? i : (S[i] = find(S, S[i]));
}
void unite(vector<int> &S, int i, int j) {
  if (S[j] < S[i]) {
    S[i] = j;
  } else {
    if (S[i] == S[j]) {
      S[i]--;
    }
    S[j] = i;
  }
}

struct Edge {
  int i, j, w;
};
bool operator<(const Edge &lhs, const Edge &rhs) {
  return lhs.w < rhs.w;
}
int Kruskal(vector<int> &S, vector<Edge> &es) {
  int ret = 0;
  int E = es.size();
  sort(es.begin(), es.end());
  for (int k = 0; k < E; ++k) {
    int i = find(S, es[k].i);
    int j = find(S, es[k].j);
    if (i != j) {
      ret += es[k].w;
      unite(S, i, j);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  while (cin >> N) {
    vector<vector<int> > G(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> G[i][j];
      }
    }
    vector<Edge> es;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        es.push_back((Edge){ i, j, G[i][j] });
      }
    }
    vector<int> S(N, -1);
    cout << Kruskal(S, es) << '\n';
  }

  return 0;
}