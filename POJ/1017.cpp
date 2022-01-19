// =====================================================================================================================
// http://poj.org/problem?id=1017
// =====================================================================================================================
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a1, a2, a3, a4, a5, a6;
  while ((cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6) && (a1 || a2 || a3 || a4 || a5 || a6)) {
    int ret = a6 + a5 + a4 + a3 / 4;
    int n1 = 0, n2 = 0;
    if (a5 != 0) {
      n1 += 11 * a5;
    }
    if (a4 != 0) {
      n2 += a4 * 5;
    }

    a3 %= 4;
    if (a3 == 1) {
      ++ret;
      n2 += 5;
      n1 += 7;
    } else if (a3 == 2) {
      ++ret;
      n2 += 3;
      n1 += 6;
    } else if (a3 == 3) {
      ++ret;
      n2 += 1;
      n1 += 5;
    }

    if (a2 >= n2) {
      a2 -= n2;
      ret += (a2 / 9);
      a2 %= 9;
      if (a2 != 0) {
        ++ret;
        n1 += (9 - a2) * 4;
      }
    } else {
      n1 += (n2 - a2) * 4;
      a2 = 0;
    }

    if (a1 >= n1) {
      a1 -= n1;
      ret += (a1 / 36 + (a1 % 36 != 0 ? 1 : 0));
    }
    cout << ret << '\n';
  }
  return 0;
}