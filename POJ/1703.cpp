// =====================================================================================================================
// http://poj.org/problem?id=1703
// =====================================================================================================================

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 100000

int T;
int N, M;
int S[MAX_N * 2];
int R[MAX_N * 2];

int find(int i) {
  if (S[i] == i) {
    return i;
  }
  return S[i] = find(S[i]);
}

void unite(int i, int j) {
  i = find(i);
  j = find(j);
  if (i == j) {
    return;
  }
  if (R[i] < R[j]) {
    S[i] = j;
  } else {
    S[j] = i;
    if (R[i] == R[j]) {
      R[i]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  string str;
  int i, j;
  while (T--) {
    cin >> N >> M;
    for (int i = 0; i < N * 2; ++i) {
      S[i] = i;
      R[i] = 0;
    }
    while (M--) {
      cin >> str >> i >> j;
      --i;
      --j;
      if (str[0] == 'D') {
        unite(i, j + N);
        unite(j, i + N);
      } else {
        int r1 = find(i);
        int r2 = find(j);
        int r3 = find(j + N);
        if (r1 == r2) {
          cout << "In the same gang.\n";
        } else if (r1 == r3) {
          cout << "In different gangs.\n";
        } else {
          cout << "Not sure yet.\n";
        }
      }
    }
  }

  return 0;
}