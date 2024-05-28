/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 18:46:19
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
   
   int n = 0, x = 0;
   cin >> n >> x;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];
   unordered_map<int, int> hs;
   for (int i = 0; i < n; i++) {
      hs[a[i]] += 1;
   }
   for (int i = 0; i < n; i++) {
      if (hs.count(a[i] - x)) {
         return cout << "Yes\n", 0;
      }
   }
   cout << "No\n";
   return 0;
}
/*

*/