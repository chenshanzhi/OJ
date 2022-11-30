// =====================================================================================================================
// http://poj.org/problem?id=2674
// =====================================================================================================================

#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX_N 32000
#define MAX_NAME_LEN 256

int N;
float L, V;
int dir[MAX_N];
float pos[MAX_N];
char name[MAX_N][MAX_NAME_LEN];

void solve() {
  float max_d = 0;
  int max_i = 0;
  for (int i = 0; i < N; ++i) {
    float d = (dir[i] > 0 ? L - pos[i] : pos[i]);
    if (d > max_d) {
      max_d = d;
      max_i = i;
    }
  }

  int index;
  int count = 0;
  if (dir[max_i] > 0) {
    for (int i = max_i + 1; i < N; ++i) {
      if (dir[i] < 0) {
        ++count;
      }
    }
    index = max_i + count;
  } else {
    for (int i = max_i - 1; i >= 0; --i) {
      if (dir[i] > 0) {
        ++count;
      }
    }
    index = max_i - count;
  }

  printf("%13.2f %s\n", floor((max_d / V) * 100) / 100, name[index]);
}

int main() {
  while (scanf("%d", &N) != EOF && N != 0) {
    scanf("%f%f", &L, &V);
    for (int i = 0; i < N; ++i) {
      char ch;
      scanf(" %c%f%s", &ch, &pos[i], name[i]);
      dir[i] = ((ch == 'p' || ch == 'P') ? 1 : -1);
    }

    solve();
  }
  return 0;
}
