// =====================================================================================================================
// http://poj.org/problem?id=3009
// =====================================================================================================================

#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_H 21
#define MAX_W 21
#define MAX_T 11

#define POS_EMPTY 0
#define POS_BLOCK 1
#define POS_START 2
#define POS_GOAL  3

int W, H;
int G[MAX_H][MAX_W];
int s_i, s_j;
int g_i, g_j;

const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, -1, 1, 0 };

void dfs(int i, int j, int count, int &min_step) {
  if (count >= min_step) {
    return;
  }

  for (int k = 0; k < 4; ++k) {
    int y = i;
    int x = j;
    int u = i + dy[k];
    int v = j + dx[k];
    if (!(u >= 0 && u < H && v >= 0 && v < W) || G[u][v] == POS_BLOCK) {
      continue;
    }

    while (true) {
      if (!(u >= 0 && u < H && v >= 0 && v < W)) {
        break;
      }

      if (G[u][v] == POS_GOAL) {
        min_step = min(min_step, count + 1);
        break;
      }

      if (G[u][v] == POS_BLOCK) {
        G[u][v] = POS_EMPTY;
        dfs(y, x, count + 1, min_step);
        G[u][v] = POS_BLOCK;
        break;
      }

      y = u;
      x = v;
      u += dy[k];
      v += dx[k];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while ((cin >> W >> H) && !(W == 0 && H == 0)) {
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        int v;
        cin >> v;
        G[i][j] = v;

        if (v == POS_START) {
          s_i = i;
          s_j = j;
        }
      }
    }

    int ret = MAX_T;
    dfs(s_i, s_j, 0, ret);
    cout << (ret == MAX_T ? -1 : ret) << '\n';
  }
  return 0;
}