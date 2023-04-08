/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-03 17:49:13
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
      vector<int64_t> a(3, 0);
      for (int i = 0; i < 3; i++) cin >> a[i];
      sort(a.begin(), a.end());
      int64_t sum = accumulate(a.begin(), a.end(), int64_t(0));
      cout << sum / 2 << '\n';
   }
   
   return 0;
}
/*

*/