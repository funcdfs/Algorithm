/**
 * name: C. Fadi and LCM
 * link: https://codeforces.com/contest/1285/problem/C
 * time: 2024/5/25 22:35:12 https://github.com/funcdfs
 **/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
#define int long long


auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
   
   int x = 0;
   cin >> x;

   // balanced
   int ans = 1;
   for (int i = 1; i * i <= x; i++) {
      if (x % i == 0 and std::gcd(i, x / i) == 1) {
         ans = i;
      }
   }

   cout << ans << ' ' << x / ans << endl;
   
   return 0;
}
/*

*/