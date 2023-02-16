// ============================================================================
// http://poj.org/problem?id=1795
// ============================================================================

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define MAX_N 15

string R[MAX_N];
int M;

string S[MAX_N];
int N;

int overlap[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

void remove_substr() {
  N = 0;
  for (int i = 0; i < M; ++i) {
    bool isSubStr = false;
    for (int j = 0; j < M; ++j) {
      if (j != i && R[i].size() < R[j].size() && R[j].find(R[i]) != string::npos) {
        isSubStr = true;
        break;
      }
    }
    if (!isSubStr) {
      S[N++] = R[i];
    }
  }
}

void init_overlap() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int L1 = S[i].size();
      int L2 = S[j].size();
      for (int k = 0; k <= L1; ++k) {
        int L = min(L2, L1 - k);
        if (S[i].compare(k, L, S[j], 0, L) == 0) {
          overlap[i][j] = L;
          break;
        }
      }
    }
  }
}

void dfs(int s, int i, string &ret) {
  int t = s & ~(1 << i);
  if (t == 0) {
    return;
  }
  int k = -1;
  for (int j = 0; j < N; ++j) {
    if (j != i && (t & (1 << j)) != 0 && dp[t][j] + overlap[i][j] == dp[s][i]) {
      if (k == -1 || S[j].substr(overlap[i][j]) < S[k].substr(overlap[i][k])) {
        k = j;
      }
    }
  }

  ret += S[k].substr(overlap[i][k]);
  dfs(t, k, ret);
}

string solve() {
  remove_substr();
  if (N == 0) {
    return R[0];
  }

  sort(S, S + N);
  init_overlap();
  memset(dp, 0, sizeof(dp));
  for (int s = 0; s < (1 << N); ++s) {
    for (int i = 0; i < N; ++i) {
      if ((s & (1 << i)) == 0) {
        continue;
      }
      int t = s & ~(1 << i);
      for (int j = 0; j < N; ++j) {
        if (j == i || (t | (1 << j)) != t) {
          continue;
        }
        int val = overlap[i][j] + dp[t][j];
        if (dp[s][i] < val) {
          dp[s][i] = val;
        }
      }
    }
  }

  int s = (1 << N) - 1;
  int l = *max_element(dp[s], dp[s] + N);
  string ret;
  for (int i = 0; i < N; ++i) {
    if (dp[s][i] == l) {
      ret = S[i];
      dfs(s, i, ret);
      break;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int K;
  cin >> K;
  for (int k = 1; k <= K; ++k) {
    cin >> M;
    for (int i = 0; i < M; ++i) {
      cin >> R[i];
    }
    cout << "Scenario #" << k << ":\n" << solve() << "\n\n";
  }
  return 0;
}
