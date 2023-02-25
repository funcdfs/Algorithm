// https://github.com/fengwei2002, 2023.02.25-15:22:51
// https://codeforces.com/contest/1353/problem/C
// 1353C. Board Moves, Codeforces - Codeforces Round #642 (Div. 3)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      int64_t ans = 0;
      int64_t edgeLength = 3;
      for (int i = 1; i <= ((n - 1) / 2); i++) {
         ans += i * (edgeLength - 1) * 4ll;
         edgeLength += 2;
      }
      cout << ans << '\n';
   }
   return 0;
}

/*

1353C将所有的数字移动到一个格子

都往中间走是最优的解法
然后分析 n 等于多少的时候，步数分别为多少，因为 n 都是奇数
所以可以之考虑奇数

当 n == 1 的时候不用移动 d[1] = 0
中间点外面的一圈的点的距离，八个就是 1
再外面的一圈的点的距离，就是十六个，都是 2，一个矩形的点数量是 edgeLength - 1 * 4

1*8 + 2*16 + 3*24 + ...
*/