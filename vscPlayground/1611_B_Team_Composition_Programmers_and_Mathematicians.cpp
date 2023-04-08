/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-05 18:13:15
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
      int a = 0, b = 0;
      cin >> a >> b;
      cout << min({(a + b) / 4, a, b}) << '\n';
   }
   
   return 0;
}
/*

*/