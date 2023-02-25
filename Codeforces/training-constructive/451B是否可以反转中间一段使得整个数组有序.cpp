// https://github.com/fengwei2002, 2023.02.20-23:48:11
// https://codeforces.com/contest/451/problem/B
// 451B. Sort the Array, Codeforces - Codeforces Round #258 (Div. 2)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   
   vector<int> b(a.begin(), a.end());
   sort(b.begin(), b.end());
   
   int l = 0, r = n - 1;
   while (a[l] == b[l] and l <= n - 1) {
      l += 1;
   }
   while (a[r] == b[r] and r >= 0) {
      r -= 1;
   }
   
   if (l >= r) {
      cout << "yes\n";
      cout << 1 << ' ' << 1 << '\n';
      return 0;
   }
   // 如果 l >= r 则 a 数组已经有序
   
   for (int i = l, j = r; i <= r; i++, j--) {
      b[i] = a[j];
      // 将这一段反转
   }

   for (int i = 0; i < n - 1; i++) {
      if (b[i] > b[i + 1]) {
         cout << "no";
         return 0;
      }
   }
   
   cout << "yes\n";
   cout << l + 1 << ' ' << r + 1 << '\n';
   
   return 0;
}

/*

451B是否可以反转中间一段使得整个数组有序



*/