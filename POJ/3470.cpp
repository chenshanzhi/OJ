// ============================================================================
// http://poj.org/problem?id=3470
// ============================================================================

#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

// segment tree: range update, point query
int aN;
vector<int> tree;

void init(int n) {
  aN = n;
  tree.resize(n * 4, -1);
}

void range_update(int a, int b, int t, int l, int r, int k) {
  if (r <= a || b <= l) {
    return;
  }
  if (a <= l && r <= b) {
    tree[k] = t;
    return;
  }
  if (tree[k] != -1 && l + 1 < r) {
    tree[k * 2 + 1] = tree[k];
    tree[k * 2 + 2] = tree[k];
    tree[k] = -1;
  }
  int m = l + (r - l) / 2;
  range_update(a, b, t, l, m, k * 2 + 1);
  range_update(a, b, t, m, r, k * 2 + 2);
}

int point_query(int i, int l, int r, int k) {
  if (tree[k] != -1) {
    return tree[k];
  }
  if (l + 1 == r) {
    return tree[k];
  }
  int m = l + (r - l) / 2;
  if (i < m) {
    return point_query(i, l, m, k * 2 + 1);
  } else {
    return point_query(i, m, r, k * 2 + 2);
  }
}

// line segments and points
struct Seg {
  int x1, y1, x2, y2;
  Seg(int x1, int y1, int x2, int y2) :
    x1(x1), y1(y1), x2(x2), y2(y2) {}
};

int N, M;
vector<Seg> R, S;

vector<Seg> compress(const vector<Seg> &v) {
  vector<Seg> s(v);
  int n = s.size();
  vector<int> xs, ys;
  xs.reserve(n * 2);
  ys.reserve(n * 2);
  for (int i = 0; i < n; ++i) {
    xs.push_back(s[i].x1);
    ys.push_back(s[i].y1);
    xs.push_back(s[i].x2);
    ys.push_back(s[i].y2);
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  for (int i = 0; i < n; ++i) {
    s[i].x1 = lower_bound(xs.begin(), xs.end(), s[i].x1) - xs.begin();
    s[i].y1 = lower_bound(ys.begin(), ys.end(), s[i].y1) - ys.begin();
    s[i].x2 = lower_bound(xs.begin(), xs.end(), s[i].x2) - xs.begin();
    s[i].y2 = lower_bound(ys.begin(), ys.end(), s[i].y2) - ys.begin();
  }
  return s;
}

bool cmp_sweep_up(int i, int j) {
  return S[i].y2 < S[j].y2 || (S[i].y2 == S[j].y2 && i > j);
}
bool cmp_sweep_down(int i, int j) {
  return S[i].y1 > S[j].y1 || (S[i].y1 == S[j].y1 && i > j);
}
bool cmp_sweep_right(int i, int j) {
  return S[i].x2 < S[j].x2 || (S[i].x2 == S[j].x2 && i > j);
}
bool cmp_sweep_left(int i, int j) {
  return S[i].x1 > S[j].x1 || (S[i].x1 == S[j].x1 && i > j);
}

int get_dist(Seg &wall, Seg &bird) {
  if (wall.y1 == wall.y2) {
    if (bird.y1 == wall.y1) {
      return min(abs(bird.x1 - wall.x1), abs(bird.x2 - wall.x2));
    }
    if (wall.x1 <= bird.x1 && bird.x1 <= wall.x2) {
      return abs(wall.y1 - bird.y1);
    }
  }
  if (wall.x1 == wall.x2) {
    if (bird.x1 == wall.x1) {
      return min(abs(bird.y1 - wall.y1), abs(bird.y2 - wall.y2));
    }
    if (wall.y1 <= bird.y1 && bird.y1 <= wall.y2) {
      return abs(wall.x1 - bird.x1);
    }
  }
  return INT_MAX;
}

void sweep_up_down(vector<int> &I, vector<int> &bird, vector<int> &dist) {
  for (int i = 0; i < (int)I.size(); ++i) {
    int t = I[i];
    if (t < N) {
      range_update(S[t].x1, S[t].x2 + 1, t, 0, aN, 0);
    } else {
      int wall_i = point_query(S[t].x1, 0, aN, 0);
      if (wall_i != -1) {
        int d = get_dist(R[wall_i], R[t]);
        if (d < dist[t - N]) {
          bird[t - N] = wall_i;
          dist[t - N] = d;
        }
      }
    }
  }
}

void sweep_left_right(vector<int> &I, vector<int> &bird, vector<int> &dist) {
  for (int i = 0; i < (int)I.size(); ++i) {
    int t = I[i];
    if (t < N) {
      range_update(S[t].y1, S[t].y2 + 1, t, 0, aN, 0);
    } else {
      int wall_i = point_query(S[t].y1, 0, aN, 0);
      if (wall_i != -1) {
        int d = get_dist(R[wall_i], R[t]);
        if (d < dist[t - N]) {
          bird[t - N] = wall_i;
          dist[t - N] = d;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  vector<int> I;
  I.reserve(N + M);
  R.reserve(N + M);
  for (int i = 0; i < N; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 > x2) {
      swap(x1, x2);
      swap(y1, y2);
    } if (x1 == x2 && y1 > y2) {
      swap(y1, y2);
    }

    R.push_back(Seg(x1, y1, x2, y2));
    I.push_back(i);
  }
  for (int i = 0; i < M; ++i) {
    int x, y;
    cin >> x >> y;
    R.push_back(Seg(x, y, x, y));
    I.push_back(N + i);
  }
  S = compress(R); // 0 ~ (N + M) * 2 - 1
  int maxXY = (N + M) * 2;

  vector<int> bird(M);
  vector<int> dist(M, INT_MAX);

  init(maxXY);
  sort(I.begin(), I.end(), cmp_sweep_up);
  sweep_up_down(I, bird, dist);

  init(maxXY);
  sort(I.begin(), I.end(), cmp_sweep_down);
  sweep_up_down(I, bird, dist);

  init(maxXY);
  sort(I.begin(), I.end(), cmp_sweep_left);
  sweep_left_right(I, bird, dist);

  init(maxXY);
  sort(I.begin(), I.end(), cmp_sweep_right);
  sweep_left_right(I, bird, dist);

  vector<int> wall(N, 0);
  for (int i = 0; i < M; ++i) {
    int k = bird[i];
    wall[k]++;
  }
  for (int i = 0; i < N; ++i) {
    cout << wall[i] << '\n';
  }

  return 0;
}

