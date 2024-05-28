// LINK: https://codeforces.com/contest/1029/problem/A
// NAME: 1029A. Many Equal Substrings, Codeforces - Codeforces Round #506 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.12-14:15:04, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, k = 0;
   cin >> n >> k;
   string t = "";
   cin >> t;
   
   int pos = 0;
   for (int i = 1; i < n; i++) {
      if (t.substr(0, i) == t.substr(n - i, i)) {
         pos = i;
      }
   }
   string p = t.substr(pos);
   for (int i = 0; i < k - 1; i++) {
      t.append(p);
   }
   cout << t << '\n';
   
   return 0;
}

/*

1029A字串为t的重复k次的最短s串


短串中，如果存在一个前缀，同时又是串的后缀的话，
那么就应该让【短字符串相同的后缀部分】在构造的新字符串中，作为一个字符串的后缀
同时作为下一个字符串的前缀

*/