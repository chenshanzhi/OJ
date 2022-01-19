// =====================================================================================================================
// http://poj.org/problem?id=1862
// =====================================================================================================================

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <functional>
#include <vector>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &v[i]);
  }
  sort(v.begin(), v.end(), greater<int>());
  double ret = v[0];
  for (int i = 1; i < N; ++i) {
    ret = 2 * sqrt(ret * v[i]);
  }
  printf("%.3f\n", ret);

  return 0;
}
