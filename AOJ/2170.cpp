// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/2170
// =====================================================================================================================
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define MAX_N 100000 + 1
int N;
int Q;
int parent[MAX_N];
int markTime[MAX_N];
int queryTime[MAX_N];
int queryNode[MAX_N];

int find(int i, int currTime) {
  if (markTime[i] < currTime) {
    return i;
  }
  return parent[i] = find(parent[i], currTime);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while ((cin >> N >> Q) && !(N == 0 && Q == 0)) {
    parent[1] = 1;
    markTime[1] = 0;
    for (int i = 2; i <= N; ++i) {
      cin >> parent[i];
      markTime[i] = INT_MAX;
    }

    string s;
    int t;
    int count = 0;
    for (int i = 1; i <= Q; ++i) {
      cin >> s >> t;
      if (s[0] == 'Q') {
        queryTime[count] = i;
        queryNode[count] = t;
        ++count;
      } else {
        markTime[t] = min(markTime[t], i);
      }
    }

    long long ret = 0;
    for (int i = count - 1; i >= 0; --i) {
      ret += find(queryNode[i], queryTime[i]);
    }
    cout << ret << '\n';
  }

  return 0;
}
