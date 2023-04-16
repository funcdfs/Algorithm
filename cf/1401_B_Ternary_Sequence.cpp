/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-14 17:29:31
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
  cin.tie(nullptr), ios::sync_with_stdio(false);
  
  int tt = 0;
  cin >> tt;
  while (tt--) {
    int x0, x1, x2, y0, y1, y2;
    cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;
    int m = 0, sum = 0;
    m = min(x0, y2);
    x0 -= m; 
    y2 -= m; // make (0, 2) pair

    m = min(x1, y0);
    x1 -= m;
    y0 -= m; // make (1, 0) pair

    sum -= 2 * min(x1, y2);

    m = min(x2, y1);
    x2 -= m;
    y1 -= m;
    sum += 2 * m; // make (2, 1) pair, sum += 2

    cout << sum << '\n';
  }
  
  return 0;
}
/*

*/