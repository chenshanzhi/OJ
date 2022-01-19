// =====================================================================================================================
// http://poj.org/problem?id=1328
// =====================================================================================================================
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <functional>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, d;
  int round = 0;
  while ((scanf("%d%d", &n, &d) != EOF) && (n != 0 || d != 0)) {
    bool hasSolution = true;
    vector<pair<double, double> > intervals(n);
    for (int i = 0; i < n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (y > d) {
        hasSolution = false;
      } else {
        double dx = sqrt(d * d - y * y);
        intervals[i].first = x - dx;
        intervals[i].second = x + dx;
      }
    }
    int count;
    if (!hasSolution) {
      count = -1;
    } else {
      sort(intervals.begin(), intervals.end());
      count = 1;
      double l = intervals[0].first;
      double r = intervals[0].second;
      for (int i = 1; i < intervals.size(); ++i) {
        double xl = intervals[i].first;
        double xr = intervals[i].second;
        if (xl <= r) {
          l = max(l, xl);
          r = min(r, xr);
        } else {
          ++count;
          l = xl;
          r = xr;
        }
      }
    }
    printf("Case %d: %d\n", ++round, count);
  }
  return 0;
}