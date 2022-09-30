// LINK: https://codeforces.com/contest/1696/problem/C
// NAME: 1696C. Fishingprince Plays With Array, Codeforces - Codeforces Global
// Round 21 DATE: 2022.09.30 17:54:49, LIMIT: 512 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0, m = 0;
      cin >> n >> m;
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) cin >> a[i];
      int k = 0;
      cin >> k;
      vector<int> b(k, 0);
      for (int i = 0; i < k; i++) cin >> b[i];

      auto split = [m](vector<int> &a) {
         vector<pair<int, int64_t>> b;
         for (int x : a) {
            int y = 1;
            while (x % m == 0) {
               x /= m;
               y *= m;
            } // 足够细分
            
            if (!b.empty() && x == b.rbegin()[0].first) {
               b.rbegin()[0].second += y;
            } else {
               b.emplace_back(x, y);
            }
         }
         return b;
      };

      if (split(a) == split(b)) {
         cout << "Yes\n";
      } else {
         cout << "No\n";
      }
   }

   return 0;
}

/*

1696C通过split和merge使得a数组变成b数组


split: 在 a 数组中可以选择一个 m 的倍数， 然后替换成 m 个 \frac{a_i}{m}
merge: 选择数组 a 中的 m 个相同的数字 a_i, a_{i + 1}, ..., a_{i + m - 1}
   替换为 m * ai

把数组 a 如何变换为数组 b


观察得到，split 和 merge 操作是恰好相反的
对于 m = 7
   origin():    7 7 7 7 7 7 7
   split(1):    1 1 1 1 1 1 1 7 7 7 7 7 7
   merge(1, 7): 7 7 7 7 7 7 7

可以发现，经过一次 split 和对拆开的数字进行一次 merge 操作
序列相较于原来的序列不会发生变化，同样先进行 merge 操作再进行 split
操作也会得到相同的效果

那么对于一个序列 a 是否可以变为 b 的问题，就等价于 b 是否可以变为 a 的问题


由于split
只对单点进行操作，并且不会对其他位置造成影响，所以可以对两个字符串拆分之后
判断拆分之后的 A' 和 B' 是否是相等的


*/