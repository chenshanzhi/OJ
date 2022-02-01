// =====================================================================================================================
// http://poj.org/problem?id=3280
// =====================================================================================================================

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define MAX_M 2001

int N, M;
string s;
int letter[26];
int dp[MAX_M][MAX_M];

int memoization(int i, int j) {
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (i >= j) {
    return dp[i][j] = 0;
  }
  if (s[i] == s[j]) {
    return dp[i][j] = memoization(i + 1, j - 1);
  } else {
    int x = letter[s[i] - 'a'] + memoization(i + 1, j);
    int y = letter[s[j] - 'a'] + memoization(i, j - 1);
    return dp[i][j] = min(x, y);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> s;
  for (int i = 0; i < N; ++i) {
    char ch;
    int x, y;
    cin >> ch >> x >> y;
    letter[ch - 'a'] = min(x, y);
  }

  memset(dp, -1, MAX_M * MAX_M * sizeof(int));
  cout << memoization(0, M - 1) << '\n';
  return 0;
}