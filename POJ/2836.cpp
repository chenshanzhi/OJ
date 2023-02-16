// ============================================================================
// http://poj.org/problem?id=2836
// ============================================================================

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 15
#define MAX_AREA (2000 * 2000)

int X[MAX_N];
int Y[MAX_N];
int N;

int get_mask(int x_min, int x_max, int y_min, int y_max) {
  int mask = 0;
  for (int i = 0; i < N; ++i) {
    if (x_min <= X[i] && X[i] <= x_max && y_min <= Y[i] && Y[i] <= y_max) {
      mask |= (1 << i);
    }
  }
  return mask;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while ((cin >> N) && N != 0) {
    for (int i = 0; i < N; ++i) {
      cin >> X[i] >> Y[i];
    }

    vector<int> rec;
    vector<int> area;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        int x_min = min(X[i], X[j]);
        int x_max = max(X[i], X[j]);
        int y_min = min(Y[i], Y[j]);
        int y_max = max(Y[i], Y[j]);

        if (x_min == x_max) {
          rec.push_back(get_mask(x_min - 1, x_max, y_min, y_max));
          area.push_back(y_max - y_min);
          rec.push_back(get_mask(x_min, x_max + 1, y_min, y_max));
          area.push_back(y_max - y_min);
        } else if (y_min == y_max) {
          rec.push_back(get_mask(x_min, x_max, y_min - 1, y_max));
          area.push_back(x_max - x_min);
          rec.push_back(get_mask(x_min, x_max, y_min, y_max + 1));
          area.push_back(x_max - x_min);
        } else {
          rec.push_back(get_mask(x_min, x_max, y_min, y_max));
          area.push_back((x_max - x_min) * (y_max - y_min));
        }
      }
    }

    vector<int> dp(1 << N, MAX_AREA);
    dp[0] = 0;
    for (int i = 0; i < (1 << N); ++i) {
      for (int j = 0; j < (int)rec.size(); ++j) {
        dp[i | rec[j]] = min(dp[i | rec[j]], dp[i] + area[j]);
      }
    }
    cout << dp.back() << '\n';
  }

  return 0;
}
