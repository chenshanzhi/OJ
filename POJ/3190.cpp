// =====================================================================================================================
// http://poj.org/problem?id=3190
// =====================================================================================================================

#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define MAX_N 50001

int L[MAX_N];
int R[MAX_N];
int indices[MAX_N];
int cows[MAX_N];
bool cmpL(int i, int j) { return L[i] < L[j]; }

typedef pair<int, int> PII;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &L[i], &R[i]);
    indices[i] = i;
  }
  sort(indices, indices + n, cmpL);

  priority_queue<pair<int, int> > Q;
  for (int k = 0; k < n; ++k) {
    int i = indices[k];
    if (Q.empty() || L[i] <= -Q.top().first) {
      Q.push(make_pair(-R[i], i));
      cows[i] = Q.size();
    } else {
      int j = Q.top().second;
      Q.pop();
      Q.push(make_pair(-R[i], i));
      cows[i] = cows[j];
    }
  }
  printf("%d\n", Q.size());
  for (int i = 0; i < n; ++i) {
    printf("%d\n", cows[i]);
  }
  return 0;
}
