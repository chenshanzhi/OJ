// =====================================================================================================================
// http://poj.org/problem?id=2377
// =====================================================================================================================
#include <iostream>
#include <vector>
#include <algorithm>
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
  int a, b, c;
};
bool operator<(const Edge &lhs, const Edge &rhs) {
  return lhs.c > rhs.c;
}
int Kruskal(vector<int> &S, vector<Edge> &es) {
  int ret = 0;
  for (int i = 0; i < es.size(); ++i) {
    int a = find(S, es[i].a);
    int b = find(S, es[i].b);
    if (a != b) {
      ret += es[i].c;
      unite(S, a, b);
    }
  }
  int count = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] < 0) {
      ++count;
    }
  }
  return count == 1 ? ret : -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<Edge> es;
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    es.push_back((Edge){ a, b, c });
  }
  sort(es.begin(), es.end());
  vector<int> S(N, -1);
  cout << Kruskal(S, es) << '\n';
  return 0;
}