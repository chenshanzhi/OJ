// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/0118
// =====================================================================================================================

#include <bits/stdc++.h>
using namespace std;

#define MAX_W 101
#define MAX_H 101

const int d[4][2] = {{ -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 }};
int H, W;
int G[MAX_H][MAX_W];

void dfs(int i, int j, int mark)
{
  G[i][j] = 'x';
  for (int k = 0; k < 4; ++k) {
    int u = i + d[k][0];
    int v = j + d[k][1];
    if (0 <= u && u < H && 0 <= v && v < W && G[u][v] == mark) {
      dfs(u, v, mark);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str;

  while (true) {
    cin >> H >> W;
    if (H == 0 && W == 0) {
      break;
    }

    for (int i = 0; i < H; ++i) {
      cin >> str;
      for (int j = 0; j < W; ++j) {
        G[i][j] = str[j];
      }
    }

    int count = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        int mark = G[i][j];
        if (mark != 'x') {
          ++count;
          dfs(i, j, mark);
        }
      }
    }

    cout << count << '\n';
  }

  return 0;
}