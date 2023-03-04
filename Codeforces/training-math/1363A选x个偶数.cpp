// https://github.com/fengwei2002, 2023.02.28-21:26:57
// https://codeforces.com/contest/1363/problem/A
// 1363A. Odd Selection, Codeforces - Codeforces Round #646 (Div. 2)

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
      int n = 0, x = 0;
      cin >> n >> x;
      int cnt[2] = {};
      for (int i = 0; i < n; i++) {
         int a = 0;
         cin >> a;
         cnt[a & 1] += 1;
      }
      // cnt[1]: oddCnt, cnt[0]: evenCnt
      if (x == n) {
         // 如果 x == n，那么全拿走，奇数数量是奇数就可以，否则不可以
         if (cnt[1] & 1) {
            cout << "Yes\n";
         } else {
            cout << "No\n";
         }
      } else if (cnt[1] == 0 || (cnt[0] == 0 and !(x & 1))) {
         // 没有奇数 或者 偶数的数量为 0，并且 x 是奇数
         cout << "No\n";
      } else {
         cout << "Yes\n";
      }
   }
   
   return 0;
}

/*
1363A选x个偶数
在求和的时候，不管什么时候加上 偶数，他的奇偶性都不会发生变化

1 + 0 -> 1
1 + 1 -> 0
0 + 0 -> 0

因此，偶数就 只在最后的凑数量的时候有用，只有奇数的个数，会对结果的奇偶性产生影响


*/