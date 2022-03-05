// =====================================================================================================================
// http://poj.org/problem?id=3126
// =====================================================================================================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 10000

vector<int> sieve_of_Eratosthenes(int n) {
  vector<int> isPrime(n, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < n; ++i) {
    if (isPrime[i]) {
      for (int j = i * 2; j < n; j += i) {
        isPrime[j] = false;
      }
    }
  }
  return isPrime;
}

int bfs(int s, int t, vector<int> &isPrime) {
  vector<int> visited(MAX_N, false);
  queue<int> Q;
  Q.push(s);
  visited[s] = true;

  int ret = 0;
  while (!Q.empty()) {
    int sz = Q.size();
    for (int i = 0; i < sz; ++i) {
      int e = Q.front();
      Q.pop();
      if (e == t) {
        return ret;
      }
      int d[4];
      for (int i = 0, x = e; i < 4; ++i, x /= 10) {
        d[i] = x % 10;
      }
      for (int i = 0, x = 1; i < 4; ++i, x *= 10) {
        int p = e - d[i] * x;
        for (int j = 0; j < 10; ++j) {
          if (j != d[i]) {
            int q = p + j * x;
            if (q >= 1000 && !visited[q] && isPrime[q]) {
              Q.push(q);
              visited[q] = true;
            }
          }
        }
      }
    }
    ++ret;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> isPrime = sieve_of_Eratosthenes(MAX_N);

  int K;
  cin >> K;
  while (K--) {
    int s, t;
    cin >> s >> t;
    int ret = bfs(s, t, isPrime);
    if (ret >= 0) {
      cout << ret << '\n';
    } else {
      cout << "Impossible\n";
    }
  }

  return 0;
}