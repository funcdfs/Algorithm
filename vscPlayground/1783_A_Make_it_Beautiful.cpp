/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-06 15:00:10
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
   
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) cin >> a[i];
      sort(a.begin(), a.end(), [](int a, int b) {
         return a > b;
      });
      int x = a.back();
      a.pop_back();
      a.insert(a.begin(), x);
      int64_t sum = 0;
      bool ok = true;
      for (int i = 0; i < n; i++) {
         if (a[i] == sum) {
            ok = false;
            cout << "NO\n";
            break;
         }
         sum += a[i];
      }
      if (!ok) continue;

      cout << "YES\n";
      for (int i = 0; i < n; i++) {
         cout << a[i] << " \n"[i == n - 1];
      }
   }
   
   return 0;
}
/*

*/