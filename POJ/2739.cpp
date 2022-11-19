// =====================================================================================================================
// http://poj.org/problem?id=2739
// =====================================================================================================================
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 10000

vector<int> sieve(int n) {
  vector<int> isPrime(n, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < n; ++i) {
    if (isPrime[i]) {
      for (int j = i * 2; j < n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 0; i < n; ++i) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }
  return primes;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> primes = sieve(MAX_N + 1);
  int n = primes.size();

  int t;
  while ((cin >> t) && t != 0) {
    int count = 0;
    int l = 0, r = 0, s = 0;
    for (;;) {
      while (r < n && s < t) {
        s += primes[r++];
      }
      if (s < t) {
        break;
      }
      if (s == t) {
        ++count;
      }
      s -= primes[l++];
    }
    cout << count << '\n';
  }

  return 0;
}
