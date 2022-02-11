// =====================================================================================================================
// http://poj.org/problem?id=2395
// =====================================================================================================================
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &S, int i) {
  return S[i] < 0 ? i : (S[i] = find(S, S[i]));
}
void unite(vector<int> &S, int i, int j) {
  if (S[i] < S[j]) {
    S[j] = i;
  } else {
    if (S[i] == S[j]) {
      S[j]--;
    }
    S[i] = j;
  }
}
struct Edge {
  int a, b, l;
};
bool operator<(const Edge &lhs, const Edge &rhs) {
  return lhs.l < rhs.l;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<Edge> es(M);
  for (int i = 0; i < M; ++i) {
    cin >> es[i].a >> es[i].b >> es[i].l;
  }
  sort(es.begin(), es.end());

  vector<int> S(N, -1);
  int ret = 0;
  for (int i = 0; i < M; ++i) {
    int a = find(S, es[i].a);
    int b = find(S, es[i].b);
    if (a != b) {
      ret = es[i].l;
      unite(S, a, b);
    }
  }
  cout << ret << '\n';
  return 0;
}