// LINK: https://codeforces.com/contest/1759/problem/D
// NAME: 1759D. Make It Round, Codeforces - Codeforces Round  #834 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.17-17:37:28, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

#define int int64_t

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0, m = 0;
      cin >> n >> m;
      int cnt2 = 0, cnt5 = 0;
      int k = 1;
      int n0 = n;
      
      while (n > 0 and n % 2 == 0) {
         n /= 2;
         cnt2 += 1;
      }
      while (n > 0 and n % 5 == 0) {
         n /= 5;
         cnt5 += 1;
      }
      
      while (cnt2 < cnt5 and k * 2 <= m) {
         cnt2 += 1;
         k *= 2;
      }
      while (cnt5 < cnt2 and k * 5 <= m) {
         cnt5 += 1;
         k *= 5;
      }
      while (k * 10 <= m) {
         k *= 10;
      }
      
      if (k == 1) {
         cout << n0 * m << '\n';
      } else {
         k *= m / k; // m / k 在 1 到 10 之间，k 是满足要求的数字，返回最大的数字
         cout << n0 * k << '\n';
      }
   }
   
   return 0;
}

/*

1759D将n乘以m次之内可以得到的最多的末尾0的数字


n*k 是最终的答案
首先统计两个数字 cnt2 和 cnt5 各自代表 2 和 5 出现的次数
n = 2^{cnt2} * 5^{cnt5} * d ，这里的 d 不可以整除 2 或者整除 5

如果说 cnt2 == cnt5 那么就直接是这些 10 作为最后的结果
如果 cnt2 < cnt5 : 就尽可能的乘 2 来匹配 5 如果乘满了就继续追加 10

*/