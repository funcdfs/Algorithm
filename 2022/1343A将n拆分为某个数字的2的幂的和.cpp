// LINK: https://codeforces.com/contest/1343/problem/A
// NAME: 1343A. Candies, Codeforces - Codeforces Round #636 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.18-22:26:48, 1000 ms

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
      for (int pw = 2; pw < 30; pw++) {
         int val = (1 << pw) - 1;
         if (n % val == 0) {
            cout << n / val << '\n';
            break;
         }
      }
   }
   
   return 0;
}

/*

1343A将n拆分为某个数字的2的幂的和


![](https://raw.githubusercontent.com/psychonaut1f/b/main/img/202212182304126.png)

*/