// =====================================================================================================================
// http://poj.org/problem?id=3181
// =====================================================================================================================

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

typedef vector<int> bignum;
int base = 1E9;

void bignum_add(bignum &a, const bignum &b) {
  int carry = 0;
  for (int i = 0; i < max(a.size(), b.size()) || carry != 0; ++i) {
    if (i == a.size()) {
      a.push_back(0);
    }
    a[i] += (i < b.size() ? b[i] : 0) + carry;
    carry = (a[i] >= base);
    a[i] %= base;
  }
}

string bignum_to_str(const bignum &a) {
  stringstream ss;
  for (int i = a.size() - 1; i >= 0; --i) {
    ss << a[i];
  }
  return ss.str();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;
  vector<bignum> ps(K);
  vector<bignum> dp(N + 1, vector<int>(1, 0));
  dp[0] = vector<int>(1, 1);
  for (int i = 1; i <= K; ++i) {
    fill(ps.begin(), ps.end(), vector<int>(1, 0));
    for (int j = 0; j <= N; ++j) {
      bignum_add(ps[j % i], dp[j]);
      dp[j] = ps[j % i];
    }
  }
  cout << bignum_to_str(dp[N]) << '\n';

  return 0;
}