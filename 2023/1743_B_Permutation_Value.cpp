/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 16:32:31
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
      iota(a.begin(), a.end(), 1);
      reverse(a.begin(), a.end());
      a.pop_back();
      a.pop_back();
      cout << 1 << ' ';
      for (int i = 0; i < (int)a.size(); i++) {
         cout << a[i] << " ";
      }
      cout << 2 << '\n';
   }
   
   return 0;
}
/*

*/