// https://github.com/fengwei2002, 2022.12.30 20:02:06
// https://codeforces.com/contest/1294/problem/C
// 1294C. Product of Three Numbers, Codeforces - Codeforces Round #615 (Div. 3)

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
      int a = -1, b = -1;
      for (int i = 2; i * i <= n; i++) {
         if (n % i == 0) {
            a = i;
            n /= i;
            break;
         }
      }
      if (a == -1) {
         cout << "NO\n";
         continue;
      }
      for (int i = a + 1; i * i <= n; i++) {
         if (n % i == 0) {
            b = i;
            n /= i;
            break;
         }
      }
      if (b == -1 or n == a or n == b or n == 1) {
         cout << "NO\n";
      } else {
         cout << "YES\n";
         cout << a << ' ' << b << ' ' << n << '\n';
      }
   }

   return 0;
}

/*

找到3个大于2的数字乘积为n



*/