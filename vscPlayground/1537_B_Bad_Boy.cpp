/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-05 12:08:40
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n, m, i, j;
      cin >> n >> m >> i >> j;
      // in a rectangle n * m, find two point, the sum to (i, j) is max
      cout << "1 1 " << n << ' ' << m << '\n';
   }
   
   return 0;
}
/*

*/