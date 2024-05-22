/**
 * name: D. Ice Cream Balls
 * link: https://codeforces.com/contest/1862/problem/D
 * time: 2024/5/22 21:28:58 https://github.com/funcdfs
 **/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto solve(int _case) -> void {
   dbg(_case);
   
   int64_t n = 0;
   cin >> n;

   // https://www.luogu.com.cn/article/ifoce010

   // 如果没有直接精确解，那就找到小于 n 的最右侧的元素数量，然后空余位置加一补齐
   // 二分找右边界

   int64_t l = 0, r = 2e9; 
   while (l < r) {
      int64_t mid = (l + r + 1) >> 1;
      auto check = [&](int64_t k) -> bool {
         if (k * (k - 1) / 2 <= n) {
            return true;
         }
         return false;
      };
      if (check(mid)) {
         l = mid;
      } else {
         r = mid - 1;
      }
   }

   if (l * (l - 1) / 2 < n) {
      int64_t diff = n - (l * (l - 1)) / 2;
      l += diff;
   }

   cout << format("{0}\n", l);

   return;
}

auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int TT = 0;
   cin >> TT;
   for (int _case = 1; _case <= TT; _case++) {
      solve(_case);
   }

   return 0;
}
/*

*/