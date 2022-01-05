// =====================================================================================================================
// http://poj.org/problem?id=1979
// =====================================================================================================================

#include <iostream>
using namespace std;

#define MAX_W 25
#define MAX_H 25

const int d[4][2] = {{ -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 }};
int W, H;
int G[MAX_W][MAX_H];

int dfs(int i, int j) {
  int ret = 1;
  G[i][j] = '#';
  for (int k = 0; k < 4; ++k) {
    int u = i + d[k][0];
    int v = j + d[k][1];
    if (0 <= u && u < H && 0 <= v && v < W && G[u][v] == '.') {
      ret += dfs(u, v);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int si, sj;
  string str;

  while (true) {
    cin >> W >> H;
    if (W == 0 && H == 0) {
      break;
    }

    for (int i = 0; i < H; ++i) {
      cin >> str;
      for (int j = 0; j < W; ++j) {
        G[i][j] = str[j];
        if (G[i][j] == '@') {
          si = i;
          sj = j;
        }
      }
    }

    cout << dfs(si, sj) << endl;
  }
  return 0;
}