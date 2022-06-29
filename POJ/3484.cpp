// ============================================================================
// http://poj.org/problem?id=3484
// ============================================================================
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int countSeq(int x, int y, int z) {
  return (y - x) / z + 1;
}

void solve(vector<int> &X, vector<int> &Y, vector<int> &Z) {
  int N = X.size();
  int s = 0;
  for (int i = 0; i < N; ++i) {
    s += countSeq(X[i], Y[i], Z[i]);
  }
  if (s % 2 == 0) {
    cout << "no corruption\n";
    return;
  }

  int l = *min_element(X.begin(), X.end());
  int r = *max_element(Y.begin(), Y.end()) + 1;
  while (l < r) {
    int m = l + (r - l) / 2;
    int nGreater = 0;
    for (int i = 0; i < N; ++i) {
      if (m < X[i]) {
        nGreater += countSeq(X[i], Y[i], Z[i]);
      } else if (m <= Y[i]) {
        nGreater += countSeq(X[i], Y[i], Z[i]) - countSeq(X[i], m, Z[i]);
      }
    }
    if (nGreater % 2 != 0) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  int nEqual = 0;
  for (int i = 0; i < N; ++i) {
    if (X[i] <= l && l <= Y[i] && (l - X[i]) % Z[i] == 0) {
      ++nEqual;
    }
  }
  cout << l << ' ' << nEqual << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  while (cin) {
    vector<int> X, Y, Z;
    bool dataSet = false;
    while (getline(cin, line) && line != "") {
      dataSet = true;
      stringstream ss(line);
      int x, y, z;
      ss >> x >> y >> z;
      X.push_back(x);
      Y.push_back(y);
      Z.push_back(z);
    }
    if (dataSet) {
      solve(X, Y, Z);
    }
  }
  return 0;
}
