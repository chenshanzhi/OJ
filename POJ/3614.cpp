// =====================================================================================================================
// http://poj.org/problem?id=3614
// =====================================================================================================================
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define MAX_SPF 1000

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int C, L;
  cin >> C >> L;
  vector<pair<int, int> > cows(C);
  vector<int> spf(MAX_SPF + 1, 0);
  for (int i = 0; i < C; ++i) {
    cin >> cows[i].first >> cows[i].second;
  }
  for (int i = 0; i < L; ++i) {
    int t, cover;
    cin >> t >> cover;
    spf[t] += cover;
  }
  sort(cows.begin(), cows.end());

  int ret = 0;
  priority_queue<int, vector<int>, greater<int> > Q;
  int i = 0;
  for (int t = 1; t <= MAX_SPF; ++t) {
    while (!Q.empty() && Q.top() < t) {
      Q.pop();
    }
    while (i < C && cows[i].first == t) {
      Q.push(cows[i].second);
      ++i;
    }
    while (spf[t] > 0 && !Q.empty()) {
      Q.pop();
      --spf[t];
      ++ret;
    }
  }
  cout << ret << '\n';

  return 0;
}