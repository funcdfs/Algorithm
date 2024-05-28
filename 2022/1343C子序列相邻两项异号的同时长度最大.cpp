// https://github.com/fengwei2002, 2022.12.19-11:34:30
// https://codeforces.com/contest/1343/problem/C
// 1343C. Alternating Subsequence, Codeforces - Codeforces Round #636 (Div. 3)

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
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) cin >> a[i];
      
      pair<int, int64_t> neg, pos;
      // length, sum
      
      for (int i = 0; i < n; i++) {
         if (a[i] < 0) {
            neg = max(neg, make_pair(pos.first + 1, pos.second + a[i]));
         } else {
            pos = max(pos, make_pair(neg.first + 1, neg.second + a[i]));
         }
      }
      // pair 排序默认使用 first 升序，first 相同的时候对 second 进行升序
      cout << max(neg, pos).second << '\n';
   }
   
   return 0;
}

/*

1343C子序列相邻两项异号的同时长度最大


输出这个最长的子序列的总和是多少
*/