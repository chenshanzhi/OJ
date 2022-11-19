
// =====================================================================================================================
// http://poj.org/problem?id=1222
// =====================================================================================================================

#include <cstring>
#include <iostream>
using namespace std;

#define MAX_R 5
#define MAX_C 6
int input[MAX_R][MAX_C];

const int dy[] = { -1, 0, 0, 0, 1 };
const int dx[] = { 0, -1, 0, 1, 0 };

int flip[MAX_R][MAX_C];
int result[MAX_R][MAX_C];

int get(int i, int j) {
  int ret = input[i][j];
  for (int k = 0; k < 5; ++k) {
    int r = i + dy[k];
    int c = j + dx[k];
    if (0 <= r && r < MAX_R && 0 <= c && c < MAX_C) {
      ret += flip[r][c];
    }
  }
  return ret & 1;
}

int calc() {
  for (int i = 1; i < MAX_R; ++i) {
    for (int j = 0; j < MAX_C; ++j) {
      if (get(i - 1, j) != 0) {
        flip[i][j] = 1;
      }
    }
  }

  for (int j = 0; j < MAX_C; ++j) {
    if (get(MAX_R - 1, j) != 0) {
      return -1;
    }
  }

  int ret = 0;
  for (int i = 0; i < MAX_R; ++i) {
    for (int j = 0; j < MAX_C; ++j) {
      ret += flip[i][j];
    }
  }
  return ret;
}

void solve() {
  int res = -1;

  for (int b = 0; b <= 0x3f; ++b) {

    memset(flip, 0, sizeof(flip));

    int x = b;
    for (int j = 0; j < MAX_C; ++j) {
      flip[0][MAX_C - 1 - j] = x & 1;
      x >>= 1;
    }

    int num = calc();
    if (num >= 0 && (res == -1 || res > num)) {
      res = num;
      memcpy(result, flip, sizeof(flip));
    }
  }

  if (res < 0) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (int i = 0; i < MAX_R; ++i) {
      for (int j = 0; j < MAX_C; ++j) {
        cout << result[i][j] << (j + 1 == MAX_C ? '\n' : ' ');
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int m = 1; m <= n; ++m) {
    for (int i = 0; i < MAX_R; ++i) {
      for (int j = 0; j < MAX_C; ++j) {
        cin >> input[i][j];
      }
    }
    cout << "PUZZLE #" << m << '\n';
    solve();
  }

  return 0;
}
