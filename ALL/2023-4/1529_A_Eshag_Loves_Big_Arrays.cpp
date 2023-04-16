/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-30 19:23:29
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
      for(int i = 0; i < n; i++) {
         cin >> a[i];
      }
      // delete larger than the silce avg, the most count i can delete
      int minVal = *min_element(a.begin(), a.end());
      int cnt = count(a.begin(), a.end(), minVal);
      cout << n - cnt << '\n';
   }
   
   return 0;
}
/*

*/