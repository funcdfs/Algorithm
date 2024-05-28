/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-05 18:00:25
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
   
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];

   vector<int64_t> preSum(n + 1, 0);
   for (int i = 1; i <= n; i++) preSum[i] = preSum[i - 1] + a[i - 1];

   if (preSum.back() % 3) return cout << 0, 0;
   dbg(preSum);
   int64_t ans = 0, cnt = 0;
   
   // i 是第三段的起点，第三段要给前两段空出来位置
   for (int i = 3; i <= n; i++) {
      // cnt 表示第一个节点的可能数量
      if (s[i - 2])
   }
   cout << ans << '\n';
   return 0;
}