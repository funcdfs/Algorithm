/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-03 19:04:19
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
      int n = 0, k = 0;
      cin >> n >> k;
      // insert some number [1, n]
      // so that its subarrays of length k have the same sum
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) cin >> a[i];
      function<bool()> trans = [&a, n, k]() -> bool {
         unordered_set<int> S;
         for (auto& x : a) S.insert(x);
         if ((int)S.size() > k) {
            return false;
         } // 循环节的长度就是 k 了
         a.clear();
         for (auto& x : S) {
            a.push_back(x);
         } // 将不同的数字放入 a 中
         int idx = 0;
         while ((int)a.size() < k) {
            a.push_back(a[idx]);
            idx += 1;
         }
         return true;
      };
      if (trans() == true) {
         cout << n * k << '\n';
         for (int i = 0; i < n * k; i++) {
            cout << a[i % k] << " \n"[i == n * k - 1];
         }
      } else {
         cout << -1 << '\n';
      }
   }
   
   return 0;
}
/*

*/