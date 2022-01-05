// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/0121
// =====================================================================================================================

#include <bits/stdc++.h>
using namespace std;

const vector<vector<int>> G = {
  { 1, 4 },
  { 0, 2, 5 },
  { 1, 3, 6 },
  { 2, 7 },
  { 0, 5 },
  { 1, 4, 6 },
  { 2, 5, 7 },
  { 3, 6 }
};

unordered_map<uint32_t, int> M;

uint32_t a8_to_u32(int a[8]) {
  uint32_t ret = 0;
  for (int i = 0; i < 8; ++i) {
    ret <<= 4;
    ret |= a[i];
  }
  return ret;
}

int zero_index(uint32_t u) {
  int ret = 7;
  while ((u & 0xfffffff0) != u) {
    u >>= 4;
    --ret;
  }
  return ret;
}

uint32_t exchange(uint32_t u, int i, int zero_i) {
  int j = zero_i;
  uint32_t mask = (u >> (28 - i * 4)) & 0xf;
  return (u ^ (mask << (28 - i * 4))) | (mask << (28 - j * 4));
}

void bfs() {
  queue<uint32_t> Q;
  Q.push(0x01234567);
  M[0x1234567] = 0;
  int level = 1;
  while (!Q.empty()) {
    int sz = Q.size();
    for (int k = 0; k < sz; ++k) {
      auto u = Q.front();
      Q.pop();
      int j = zero_index(u);
      for (auto i : G[j]) {
        uint32_t v = exchange(u, i, j);
        auto it = M.find(v);
        if (it == M.end()) {
          Q.push(v);
          M[v] = level;
        }
      }
    }
    ++level;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bfs();

  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    int a[8];
    for (int i = 0; i < 8; ++i) {
      ss >> a[i];
    }
    auto u = a8_to_u32(a);
    cout << M[u] << '\n';
  }
  return 0;
}