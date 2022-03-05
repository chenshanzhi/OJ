// =====================================================================================================================
// http://poj.org/problem?id=1930
// =====================================================================================================================
#include <climits>
#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b) {
  while (b != 0) {
    ull r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string str;
  while (cin >> str && str != "0") {
    ull p = 1, q = 1;
    ull x = 0, y = 0;
    for (ull i = 0; str[2 + i] != '.'; ++i) {
      q *= 10;
      y *= 10;
      y += str[2 + i] - '0';
    }

    ull A = ULLONG_MAX, B = ULLONG_MAX;
    for (ull i = 0; str[2 + i] != '.'; ++i) {
      ull a = p * (q - 1);
      ull b = x * (q - 1) + y;
      ull g = gcd(a, b);
      a /= g;
      b /= g;
      if (a < A) {
        A = a;
        B = b;
      }
      p *= 10;
      q /= 10;
      x *= 10;
      x += y / q;
      y %= q;
    }
    cout << B << '/' << A << '\n';
  }
  return 0;
}