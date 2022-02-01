// =====================================================================================================================
// http://poj.org/problem?id=3666
// =====================================================================================================================
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &v, vector<int> &u) {
  vector<vector<int> > dp(2, vector<int>(u.size()));
  int prev = 0, curr = 1;
  for (int i = 0; i < v.size(); ++i) {
    int t = INT_MAX;
    for (int j = 0; j < u.size(); ++j) {
      t = min(t, dp[prev][j]);
      dp[curr][j] = t + abs(v[i] - u[j]);
    }
    swap(prev, curr);
  }
  return *min_element(dp[prev].begin(), dp[prev].end());
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }
  vector<int> u(v);
  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());

  int r1 = solve(v, u);
  reverse(v.begin(), v.end());
  int r2 = solve(v, u);
  cout << min(r1, r2) << '\n';

  return 0;
}