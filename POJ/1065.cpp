// =====================================================================================================================
// http://poj.org/problem?id=1065
// =====================================================================================================================
#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, N;
  cin >> T;
  while (T--) {
    cin >> N;
    vector<pair<int, int> > v(N);
    for (int i = 0; i < N; ++i) {
      cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    set<int, greater<int> > S;
    for (int i = 0; i < N; ++i) {
      int e = v[i].second;
      set<int, greater<int> >::iterator it = S.lower_bound(e);
      if (it == S.end()) {
        S.insert(e);
      } else {
        S.erase(it);
        S.insert(e);
      }
    }
    cout << S.size() << '\n';
  }

  return 0;
}