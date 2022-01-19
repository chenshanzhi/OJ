// =====================================================================================================================
// http://poj.org/problem?id=2376
// =====================================================================================================================
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, T;
  scanf("%d%d", &N, &T);
  vector<pair<int, int> > input(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d%d", &input[i].first, &input[i].second);
  }
  sort(input.begin(), input.end());

  int count = 0;
  int L = 1;
  int i = 0;
  while (L <= T) {
    int R = 0;
    while (i < N && input[i].first <= L) {
      R = max(R, input[i].second);
      ++i;
    }
    if (R == 0) {
      printf("-1\n");
      return 0;
    }
    ++count;
    L = R + 1;
  }
  printf("%d\n", count);
  return 0;
}