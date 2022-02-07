// =====================================================================================================================
// http://poj.org/problem?id=2236
// =====================================================================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX_N 1001

int N;
int D;
int X[MAX_N];
int Y[MAX_N];
int S[MAX_N];
int R[MAX_N];

int find(int i) {
  if (S[i] == i) {
    return i;
  }
  return S[i] = find(S[i]);
}
void unite(int i, int j) {
  if (R[i] < R[j]) {
    S[i] = j;
  } else {
    S[j] = i;
    if (R[i] == R[j]) {
      R[i]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> D;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
    S[i] = i;
    R[i] = 0;
  }

  vector<vector<int> > G(N);
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int dx = X[i] - X[j];
      int dy = Y[i] - Y[j];
      if (dx * dx + dy * dy <= D * D) {
        G[i].push_back(j);
        G[j].push_back(i);
      }
    }
  }

  vector<int> repaired(N, false);
  string s;
  int p, q;
  while (cin >> s) {
    if (s[0] == 'O') {
      cin >> p;
      repaired[p - 1] = true;
      for (int i = 0; i < G[p - 1].size(); ++i) {
        if (repaired[G[p - 1][i]]) {
          int r1 = find(p - 1);
          int r2 = find(G[p - 1][i]);
          if (r1 != r2) {
            unite(r1, r2);
          }
        }
      }
    } else {
      cin >> p >> q;
      if (repaired[p - 1] && repaired[q - 1] && find(p - 1) == find(q - 1)) {
        cout << "SUCCESS\n";
      } else {
        cout << "FAIL\n";
      }
    }
  }

  return 0;
}