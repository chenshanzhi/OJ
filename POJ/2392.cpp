// =====================================================================================================================
// http://poj.org/problem?id=2392
// =====================================================================================================================
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_K 400
#define MAX_A 40000

struct Block {
  int h, a, c;
} blocks[MAX_K];
bool cmp(const Block &i, const Block &j) { return i.a < j.a; }

int dp[MAX_A + 1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int K;
  cin >> K;
  int A = 0;;
  for (int i = 0; i < K; ++i) {
    cin >> blocks[i].h >> blocks[i].a >> blocks[i].c;
    A = max(A, blocks[i].a);
  }
  sort(blocks, blocks + K, cmp);

  dp[0] = 0;
  fill(dp + 1, dp + A + 1, -1);
  int ret = 0;
  for (int i = 0; i < K; ++i) {
    int h = blocks[i].h;
    int a = blocks[i].a;
    int c = blocks[i].c;
    for (int j = 0; j <= A; ++j) {
      if (j > a) {
        dp[j] = -1;
      } else if (dp[j] >= 0) {
        dp[j] = c;
      } else if (j < h || dp[j - h] <= 0) {
        dp[j] = -1;
      } else {
        dp[j] = dp[j - h] - 1;
      }

      if (dp[j] >= 0) {
        ret = max(ret, j);
      }
    }
  }
  cout << ret << '\n';

  return 0;
}