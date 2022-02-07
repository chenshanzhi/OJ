// =====================================================================================================================
// http://poj.org/problem?id=2010
// =====================================================================================================================

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, C, F;
  cin >> N >> C >> F;
  vector<pair<int, int> > v(C);
  for (int i = 0; i < C; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());

  vector<ll> S(C, 0);
  priority_queue<ll> L, R;

  ll s = 0;
  for (int i = 0; i < N / 2; ++i) {
    s += v[i].second;
    L.push(v[i].second);
  }
  for (int i = N / 2; i < C - N / 2; ++i) {
    S[i] = s;
    if (v[i].second < L.top()) {
      s -= L.top();
      L.pop();
      s += v[i].second;
      L.push(v[i].second);
    }
  }

  s = 0;
  for (int i = C - 1; i >= C - N / 2; --i) {
    s += v[i].second;
    R.push(v[i].second);
  }
  for (int i = C - N / 2 - 1; i >= N / 2; --i) {
    S[i] += s;
    if (S[i] + v[i].second <= F) {
      cout << v[i].first << '\n';
      return 0;
    }
    if (v[i].second < R.top()) {
      s -= R.top();
      R.pop();
      s += v[i].second;
      R.push(v[i].second);
    }
  }
  cout << "-1" << '\n';
  return 0;
}