// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/0531
// =====================================================================================================================
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1024

int W, H, N;
int X1[MAX_N];
int Y1[MAX_N];
int X2[MAX_N];
int Y2[MAX_N];

int M[MAX_N * 4][MAX_N * 4];

int compress(int *x1, int *x2, int n, int x_max) {
  vector<int> xs;
  for (int i = 0; i < n; ++i) {
    int t1 = x1[i] - 1;
    if (1 <= t1 && t1 <= x_max) {
      xs.push_back(t1);
    }
    xs.push_back(x1[i]);
    xs.push_back(x2[i]);
    int t2 = x2[i] + 1;
    if (1 <= t2 && t2 <= x_max) {
      xs.push_back(t2);
    }
  }

  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());

  for (int i = 0; i < n; ++i) {
    x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
    x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
  }
  return xs.size();
}

int bfs() {
  const int dx[4] = { 0, -1, 1, 0 };
  const int dy[4] = { -1, 0, 0, 1 };
  int ret = 0;
  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      if (M[y][x]) {
        continue;
      }

      ++ret;

      queue<pair<int, int>> Q;
      Q.push({x, y});
      M[y][x] = 1;
      while (!Q.empty()) {
        int sx = Q.front().first;
        int sy = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; ++i) {
          int tx = sx + dx[i];
          int ty = sy + dy[i];
          if (0 <= tx && tx < W && 0 <= ty && ty < H && M[ty][tx] == 0) {
            Q.push({tx, ty});
            M[ty][tx] = 1;
          }
        }
      }
    }
  }
  return ret;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while ((cin >> W >> H) && W != 0 && H != 0) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
      X1[i]++;
      Y1[i]++;
    }

    W = compress(X1, X2, N, W);
    H = compress(Y1, Y2, N, H);

    memset(M, 0, sizeof(M));
    for (int i = 0; i < N; ++i) {
      for (int y = Y1[i]; y <= Y2[i]; ++y) {
        for (int x = X1[i]; x <= X2[i]; ++x) {
          M[y][x] = 1;
        }
      }
    }
    cout << bfs() << '\n';
  }

  return 0;
}

