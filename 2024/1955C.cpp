/**
 * name: C. Inhabitant of the Deep Sea
 * link: https://codeforces.com/contest/1955/problem/C
 * time: 2024/5/21 12:52:49 https://github.com/funcdfs
 **/
#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif


#define int long long
auto solve(int _case) -> void {
   dbg(_case);
   int n = 0, k = 0;
   cin >> n >> k;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];
   
   int l = (k + 1) / 2, r = k - l;
   // 怪物在左右攻击的次数, left cnt, right cnt
   int ans = 0;


   for (int i = 0; i < n; i++) {
      if (a[i] <= l) {
         l -= a[i];
         a[i] = 0;
         ans += 1;
      } else {
         a[i] -= l;
         break;
      }
   }


   for (int i  =n - 1;i >= 0;i--) {
      if (a[i] <= r) {
         r -= a[i];
         if (a[i] > 0) {
            ans += 1;
         }
         a[i] = 0;
      } else {
         a[i] -= r;
         break;
      }
   }

   cout << format("{0}\n", ans);

   return;
}
#undef int

auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
 
   int TT = 0;
   cin >> TT;
   for (int _case = 1; _case <= TT; _case++) {
      solve(_case);
   }
 
   return 0;
}