/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-22 15:40:20
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
      vector<int> a(2 * n, 0);
      vector<int> even, odd;
      for(int i = 0; i < 2 * n; i++) {
         cin >> a[i];
         if (a[i] % 2) {
            odd.push_back(i + 1);
         } else {
            even.push_back(i + 1);
         }
      }
      vector<pair<int, int>> ans;
      for (int i = 0; i + 1 < (int)odd.size(); i += 2) {
         ans.push_back({odd[i], odd[i + 1]});
      }
      for (int i = 0; i + 1 < (int)even.size(); i += 2) {
         ans.push_back({even[i], even[i + 1]});
      }
      for (int i = 0; i < n - 1; i++) {
         cout << ans[i].first << ' ' << ans[i].second << '\n';
      }
   }
   return 0;
}
/*

*/