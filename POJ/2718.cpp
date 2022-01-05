// =====================================================================================================================
// http://poj.org/problem?id=2718
// =====================================================================================================================

#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int arr_to_num(int a[], int n) {
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret *= 10;
    ret += a[i];
  }
  return ret;
}

int solve(int a[], int n) {
  int ret = INT_MAX;
  do {
    int m = n / 2;
    if ((a[0] == 0 && m != 1) || (a[m] == 0 && n - m != 1)) {
      continue;
    }
    int x = arr_to_num(a, m);
    int y = arr_to_num(&a[m], n - m);
    ret = min(ret, abs(x - y));
  } while (next_permutation(a, a + n));
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  int a[10];

  string line;
  cin >> N;
  cin.ignore();
  while (N--) {
    getline(cin, line);
    stringstream ss(line);
    int n = 0;
    while (ss >> a[n]) {
      ++n;
    }
    cout << solve(a, n) << '\n';
  }
  return 0;
}