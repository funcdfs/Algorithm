// LINK: https://codeforces.com/contest/478/problem/C
// NAME: 478C. Table Decorations, Codeforces - Codeforces Round #273 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.12.09-14:20:05, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int64_t r = 0, g = 0, b = 0; 
   cin >> r >> g >> b;
   
   int64_t ans = min({
      (r + g + b) / 3, 
      // 最终状态下所有的颜色都用光了, 或者剩下一个或者两个某一种颜色
      r + g + b - max({r, g, b}),
      // 最终的情况下只剩下一个颜色的剩余部分
      // 值就是最多的颜色减去其他两种颜色的数量 [2][1] and [2][1]
   });
   
   cout << ans << '\n';
   
   return 0;
}

/*

478C一组中三个颜色不可以完全相同的桌子的数量

*/